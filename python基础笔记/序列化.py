import pickle
d = dict(name='Bob', age=20, score=88)
#pickle.dumps(d)
#b'\x80\x03}q\x00(X\x03\x00\x00\x00ageq\x01K\x14X\x05\x00\x00\x00scoreq\x02KXX\x04\x00\x00\x00nameq\x03X\x03\x00\x00\x00Bobq\x04u.'

#pickle.dumps()方法把任意对象序列化成一个bytes，然后，就可以把这个bytes写入文件。或者用另一个方法pickle.dump()直接把对象序列化后写入一个file-like Object：
f = open('D://Pythontestpath//dump.txt', 'wb')
pickle.dump(d, f)
f.close()
'''
看看写入的dump.txt文件，一堆乱七八糟的内容，这些都是Python保存的对象内部信息。

当我们要把对象从磁盘读到内存时，可以先把内容读到一个bytes，然后用pickle.loads()方法反序列化出对象，也可以直接用pickle.load()方法从一个file-like Object中直接反序列化出对象。我们打开另一个Python命令行来反序列化刚才保存的对象：
'''
f = open('D://Pythontestpath//dump.txt', 'rb')
d = pickle.load(f)
f.close()
print (d)
'''
{'name': 'Bob', 'age': 20, 'score': 88}
[Finished in 0.2s]
'''