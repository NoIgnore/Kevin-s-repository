from functools import reduce
def normalize(name):
    return name[0].upper() + name[1:].lower()
L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print("")
print(L2)
"""
1.题目测试要求:  利用map()函数，把用户输入的不规范的英文名字，变为首字母大写，其他小写的规范名字。
L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)
"""
###
###
print("")

def prod(L):
    return reduce(lambda x,y : x*y , L)
print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))
'''
2.题目测试要求:  写一个prod()函数，可以接受一个list并利用reduce()求积：
print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))
if prod([3, 5, 7, 9]) == 945:
    #print('测试成功!')
else:
    #print('测试失败!')
'''
print("")

###
###
'''
3.题目要求：利用map和reduce编写一个str2float函数，把字符串'123.456'转换成浮点数123.456：
print('str2float(\'123.456\') =', str2float('123.456'))
if abs(str2float('123.456') - 123.456) < 0.00001:
    print('测试成功!')
else:
    print('测试失败!')
'''
def str2float(s):
    dictionary1 = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}
    n=0
    while s[n]!='.':         #计算小数点在第几位
        n=n+1
    s1=s[:n]                  #小数点前切片
    s2=s[n+1:]              #小数点后切片
    def f1(x,y):
        return 10*x+y
    def char2num(s):
        return dictionary1[s]
#比如'1234.567'，对于b数来说，567/(100^3)=0.567
    a=reduce(f1,map(char2num,s1))                                
    b=reduce(f1,map(char2num,s2))/(10**(len(s2)))
    return a+b
print('字符串 str2float(\'123.456\') =', str2float('123.456'))
print("")
'''
str45 = '21342.544'
asdf,sdfd = str45.split('.')
print (asdf,sdfd)
输出结果为 21342 544
'''