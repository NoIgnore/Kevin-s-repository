import requests
import re
def getHTMLText(url):
    try:
        headers={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:69.0) Gecko/20100101 Firefox/69.0",
         "Cookies":"_uab_collina=156844585879316518416028;_umdata=G90392B84749395B5FC7B49388A2D315563D35A"}
        r=requests.get(url,timeout=30,headers=headers)
        r.raise_for_status()#如果状态不是200，引发HTTPError异常
        r.encoding=r.apparent_encoding
        #print(r.text[:1000])
        return r.text
    except:
        return ""
def parsePage(ilt,html):
    try:
        plt=re.findall(r'"view_price":"[\d.]*"',html)
        tlt=re.findall(r'"raw_title":".*?"',html)
        for i in range(len(plt)):
            price=eval(plt[i].split(':')[1])
            title=eval(tlt[i].split(':')[1])
            ilt.append([price,title])
    except:
        print("")

def printGoodlist(ilt):
    tplt="{:4}\t{:8}\t{:16}"
    print(tplt.format("序号","价格","商品名称"))
    count=0
    for g in ilt:
        count=count+1
        print(tplt.format(count,g[0],g[1]))

def main():
    goods='书包'
    depth = 2
    start_url = 'https://s.taobao.com/search?q=' + goods
    infoList = []
    for i in range(depth):
        try:
            url = start_url + '&s=' + str(44*i)
            html = getHTMLText(url)
            parsePage(infoList,html)
        except:
            continue
    printGoodlist(infoList)

main()
#九月份只能看到表头看不见内容了，虽然伪造了cookie登录