'''添加headers：
import requests
headers = {
    "User-Agent":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36"
}
response =requests.get("https://www.zhihu.com",headers=headers)

print(response.text[:100])'''
'''import requests

data = {
    "name":"zhaofan",
    "age":23
}
response = requests.post("http://httpbin.org/post",data=data)
print(response.text[:100])

-----------------------------------------------------------------------------
import requests
#基本post请求：
response = requests.get("http://www.baidu.com")
print(type(response.status_code),response.status_code)
print(type(response.headers),response.headers)
print(type(response.cookies),response.cookies)
print(type(response.url),response.url)
print(type(response.history),response.history)

-----------------------------------------------------------------------------
import requests
#响应:
response= requests.get("http://www.baidu.com")
if response.status_code == requests.codes.okay:
	print("访问成功")
-----------------------------------------------------------------------------
#文件上传:

#实现方法和其他参数类似，也是构造一个字典然后通过files参数传递

import requests
files= {"files":open("git.jpeg","rb")}
response = requests.post("http://httpbin.org/post",files=files)
print(response.text)

-----------------------------------------------------------------------------
获取cookie
import requests

response = requests.get("http://www.baidu.com")
print(response.cookies)

for key,value in response.cookies.items():
    print(key+"="+value)
-----------------------------------------------------------------------------
import requests
s = requests.Session()
s.get("http://httpbin.org/cookies/set/number/123456")
response = s.get("http://httpbin.org/cookies")
print(response.text)

print("")
from requests.packages import urllib3
urllib3.disable_warnings()
response = requests.get("https://www.12306.cn",verify=False)
print(response.status_code)
'''
import requests
import re
headers = {
    "User-Agent":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36"
}
content = requests.get('https://book.douban.com/',headers=headers)
#pattern = re.compile('<li.*?cover.*?href="(.*?)".*?title="(.*?)".*?more-meta.*?author">(.*?)</span>.*?year">(.*?)</span>.*?</li>', re.S)
#pattern = re.compile('<li.*?"cover".*?href="(.*?)" title="(.*?)">.*?author">(.*?).*?year">(.*?)</span>',re.S)
#results = re.findall(pattern, content)
results = re.findall('<li.*?"cover".*?href="(.*?)" title="(.*?)">.*?author">(.*?)</div>.*?year">(.*?)</span>', content.text, re.S)
#四个(.*?)括号表示要匹配的对象
#.表示匹配除换行符\n外的任意字符，*表示零次或者多次，？表示匹配前面的子表达式零次或者一次
'''
比如：   <H1>Chapter 1 - 介绍正则表达式</H1>

使用/<.*>/匹配的结果为：H1>Chapter 1 - 介绍正则表达式</H1

使用/<.*?>/匹配结果为：H1
'''
'''
这个是re.S的使用
import re
a = 'sdfkhellolsdlfsdfiooefo:
877898989worldafdsf'
b = re.findall('hello(.*?)world',a)
c = re.findall('hello(.*?)world',a,re.S)
print ('b is ' , b)
print ('c is ' , c)
 
 
# 输出结果：
# b is  []
# #c is  ['lsdlfsdfiooefo:\n877898989']
'''

def generator_3():
	for n in range(101):
		yield n
a = generator_3()

next(a)

print(results)#这个有点乱，还是别打印了
print("")
for result in results:
    url,name,author,date = result
    author = re.sub('\s','',author)#\s表示匹配任何空白字符，包括空格、制表符、换页符等等。等价于 [ \f\n\r\t\v]。注意 Unicode 正则表达式会匹配全角空格符。
    date = re.sub('\s','',date)#' '中间的空格参数表示要替代\s匹配的字符，date表示范围内容
    print(next(a),url,name,author,date)
