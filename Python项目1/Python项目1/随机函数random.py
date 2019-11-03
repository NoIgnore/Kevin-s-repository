import random
while 1>0:
    x = random.randint(0,9)
    print (x)
    print ("")
    a = input("输出的是0~9的随机数，请按其它键继续,F/f键退出.........")
    if a == "F" or a == "f":
        break
    else :
        continue