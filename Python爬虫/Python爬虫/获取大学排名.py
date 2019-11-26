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
            ulist.append([tds[0].string,tds[1].string,tds[3].string])#参考网页源代码string,tds[2]对应的是北京
'''
对应的网页部分源代码如下
<tbody class="hidden_zhpm" style="text-align: center;">
    <tr class="alt"><td>1</td><td><div align="left">清华大学</div></td><td>北京</td><td>95.3</td>'''

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
'''
   rank         school_name        tatal score
    1       　　　清华大学　　　     95.3   
    2       　　　北京大学　　　     78.6   
    3       　　　浙江大学　　　     73.9   
    4       　　上海交通大学　　     73.1   
    5       　　　复旦大学　　　     66.0   
    6       　中国科学技术大学　     61.9   
    7       　　　南京大学　　　     59.8   
    8       　　华中科技大学　　     59.1   
    9       　　　中山大学　　　     58.6   
    10      　哈尔滨工业大学　　     57.4   
    11      　　　同济大学　　　     56.4   
    12      　　　武汉大学　　　     55.5   
    13      　　　东南大学　　　     55.3   
    14      　　西安交通大学　　     54.2   
    15      　北京航空航天大学　     54.0   
    16      　　　南开大学　　　     53.9   
    17      　　　四川大学　　　     53.3   
    18      　　　天津大学　　　     52.4   
    19      　　华南理工大学　　     51.8   
    20      　　北京师范大学　　     51.7   
Suc20
[Finished in 2.7s]'''




#http://www.zuihaodaxue.com/zuihaodaxuepaiming2018.html