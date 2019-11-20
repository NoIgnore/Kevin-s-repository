import functools
#把二进制转化成十进制
'''类似于
def int2(x, base=2):
    return int(x, base)
'''
int2 = functools.partial(int, base=2)

print('1000000 =', int2('1000000'))
print('1010101 =', int2('1010101'))
'''
1000000 = 64
1010101 = 85
[Finished in 0.1s]
当函数的参数个数太多，需要简化时，使用functools.partial可以创建一个新的函数，这个新函数可以固定住原函数的部分参数，从而在调用时更简单。
'''