import requests
import re
headers = {
    "User-Agent":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36"
}
content = requests.get('https://book.douban.com/',headers=headers)
results = re.findall('<li.*?"cover".*?href="(.*?)" title="(.*?)">.*?author">(.*?)</div>.*?year">(.*?)</span>', content.text, re.S)

def generator_3():
	for n in range(101):
		yield n
a = generator_3()

next(a)

print(results)
print("")
for result in results:
    url,name,author,date = result
    author = re.sub('\s','',author)#\s是指空白，包括空格、换行、tab缩进等所有的空白，而\S刚好相反
    #\s本来只能匹配一次，但在re.sub里面一个个空格匹配一次就是匹配好全部了
    date = re.sub('\s','',date)
    print(next(a),url,name,author,date)


'''
import re
result=re.match("嫦娥\s*号","嫦娥   号")
a=result.group()
print(a)
'''
'''
嫦娥   号
[Finished in 0.1s]
'''

'''
[('https://book.douban.com/subject/33440237/?icn=index-latestbook-subject', '强风吹拂', '\n                [日] 三浦紫苑\n              ', '\n                    2019-10\n                  '), 
('https://book.douban.com/subject/27156274/?icn=index-latestbook-subject', '德国人', '\n                [德]埃米尔·路德维希\n              ', '\n                    2019-10\n                  ')]
'''
