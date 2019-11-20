#请把下面的Student对象的gender字段对外隐藏起来，用get_gender()和set_gender()代替，并检查参数有效性：
class Student(object):
    def __init__(self, name, gender):
        self.name = name
        self.__gender = gender
    def get_gender(self):
        return self.__gender

    def set_gender(self,gender):
    	if gender == 'female' or gender == 'male':
    		self.__gender = gender
    		return self.__gender
    	else:
        	#raise ValueError('bad datas')
        	print ("0")
bart = Student('Bart', 'male')
if bart.get_gender() != 'male':
    print('测试失败!')
else:
    bart.set_gender('female')
    if bart.get_gender() != 'female':
        print('测试失败!')
    else:
        print('测试成功!')
bart2 = Student('Barrt', 'males')
bart2.set_gender('female2')