'''
1 https://book.douban.com/subject/33474599/?icn=index-latestbook-subject 我们的时代 [美]欧内斯特·海明威 2019-12
2 https://book.douban.com/subject/34836249/?icn=index-latestbook-subject 没药花园 何袜皮 2019-10
3 https://book.douban.com/subject/34856160/?icn=index-latestbook-subject 最后的巨人 [法]法兰斯瓦·普拉斯 2019-11
4 https://book.douban.com/subject/34857213/?icn=index-latestbook-subject 亲密陷阱 [比利时]埃丝特•佩瑞尔（EstherPerel) 2019-10
5 https://book.douban.com/subject/33455795/?icn=index-latestbook-subject 落失男孩 [美]托马斯·沃尔夫 2019-12
6 https://book.douban.com/subject/34839989/?icn=index-latestbook-subject 饭局的起源 [英]马丁•琼斯 2019-10
7 https://book.douban.com/subject/33657510/?icn=index-latestbook-subject 幻化 [日]梅崎春生 2019-10
8 https://book.douban.com/subject/34808250/?icn=index-latestbook-subject 被弃的意象 [英]C·S·路易斯 2019-11
9 https://book.douban.com/subject/34840585/?icn=index-latestbook-subject 她的名字是 [韩]赵南柱 2019-11
10 https://book.douban.com/subject/34851866/?icn=index-latestbook-subject 中国造园艺术 曹汛 2019-11-1
11 https://book.douban.com/subject/27188666/?icn=index-latestbook-subject 基列家书 [美]玛丽莲·罗宾逊 2019-10
12 https://book.douban.com/subject/34398024/?icn=index-latestbook-subject 诗意的宇宙 [奥]斯特凡·克莱因 2019-10
13 https://book.douban.com/subject/34808267/?icn=index-latestbook-subject 萨拉戈萨手稿 [波兰]扬·波托茨基&nbsp;/&nbsp;JeanPotocki 2019-11
14 https://book.douban.com/subject/33438831/?icn=index-latestbook-subject 梦的宇宙志 [日]涩泽龙彦 2019-11
15 https://book.douban.com/subject/34859246/?icn=index-latestbook-subject 黑色天鹅 （日）鲇川哲也 2019-11
16 https://book.douban.com/subject/30317910/?icn=index-latestbook-subject 教父电影全剧本（全彩插图评注版） [美]珍妮·M·琼斯 2019-12
17 https://book.douban.com/subject/34431940/?icn=index-latestbook-subject 双胞胎 [日]藤崎彩织 2019-10-1
18 https://book.douban.com/subject/34842793/?icn=index-latestbook-subject 薄世宁医学通识讲义 薄世宁 2019-10-11
19 https://book.douban.com/subject/33455809/?icn=index-latestbook-subject 老爸的笑声 [菲律宾]卡洛斯·布洛桑 2019-12
20 https://book.douban.com/subject/34821222/?icn=index-latestbook-subject 无尽之河：平克·弗洛伊德传 马克·布莱克 2019-11
21 https://book.douban.com/subject/34841937/?icn=index-latestbook-subject 群星 七月 2019-11
22 https://book.douban.com/subject/34825128/?icn=index-latestbook-subject 维多利亚女王 [英]露西·沃斯利 2019-10-1
23 https://book.douban.com/subject/34863774/?icn=index-latestbook-subject 遗失的灵魂 [波兰]奥尔加·托卡尔丘克&nbsp;/&nbsp;[波兰]乔安娜孔塞霍绘 2019-11
24 https://book.douban.com/subject/34848926/?icn=index-latestbook-subject 八千里路云和月 白先勇 2019-11-1
25 https://book.douban.com/subject/34672176/?icn=index-latestbook-subject 呼吸 [美]特德·姜 2019-11
26 https://book.douban.com/subject/34788663/?icn=index-latestbook-subject 传统十论 秦晖 2019-10
27 https://book.douban.com/subject/34822443/?icn=index-latestbook-subject 潘神的迷宫 [墨西哥]吉尔莫·德尔·托罗&nbsp;/&nbsp;[德]柯奈莉亚·冯克 2019-11
28 https://book.douban.com/subject/34781358/?icn=index-latestbook-subject 史记的读法 杨照 2019-11
29 https://book.douban.com/subject/34821347/?icn=index-latestbook-subject 老虎与不夜城 陈志炜 2019-12
30 https://book.douban.com/subject/34833897/?icn=index-latestbook-subject 征服自然 [美]大卫·布莱克本 2019-10
31 https://book.douban.com/subject/33440237/?icn=index-latestbook-subject 强风吹拂 [日]三浦紫苑 2019-10
32 https://book.douban.com/subject/34872361/?icn=index-latestbook-subject 文案的基本修养 东东枪 2019-10
33 https://book.douban.com/subject/34670767/?icn=index-latestbook-subject 出售幻觉 [智利]迭戈·穆尼奥斯·瓦伦苏埃拉 2019-11
34 https://book.douban.com/subject/34463603/?icn=index-latestbook-subject 太阳与少女 [日]森见登美彦 2019-10
35 https://book.douban.com/subject/34860553/?icn=index-latestbook-subject 我们盗走星座的理由 （日）北山猛邦 2019-10
36 https://book.douban.com/subject/27156274/?icn=index-latestbook-subject 德国人 [德]埃米尔·路德维希 2019-10
37 https://book.douban.com/subject/34648287/?icn=index-latestbook-subject 幻兽动物园 [英]利奥·鲁伊克比 2019-11
38 https://book.douban.com/subject/34838322/?icn=index-latestbook-subject 空的空间 [英]彼得·布鲁克 2019-11
39 https://book.douban.com/subject/34873145/?icn=index-latestbook-subject 生肉 [英]奥利维娅·莱恩 2019-10
40 https://book.douban.com/subject/34840198/?icn=index-latestbook-subject 人类的终极问题 袁越 2019-10
[Finished in 15.5s]
'''

'''
这个是re.S的使用
import re
a = """sdfkhellolsdlfsdfiooefo:
877898989worldafdsf"""
b = re.findall('hello(.*?)world',a)
c = re.findall('hello(.*?)world',a,re.S)
print ('b is ' , b)
print ('c is ' , c)
 
 
# 输出结果：
# b is  []
# #c is  ['lsdlfsdfiooefo:\n877898989']'''