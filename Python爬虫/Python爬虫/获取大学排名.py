import requests
from bs4 import BeautifulSoup
import bs4

def gettext(url):
    try:
        r = requests.get(url,timeout=10)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""
    
def filltext(ulist,html):
    soup = BeautifulSoup(html,"html.parser")
    for tr in soup.find('tbody').children:
        if isinstance(tr,bs4.element.Tag):
            tds = tr('td')
            ulist.append([tds[0].string,tds[1].string,tds[3].string])



def printtext(ulist,num):
    tplt = "{0:^10}\t{1:{3}^10}\t{2:^10}"
    print (tplt.format("rank","    school_name","       tatal score",chr(12288)))
    for i in range(num):
        u = ulist[i]
        print (tplt.format(u[0],u[1],u[2],chr(12288)))

    print ("Suc" + str(num))

def main():
    unifo = []
    url = 'http://www.zuihaodaxue.com/zuihaodaxuepaiming2018.html'
    html = gettext(url)
    filltext(unifo,html)
    printtext(unifo,20)#打印前20所
main()






#http://www.zuihaodaxue.com/zuihaodaxuepaiming2018.html