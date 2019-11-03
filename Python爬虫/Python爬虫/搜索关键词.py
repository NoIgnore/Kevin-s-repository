import requests
url = "http://baidu.com/s"
try:
    kv = {'wd':'python'}
    r = requests.get(url,params=kv)
    print(r.request.url)#这个reqest没有s！！！！！
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print (len(r.text))
    print (r.text[0:20])
except:
    print("ERROR.....")
