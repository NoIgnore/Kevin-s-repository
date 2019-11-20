import hashlib, random

md5 = hashlib.md5()
md5.update('how to use md5 in python hashlib?'.encode('utf-8'))
print(md5.hexdigest())
'''如果数据量很大，可以分块多次调用update()，最后计算的结果是一样的：
import hashlib
md5 = hashlib.md5()
md5.update('how to use md5 in '.encode('utf-8'))
md5.update('python hashlib?'.encode('utf-8'))
print(md5.hexdigest())'''
def calc_md5(password):
    secret1 = hashlib.md5()
    secret1.update(password.encode('utf-8'))
    return secret1.hexdigest()
a = calc_md5('how to use md5 in python333333 hashlib?')
print (a)


#设计一个验证用户登录的函数，根据用户输入的口令是否正确，返回True或False：
db1 = {
    'michael': 'e10adc3949ba59abbe56e057f20f883e',
    'bob': '878ef96e86145580c38c87f0410ad153',
    'alice': '99b1c2188db85afee403b1536010c2c9'
}
def login1(user, password):
    secret3 = hashlib.md5()
    secret3.update(password.encode('utf-8'))
    if secret3.hexdigest() == db1[user]:
    	return True
    else :
    	return False
# 测试:
assert login1('michael', '123456')
assert login1('bob', 'abc999')
assert login1('alice', 'alice2008')
assert not login1('michael', '1234567')
assert not login1('bob', '123456')
assert not login1('alice', 'Alice2008')
print('1-ok')
print("——"*20)
'''
练习

根据用户输入的登录名和口令模拟用户注册，计算更安全的MD5：
'''
'''
db = {}

def register(username, password):
    db[username] = get_md5(password + username + 'the-Salt')
'''
#然后，根据修改后的MD5算法实现用户登录的验证：

def get_md5(s):
    return hashlib.md5(s.encode('utf-8')).hexdigest()

class User(object):
    def __init__(self, username, password):
        self.username = username
        self.salt = ''.join([chr(random.randint(48, 122)) for i in range(20)])
        #join用于将序列中的元素以指定的字符连接生成一个新的字符串
        #alf = chr(random.randint(65,90))  #根据 ascii码，随机生成字母
        self.password = get_md5(password + self.salt)

db = {
    'michael': User('michael', '123456'),
    'bob': User('bob', 'abc999'),
    'alice': User('alice', 'alice2008')
}
def login(username, password):
    user = db[username]
    print(user.username)
    print(user.salt) 
    print(user.password)
    print('-'*50)
    return user.password == get_md5(password+user.salt)#salt值每次都会变

# 测试:
assert login('michael', '123456')
assert login('bob', 'abc999')
assert login('alice', 'alice2008')
assert not login('michael', '1234567')
assert not login('bob', '123456')
assert not login('alice', 'Alice2008')
print('2-ok')
print("")
alf =''.join([chr(random.randint(65, 90)) for i in range(20)]) #根据 ascii码，随机生成字母
print(alf)
print("")
'''
d26a53750bc40b38b65a520292f69306
88df5c9cc3b51ea1b10117dbe6c5b3cd
1-ok
————————————————————————————————————————
michael
J07[8=8m_HV28A1i<_@1
703474b0383ca4184791bb2c1d366a1f
--------------------------------------------------
bob
O_F\Q_g2Jssqy`rUBqzN
a7120f01b95abe5e8c71d269c1ec082a
--------------------------------------------------
alice
Jg:G=_derN][PDDPQMj`
e16972eaa6136d8b1cfadba011f542d1
--------------------------------------------------
michael
J07[8=8m_HV28A1i<_@1
703474b0383ca4184791bb2c1d366a1f
--------------------------------------------------
bob
O_F\Q_g2Jssqy`rUBqzN
a7120f01b95abe5e8c71d269c1ec082a
--------------------------------------------------
alice
Jg:G=_derN][PDDPQMj`
e16972eaa6136d8b1cfadba011f542d1
--------------------------------------------------
2-ok
[Finished in 0.1s]
'''