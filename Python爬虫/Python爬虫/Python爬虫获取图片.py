import os
import requests
url = "https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1571044852125&di=ed62fa2433c04f822177ae0569c0cdad&imgtype=0&src=http%3A%2F%2Fimgk.zol.com.cn%2Flolbbs%2F4815%2Fa4814279_s.jpg"
root = "D://。。。。。。//"
path =  root + "lol.jpg"
try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r = requests.get(url)
        with open(path,'wb') as f:
            f.write(r.content)
            f.close()
            print ("Success...")
    else:
        print("File exists...")
except:
    print ("Failed to get..")
