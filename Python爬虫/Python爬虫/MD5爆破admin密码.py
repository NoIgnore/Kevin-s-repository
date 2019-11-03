import hashlib
knownmd5 = '09e'
dict = 'abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def md5(text):
    return hashlib.md5(str(text).encode('utf-8')).hexdigest()
for i in dict:
    for j in dict:
        for k in dict:
            for l in dict:
                x = i + j + k +l
                #b=x
                codemd5=md5(x)
                if codemd5[:3] == knownmd5:
                    print(x)
                    exit()



#quit()也可以退出程序
