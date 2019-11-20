import requests
from bs4 import BeautifulSoup
import traceback
import re
def getHTMLText(url):
    try:
        r = requests.get(url,timeout = 30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""
    
def getStockList(lst,stockURL):
    html = getHTMLText(stockURL)
    soup = BeautifulSoup(html,'html.parser')
    a = soup.find_all('a')
    for i in a:
        try:
            href = i.attrs['herf']#这个应该是找到herf的属性吧
            lst.append(re.findall(r"[s][hz]\d{6}",herf)[0])
        except:
            continue
def getStocInfo(lst,stockURL,fpath):
    for stock in lst:
        url = stockURL + stock + ".html"
        html = getHTMLText(url)
        try :
            if html == "":
                continue
            infoDict = {}
            soup = BeautifulSoup(html,'html.parser')
            stockInfo = soup.find('div',attrs={'class':'stock-bets'})#这里用find，只找一个
            name  = stockInfo.find_all(attrs={'class':'bets-name'})[0]
            infoDict.update({'stock name':name.text.split()[0]})#这个是第一行起个stockname的标题，然后换行输出键值
            keyList = stockInfo.find_all('dt')
            valueList = stockInfo.find_all('dd')
            for i in range(len(keyList)):
                key = keyList[i].text
                val = valueList[i].text
                infoDict[key] = val 
            with open(fpath,'a',encoding = 'utf-8') as f:#若不存在，则创建
                f.write(str(infoDict) + '\n')
        except:
            traceback.print_exc()
            continue
#getStockList应该是获取股票代码，然后拿着股票代码查询另一个网站的对应的股票信息
def main():
    stock_list_url = 'http://www.baidu.com'
    stock_info_url = 'http://xxxxxxx'
    output_file = 'D://BaiduStockInfo.txt'
    slist = []
    getStockList(slist,stock_list_url)
    getStocInfo(slist,stock_info_url,output_file)
main()