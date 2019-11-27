import re
# 01：“.”匹配任意1个字符
result=re.match(".....","baaop")
a=result.group()
print(a)
#结果：baaop
 
# 02:“[]”匹配[]中列举的字符
# 字符串第一个字符只要存在于[]中就能成功匹配，
# [a-zA-Z0-9_]表示可以匹配"a-z","A-Z","0-9"和"_"区间内的所有元素
result=re.match("[Aa]","Aaaaaaabbba")
a=result.group()
print(a)
#结果：A
 
#03:"\d"匹配数字，即0-9
result=re.match("嫦娥\d号","嫦娥9号")
a=result.group()
print(a)
#结果：嫦娥9号
 
#04：“\D”匹配非数字，即不是数字
result=re.match("嫦娥\D号","嫦娥a号")
a=result.group()
print(a)
#结果：嫦娥a号
 
# 05：“\s”匹配空白，即 空格，tab键
result=re.match("嫦娥\s号","嫦娥 号")
a=result.group()
print(a)
#结果：嫦娥 号
 
# 06：“\S”匹配非空白
result=re.match("嫦娥\S号","嫦娥1号")
a=result.group()
print(a)
#结果：嫦娥1号
 
# 07："\w"匹配单词字符，即a-z，A-Z，0-9、_
result=re.match("嫦娥\w号","嫦娥_号")
a=result.group()
print(a)
#结果：嫦娥_号
 
# 08："\W"匹配单词字符，即匹配非单词字符
result=re.match("嫦娥\W号","嫦娥￥号")
a=result.group()
print(a)
#结果：嫦娥￥号


result=re.match("嫦娥\s*号","嫦娥   		号")
a=result.group()
print(a)
'''
嫦娥   号
[Finished in 0.1s]
'''