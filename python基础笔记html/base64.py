import base64
def safe_base64_decode(s):
    x = len(s) % 4
    if x != 0:
    	for i in range(4-x):
    		s = s + b'='
    		print(s)
    return base64.urlsafe_b64decode(s)
# 测试:
assert b'abcd' == safe_base64_decode(b'YWJjZA=='), safe_base64_decode('YWJjZA==')
assert b'abcd' == safe_base64_decode(b'YWJjZA'), safe_base64_decode('YWJjZA')
print('ok')