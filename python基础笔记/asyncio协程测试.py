'''asyncio的编程模型就是一个消息循环。我们从asyncio模块中直接获取一个EventLoop的引用，然后把需要执行的协程扔到EventLoop中执行，就实现了异步IO。

用asyncio实现Hello world代码如下：'''
'''import asyncio

@asyncio.coroutine
def hello():
    print("Hello world!")
    # 异步调用asyncio.sleep(1):
    r = yield from asyncio.sleep(1)
    print("Hello again!")

# 获取EventLoop:
loop = asyncio.get_event_loop()
# 执行coroutine
loop.run_until_complete(hello())
loop.close()'''

import asyncio

@asyncio.coroutine
def wget(host):
    print('开始处理 %s...' % host)
    connect = asyncio.open_connection(host, 80)
    print('%s开始连接...' % host)

    reader, writer = yield from connect
    print ('%s 连接成功' % host)#每个网站连接时间不同，先连接的先执行
    header = 'GET / HTTP/1.0\r\nHost: %s\r\n\r\n' % host
    writer.write(header.encode('utf-8'))
    yield from writer.drain()
    print('%s is ok' % host)
    while True:
        line = yield from reader.readline()
        if line == b'\r\n':
            break
        print('%s header > %s' % (host, line.decode('utf-8').rstrip()))
    # Ignore the body, close the socket
    writer.close()

loop = asyncio.get_event_loop()
tasks = [wget(host) for host in ['www.sina.com.cn', 'www.sohu.com', 'www.163.com']]
loop.run_until_complete(asyncio.wait(tasks))
loop.close()
'''
开始处理 www.163.com...
www.163.com开始连接...
开始处理 www.sohu.com...
www.sohu.com开始连接...
开始处理 www.sina.com.cn...
www.sina.com.cn开始连接...
www.sohu.com 连接成功
www.sohu.com is ok
www.sina.com.cn 连接成功
www.sina.com.cn is ok
www.163.com 连接成功
www.163.com is ok
www.sohu.com header > HTTP/1.1 200 OK
www.sohu.com header > Content-Type: text/html;charset=UTF-8
www.sohu.com header > Connection: close
www.sohu.com header > Server: nginx
www.sohu.com header > Date: Fri, 22 Nov 2019 03:27:31 GMT
www.sohu.com header > Cache-Control: max-age=60
www.sohu.com header > X-From-Sohu: X-SRC-Cached
www.sohu.com header > Content-Encoding: gzip
www.sohu.com header > FSS-Cache: HIT from 3159614.4339272.4479056
www.sohu.com header > FSS-Proxy: Powered by 3487299.4994637.4806746
www.sina.com.cn header > HTTP/1.1 302 Moved Temporarily
www.sina.com.cn header > Server: nginx
www.sina.com.cn header > Date: Fri, 22 Nov 2019 03:27:52 GMT
www.sina.com.cn header > Content-Type: text/html
www.sina.com.cn header > Content-Length: 138
www.sina.com.cn header > Connection: close
www.sina.com.cn header > Location: https://www.sina.com.cn/
www.sina.com.cn header > X-Via-CDN: f=edge,s=cern.beijing.ha2ts4.35.nb.sinaedge.com,c=2001:da8:6000:302::2:7d3c;
www.sina.com.cn header > X-Via-Edge: 15743932724410000020041002600095d3ebf
www.163.com header > HTTP/1.1 200 OK
www.163.com header > Date: Fri, 22 Nov 2019 03:27:52 GMT
www.163.com header > Content-Type: text/html; charset=GBK
www.163.com header > Connection: close
www.163.com header > Expires: Fri, 22 Nov 2019 03:29:01 GMT
www.163.com header > Server: nginx
www.163.com header > Cache-Control: no-cache,no-store,private
www.163.com header > Age: 10
www.163.com header > Vary: Accept-Encoding
www.163.com header > X-Ser: BC51_dx-lt-yd-shandong-jinan-5-cache-6, BC53_dx-lt-yd-shandong-jinan-5-cache-6, BC30_yd-guangdong-guangzhou-3-cache-2
www.163.com header > cdn-user-ip: 2001:da8:6000:302::2:7d3c
www.163.com header > cdn-ip: 2409:8754:c10:2001::1:19
www.163.com header > X-Cache-Remote: HIT
www.163.com header > cdn-source: baishan
[Finished in 0.4s]
'''