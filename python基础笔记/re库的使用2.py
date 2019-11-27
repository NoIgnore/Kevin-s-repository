import re

content = "Extra things hello 123455 World_this is a regex Demo extra things"

content = re.sub('(\d+)',r'\1 7890',content)#\1是获取第一个匹配的结果，为了防止转义字符的问题，我们需要在前面加上r
print(content)

print("-"*100)

content= """hello 12345 world_this
fan
"""

pattern =re.compile("hello.*fan",re.S)

result = re.match(pattern,content)
print('1',result)
print('2',result.group())
print("-"*100)

content2= """hello fan 12345 world_this  aaa_fan"""

pattern2 =re.compile("hello.*?fan",re.S)
pattern1 =re.compile("hello.*fan",re.S)
result1 = re.match(pattern1,content2)
result2 = re.match(pattern2,content2)
print('1',result1)
print('2',result1.group())
print('3',result2)
print('4',result2.group())

