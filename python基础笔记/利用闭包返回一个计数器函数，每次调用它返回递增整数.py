#利用闭包返回一个计数器函数，每次调用它返回递增整数：
def createCounter():
    n=0
    def counter():
        nonlocal n#将 n 声明成非局部变量
        n=n+1
        return n 
    return counter
    # 测试:
counterA = createCounter()
print(counterA(), counterA(), counterA(), counterA(), counterA()) # 1 2 3 4 5
counterB = createCounter()
if [counterB(), counterB(), counterB(), counterB()] == [1, 2, 3, 4]:
    print('测试通过!')
else:
    print('测试失败!')