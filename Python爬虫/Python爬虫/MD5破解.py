import hashlib
#knownmd5 = '892f'
dict = 'abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def md5(text):
    return hashlib.md5(str(text).encode('utf-8')).hexdigest()
while True:
    knownmd5 = input("请输入所求的目标:   ")
    Hhj = False
    for i in dict:
        for j in dict:
            for k in dict:
                for l in dict:
                    x = i + j + k +l
                    b=x
                    codemd5=md5(b)
                    if codemd5[:4] == knownmd5:
                        Hhj = True
                        print(x)
                    if Hhj == True:
                        break
                if Hhj == True:
                    break
            if Hhj == True:
                break
        if Hhj == True:
            break

#exit()也可以退出程序

