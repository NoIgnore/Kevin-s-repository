'''利用os模块编写一个能实现dir -l输出的程序。'''
from datetime import datetime
import os

pwd = os.path.abspath('.')

print('      Size     Last Modified  Name')
print('------------------------------------------------------------')
print(pwd)
for f in os.listdir(pwd):
    fsize = os.path.getsize(f)
    mtime = datetime.fromtimestamp(os.path.getmtime(f)).strftime('%Y-%m-%d %H:%M')
    flag = '/' if os.path.isdir(f) else ''
    print('%10d  %s  %s%s' % (fsize, mtime, f, flag))
'''
      Size     Last Modified  Name
------------------------------------------------------------
      2323  2019-11-03 19:09  airplanegame.py
      1874  2019-11-01 11:28  map和reduce函数完成强制类型转换.py
      2546  2019-10-13 21:53  plane_main.py
      4096  2019-10-16 21:08  python基础笔记html/
       567  2019-10-20 15:00  python递归汉诺塔.py
       784  2019-11-17 10:08  python里的json.py
      2797  2019-11-15 11:17  使用@property.py
      1561  2019-11-16 15:49  使用枚举类.py
       484  2019-11-13 12:50  偏函数进制转换.py
       272  2019-10-29 23:38  写一个将字符串数字转化为int型.py
       654  2019-11-17 00:30  利用os模块编写一个能实现dir -l输出的程序.py
       518  2019-11-13 10:32  利用闭包返回一个计数器函数，每次调用它返回递增整数.py
       148  2019-11-13 10:52  匿名函数改造代码.py
      2706  2019-11-16 17:02  单元测试.py
       686  2019-11-01 14:34  回数判断.py
       612  2019-11-15 10:35  实例属性和类属性.py
      1086  2019-11-17 09:54  序列化.py
       371  2019-11-02 19:21  按照分数或者名字排序.py
        86  2019-11-17 00:07  文件读写.py
       719  2019-11-16 23:40  文档测试.py
       977  2019-11-17 10:21  查找文件名包含指定字符串的文件.py
      2059  2019-10-18 11:14  爬取股票（伪链接）.py
       462  2019-11-01 13:17  生成器求质数.py
      2169  2019-11-13 12:28  装饰器.py
       838  2019-11-14 00:05  访问限制.py
       532  2019-11-16 16:16  错误处理.py
[Finished in 0.1s]
'''