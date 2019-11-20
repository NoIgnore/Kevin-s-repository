import json

class Student(object):
    def __init__(self, name, age, score):
        self.name = name
        self.age = age
        self.score = score
def student2dict(std):
    return {
        'name': std.name,
        'age': std.age,
        'score': std.score
    }
s = Student('Bob', 20, 88)
print(json.dumps(s, default=student2dict))
print ("")
#对中文进行JSON序列化时，json.dumps()提供了一个ensure_ascii参数，观察该参数对结果的影响：
#ensure_ascii默认情况是True，这时会把中文转成Unicode码，设置成False的话就是打印中文
obj = dict(name='小明', age=20)
s = json.dumps(obj, ensure_ascii=True)
print(s,'ensure_ascii=True')

s1 = json.dumps(obj, ensure_ascii=False)
print(s1,'   ensure_ascii=False')