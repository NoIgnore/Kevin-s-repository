import re
pattern = re.compile(ur"php")
str = u''
print(pattern.search(str))
