def fact(n):
    '''
    Calculate 1*2*...*n
    
    >>> fact(1)
    1
    >>> fact(10)
    3628800
    >>> fact(-1)
    Traceback (most recent call last):
          ...
    ValueError
    '''
    if n < 1:
        raise ValueError()
    if n == 1:
        return 1
    return n * fact(n - 1)#这是阶乘Calculate 1*2*...*n

if __name__ == '__main__':
    import doctest
    doctest.testmod()
'''
Python内置的“文档测试”（doctest）模块可以直接
提取注释中的代码并执行测试。
doctest严格按照Python交互式命令行的输入和输出
来判断测试结果是否正确。只有测试异常的时候，可以
用...表示中间一大段烦人的输出。
'''