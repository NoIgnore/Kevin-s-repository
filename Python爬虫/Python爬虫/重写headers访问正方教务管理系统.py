import requests
url = ("http://jw.xhsysu.edu.cn/")
try:
    #kv = {'user-agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:69.0) Gecko/20100101 Firefox/69.0'}
    #r = requests.get(url,headers=kv)
    r = requests.get(url)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print (r.text[:1000])
except:
    print("ERROR....")