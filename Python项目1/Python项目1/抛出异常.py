def input_password():
    pw = input("please input your password:  ")
    if len(pw) >= 8:
        return pw
    print ("主动抛出异常")
    ex = Exception("密码不够长")
    raise ex
try:
    print(input_password())
except Exception as result:
    print("- -" * 10)
    print(result)
'''
please input your password:  2
主动抛出异常
- -- -- -- -- -- -- -- -- -- -
密码不够长
请按任意键继续. . .
'''

"""
please input your password:  123456789
123456789
请按任意键继续. . .
"""