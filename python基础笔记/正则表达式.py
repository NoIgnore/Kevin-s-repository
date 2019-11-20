import re
# 编译:
re_telephone = re.compile(r'^(\d{3})-(\d{3,8})$')
# 使用：
print (re_telephone.match('010-12345').groups())

print (re_telephone.match('010-8086').groups())

'''请尝试写一个验证Email地址的正则表达式。版本一应该可以验证出类似的Email：
    someone@gmail.com
    bill.gates@microsoft.com
'''
def is_valid_email(addr):
    re_mail = re.compile(r'^([a-z]+)(\.[a-z]+|[a-z])(@[a-z]+)\.com$')#^表示开头，'+'匹配前面的子表达式一次或多次(大于等于1次）。例如，“zo+”能匹配“zo”以及“zoo”，但不能匹配“z”。+等价于{1,}。
    if re_mail.match(addr):
        return True
# 测试:
assert is_valid_email('someone@gmail.com')
assert is_valid_email('bill.gates@microsoft.com')
assert not is_valid_email('bob#example.com')
assert not is_valid_email('mr-bob@example.com')
print('1ok')
print("-" * 100)
'''
版本二可以提取出带名字的Email地址：
<Tom Paris> tom@voyager.org => Tom Paris
bob@example.com => bob
'''
# 测试:
def name_of_email(addr):
    re_mail = re.compile(r'^(.*?)([a-zA-Z\s]+)(.*)$')#r'^(.*?):第一组是以任意字符开头的最小匹配([a-zA-Z\s]+):第二组是任意个字母(.*)$:任意个任意的字符结尾'
    m = re_mail.match(addr)
    print(m.group(1))
    print(m.group(2))
    print(m.group(3))
    print("——" * 20)
    return m.group(2)
assert name_of_email('<Tom Paris> tom@voyager.org') == 'Tom Paris'
assert name_of_email('tom@voyager.org') == 'tom'
print('2ok')
'''
('010', '12345')
('010', '8086')
1ok
----------------------------------------------------------------------------------------------------
<
Tom Paris
> tom@voyager.org
————————————————————————————————————————

tom
@voyager.org
————————————————————————————————————————可见tom@voyager.org第一组是空格
2ok
[Finished in 0.1s]
'''