def is_palindrome2(h):
	n = str(h)
	if len(n) == 1:
		return h
	elif len(n)==2:
		b = h % 10
		c = (h-b)/10
		if b == c:
			return h
	elif len(n)==3:
		d = h % 10
		e = int(h/100)
		if e == d:
			return h
af = is_palindrome2(55)
print (af)#自己写的鬼长~~~~~~~~~~
'''
def is_palindrome(n):
    return str(n) == str(n)[::-1] #这是网上别人写的
'''
output = filter(is_palindrome2, range(1, 100))
print('1~1000:', list(output))
if list(filter(is_palindrome2, range(1, 200))) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191]:
    print('测试成功!')
else:
    print('测试失败!')