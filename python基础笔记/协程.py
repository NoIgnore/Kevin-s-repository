def consumer():
    r = ''
    while True:
        n = yield r
        if not n:
            return
        print('[CONSUMER] Consuming %s...' % n)
        r = '200 OK'

def produce(c):
    c.send(None)
    n = 0
    while n < 5:
        n = n + 1
        print('[PRODUCER] Producing %s...' % n)
        r = c.send(n)
        print('[PRODUCER] Consumer return: %s' % r)
    c.close()

c = consumer()
produce(c)
'''执行结果：

[PRODUCER] Producing 1...
[CONSUMER] Consuming 1...
[PRODUCER] Consumer return: 200 OK
[PRODUCER] Producing 2...
[CONSUMER] Consuming 2...
[PRODUCER] Consumer return: 200 OK
[PRODUCER] Producing 3...
[CONSUMER] Consuming 3...
[PRODUCER] Consumer return: 200 OK
[PRODUCER] Producing 4...
[CONSUMER] Consuming 4...
[PRODUCER] Consumer return: 200 OK
[PRODUCER] Producing 5...
[CONSUMER] Consuming 5...
[PRODUCER] Consumer return: 200 OK
'''


'''注意到consumer函数是一个generator，把一个consumer传入produce后：

    首先调用c.send(None)启动生成器；

    然后，一旦生产了东西，通过c.send(n)切换到consumer执行；

    consumer通过yield拿到消息，处理，又通过yield把结果传回；

    produce拿到consumer处理的结果，继续生产下一条消息；

    produce决定不生产了，通过c.close()关闭consumer，整个过程结束。

整个流程无锁，由一个线程执行，produce和consumer协作完成任务，所以称为“协程”，而非线程的抢占式多任务。

最后套用Donald Knuth的一句话总结协程的特点：

“子程序就是协程的一种特例。”'''
'''
1、例子中的c.send(None)，其功能类似于next(c)，比如：

>>> def num():
        yield 1
        yield 2
    
>>> c = num()
>>> c.send(None)
1
>>> c.send(None)
2
>>> c.send(None)
Traceback (most recent call last):
  File "<pyshell#9>", line 1, in <module>
    c.send(None)
StopIteration
>>> 

2、n = yield r，这里是一条语句，但要理解两个知识点，赋值语句先计算= 右边，由于右边是 yield 语句，所以yield语句执行完以后，进入暂停，而赋值语句在下一次启动生成器的时候首先被执行；

3、send 在接受None参数的情况下，等同于next(generator)的功能，但send同时也可接收其他参数，比如例子中的c.send(n)，要理解这种用法，先看一个例子：

>>> def num():
        a = yield 1
        while True:
            a = yield a
       
>>> c = num()
>>> c.send(None)
1
>>> c.send(5)
5
>>> c.send(100)
100

在上面的例子中，首先使用 c.send(None)，返回生成器的第一个值，a = yield 1 ，也就是1（但此时，并未执行赋值语句），

接着我们使用了c.send(5)，再次启动生成器，并同时传入了一个参数5，再次启动生成的时候，从上次yield语句断掉的地方开始执行，即 a 的赋值语句，由于我们传入了一个参数5，所以a被赋值为5，接着程序进入whlie循环，当程序执行到 a = yield a，同理，先返回生成器的值 5，下次启动生成器的时候，再执行赋值语句，以此类推...

所以c.send(n)的用法就是老师上文中所说的 ，" Python的yield不但可以返回一个值，它还可以接收调用者发出的参数。"

但注意，在一个生成器函数未启动之前，是不能传递值进去。也就是说在使用c.send(n)之前，必须先使用c.send(None)或者next(c)来返回生成器的第一个值。
最后我们来看上文中的例子，梳理下执行过程：

def consumer():
    r = ''
    while True:
        n = yield r
        if not n:
            return
        print('[CONSUMER] Consuming %s...' % n)
        r = '200 OK'

def produce(c):
    c.send(None)
    n = 0
    while n < 5:
        n = n + 1
        print('[PRODUCER] Producing %s...' % n)
        r = c.send(n)
        print('[PRODUCER] Consumer return: %s' % r)
    c.close()

c = consumer()
produce(c)

第一步：执行 c.send(None)，启动生成器返回第一个值，n = yield r，此时 r 为空，n 还未赋值，然后生成器暂停，等待下一次启动。

第二步：生成器返回空值后进入暂停，produce(c) 接着往下运行，进入While循环，此时 n 为1，所以打印：

[PRODUCER] Producing 1...

第三步：produce(c) 往下运行到 r = c.send(1)，再次启动生成器，并传入了参数1，而生成器从上次n的赋值语句开始执行，n 被赋值为1，n存在，if 语句不执行，然后打印：

[CONSUMER] Consuming 1...

接着r被赋值为'200 OK'，然后又进入循环，执行n = yield r，返回生成器的第二个值，'200 OK'，然后生成器进入暂停，等待下一次启动。

第四步：生成器返回'200 OK'进入暂停后，produce(c)往下运行，进入r的赋值语句，r被赋值为'200 OK'，接着往下运行，打印：

[PRODUCER] Consumer return: 200 OK

以此类推...

当n为5跳出循环后，使用c.close() 结束生成器的生命周期，然后程序运行结束。'''