import time,functools
def metric(name):
    @functools.wraps(name)
    def wrap(*args,**kw):
        print('now time:',time.ctime())
        print('%s executed in %s ms' % (name.__name__, 10.26))
        return name(*args,**kw)
    return wrap

@metric
def fast(x, y):
    time.sleep(0.0012)
    return x + y;

@metric
def slow(x, y, z):
    time.sleep(0.1234)
    return x * y * z;

f = fast(11, 22)
s = slow(11, 22, 33)
print (f,s)
if f != 33:
    print('f测试失败!')
elif s != 7986:
    print('s测试失败!')

print("")
#请编写一个decorator，能在函数调用的前后打印出'begin call'和'end call'的日志。
def call(func):
    @functools.wraps(func)
    def wrapper(*args,**kw):
        print('begin call')
        func(*args,**kw)
        print('end call')
    return wrapper
'''再思考一下能否写出一个@log的decorator，使它既支持：

@log
def f():
    pass

又支持：

@log('execute')
def f():
    pass
'''
#第一种编写log的方法：
def log(funcortext):
    def dec1(func):#传入文本
        def wrapper(*args,**kw):
            print("传入的是文本:"+funcortext,func.__name__)
            func(*args, **kw)
        return wrapper
    def dec2(*args,**kw):#传入函数
        print("传入的是函数:"+funcortext.__name__)
        funcortext(*args, **kw)
    dec=dec1 if isinstance(funcortext, str) else dec2
    return dec

'''
第二种编写log的方法：
def log(textorfunc):
    if isinstance(textorfunc,str):
        text = textorfunc
        def decorator(func):
            @functools.wraps(func)
            def wrapper(*args, **kw):
                print('%s %s():' % (text, func.__name__))
                return func(*args, **kw)
            return wrapper
        return decorator
    else:
        func = textorfunc
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print('named:  %s()' % func.__name__)
            return func(*args, **kw)
        return wrapper
'''
@log
def now1():
    print(time.ctime())
now1()

@log('execute')
def now2():
    print(time.ctime())
now2()