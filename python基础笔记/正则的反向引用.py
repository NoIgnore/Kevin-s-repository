import re
if re.search('(\d).*?\1','123123' ):
	print("1 is true")
elif re.search('(why).*\\1','whywhy' ):
	print("2 is true")
else:
	print("no answer")
print('-'*100)
if not re.search('(\d).*?\1','123123' ):
	print("1 is false")
print('-'*100)

if re.search('(ab)(cd)[def]*\\1\\2','abcdecdab'):
	print('3 is true')
if re.search('(ab)(cd)[def]*\\1\\2','abcdeabcd'):
	print("4 is true")
if re.search('(ab)(cd)[def]*\\2\\1','abcdecdab'):
	print('5 is true')
if re.search('(ab)(cd)(hj)[def]*\\3\\2\\1','abcdhjehjcdab'):
	print('6 is true')
'''输出结果
1.python中与老师讲的格式不同，括号内去除斜杠，反向引用时增加斜杠
2.通过4 is true的例子可看出\\1=(ab)

2 is true
----------------------------------------------------------------------------------------------------
1 is false
----------------------------------------------------------------------------------------------------
4 is true
5 is true
6 is true
'''