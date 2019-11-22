# 使用同步方式编写异步功能,结合@asyncio.coroutine实现协程
import time
import asyncio
@asyncio.coroutine # 标志协程的装饰器
def taskIO_1():
    print('开始运行IO任务1...')
    yield from asyncio.sleep(2)  # 假设该任务耗时2s
    print('IO任务1已完成，耗时2s')
    return taskIO_1.__name__
@asyncio.coroutine # 标志协程的装饰器
def taskIO_2():
    print('开始运行IO任务2...')
    yield from asyncio.sleep(3)  # 假设该任务耗时3s
    print('IO任务2已完成，耗时3s')
    return taskIO_2.__name__
@asyncio.coroutine # 标志协程的装饰器
def main(): # 调用方
    tasks = [taskIO_1(), taskIO_2()]  # 把所有任务添加到task中
    done,pending = yield from asyncio.wait(tasks) # 子生成器
    for r in done: # done和pending都是一个任务，所以返回结果需要逐个调用result()
        print('协程无序返回值：'+r.result())

if __name__ == '__main__':
    start = time.time()
    loop = asyncio.get_event_loop() # 创建一个事件循环对象loop
    try:
        loop.run_until_complete(main()) # 完成事件循环，直到最后一个任务结束
    finally:
        loop.close() # 结束事件循环
    print('所有IO任务总耗时%.5f秒' % float(time.time()-start))
'''
【使用方法】： @asyncio.coroutine装饰器是协程函数的标志，我们需要在每一个任务函数前加这个装饰器，并在函数中使用yield from。在同步IO任务的代码中使用的time.sleep(2)来假设任务执行了2秒。但在协程中yield from后面必须是子生成器函数，而time.sleep()并不是生成器，所以这里需要使用内置模块提供的生成器函数asyncio.sleep()。
【功能】：通过使用协程，极大增加了多任务执行效率，最后消耗的时间是任务队列中耗时最多的时间。上述例子中的总耗时3秒就是taskIO_2()的耗时时间。
【执行过程】：

    上面代码先通过get_event_loop()获取了一个标准事件循环loop(因为是一个，所以协程是单线程)
    然后，我们通过run_until_complete(main())来运行协程(此处把调用方协程main()作为参数，调用方负责调用其他委托生成器)，run_until_complete的特点就像该函数的名字，直到循环事件的所有事件都处理完才能完整结束。
    进入调用方协程，我们把多个任务[taskIO_1()和taskIO_2()]放到一个task列表中，可理解为打包任务。
    现在，我们使用asyncio.wait(tasks)来获取一个awaitable objects即可等待对象的集合(此处的aws是协程的列表)，并发运行传入的aws，同时通过yield from返回一个包含(done, pending)的元组，done表示已完成的任务列表，pending表示未完成的任务列表；如果使用asyncio.as_completed(tasks)则会按完成顺序生成协程的迭代器(常用于for循环中)，因此当你用它迭代时，会尽快得到每个可用的结果。【此外，当轮询到某个事件时(如taskIO_1())，直到遇到该任务中的yield from中断，开始处理下一个事件(如taskIO_2()))，当yield from后面的子生成器完成任务时，该事件才再次被唤醒】
    因为done里面有我们需要的返回结果，但它目前还是个任务列表，所以要取出返回的结果值，我们遍历它并逐个调用result()取出结果即可。(注：对于asyncio.wait()和asyncio.as_completed()返回的结果均是先完成的任务结果排在前面，所以此时打印出的结果不一定和原始顺序相同，但使用gather()的话可以得到原始顺序的结果集，两者更详细的案例说明见此)
    最后我们通过loop.close()关闭事件循环。

协程的完整实现是靠①事件循环＋②协程。


异步爬虫不同于多进程爬虫，它使用单线程(即仅创建一个事件循环，然后把所有任务添加到事件循环中)就能并发处理多任务。在轮询到某个任务后，当遇到耗时操作(如请求URL)时，挂起该任务并进行下一个任务，当之前被挂起的任务更新了状态(如获得了网页响应)，则被唤醒，程序继续从上次挂起的地方运行下去。极大的减少了中间不必要的等待时间。
'''