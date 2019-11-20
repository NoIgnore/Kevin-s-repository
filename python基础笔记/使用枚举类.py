#把Student的gender属性改造为枚举类型，可以避免使用字符串：
from enum import Enum, unique
class Gender(Enum):
    Male = 0
    Female = 1
class Student(object):
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender
# 测试:
bart = Student('Bart', Gender.Male)
if bart.gender == Gender.Male:#Gender.Male等于Male
    print('测试通过!')
else:
    print('测试失败!')
print (bart.gender)
print (Gender.Male)
print(bart.gender.value)
'''
测试通过!
Gender.Male
Gender.Male
0
[Finished in 0.1s]
'''
'''
更好的方法是为这样的枚举类型定义一个class类型，然后，每个常量都是class的一个唯一实例。Python提供了Enum类来实现这个功能：

from enum import Enum

Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'))

这样我们就获得了Month类型的枚举类，可以直接使用Month.Jan来引用一个常量，或者枚举它的所有成员：

for name, member in Month.__members__.items():
    print(name, '=>', member, ',', member.value)

value属性则是自动赋给成员的int常量，默认从1开始计数。

如果需要更精确地控制枚举类型，可以从Enum派生出自定义类：

from enum import Enum, unique

@unique
class Weekday(Enum):
    Sun = 0 # Sun的value被设定为0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6

@unique装饰器可以帮助我们检查保证没有重复值。
'''