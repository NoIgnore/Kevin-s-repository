#练习：对Student类编写单元测试，结果发现测试不通过，请修改Student类，让测试通过：
import unittest
class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def get_grade(self):
        if self.score > 100 or self.score < 0:
            raise ValueError()#多加了两行raise error
        if 80 > self.score >= 60:#把self.score >= 60:改了
            return 'B'
        if self.score >= 80:
            return 'A'
        else:
            return 'C'

class TestStudent(unittest.TestCase):

    def test_80_to_100(self):
        s1 = Student('Bart', 80)
        s2 = Student('Lisa', 100)
        self.assertEqual(s1.get_grade(), 'A')
        self.assertEqual(s2.get_grade(), 'A')

    def test_60_to_80(self):
        s1 = Student('Bart', 60)
        s2 = Student('Lisa', 79)
        self.assertEqual(s1.get_grade(), 'B')
        self.assertEqual(s2.get_grade(), 'B')

    def test_0_to_60(self):
        s1 = Student('Bart', 0)
        s2 = Student('Lisa', 59)
        self.assertEqual(s1.get_grade(), 'C')
        self.assertEqual(s2.get_grade(), 'C')

    def test_invalid(self):
        s1 = Student('Bart', -1)
        s2 = Student('Lisa', 101)
        with self.assertRaises(ValueError):
            s1.get_grade()
        with self.assertRaises(ValueError):
            s2.get_grade() 
'''
另一种重要的断言就是期待抛出指定类型的Error，比如通过d['empty']访问不存在的key时，断言会抛出KeyError：

with self.assertRaises(KeyError):
    value = d['empty']

而通过d.empty访问不存在的key时，我们期待抛出AttributeError：

with self.assertRaises(AttributeError):
    value = d.empty

'''
if __name__ == '__main__':
    unittest.main()
'''
..FF
======================================================================
FAIL: test_80_to_100 (__main__.TestStudent)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "c:/Users/12091/Desktop/Python.py", line 24, in test_80_to_100 
    self.assertEqual(s1.get_grade(), 'A')
AssertionError: 'B' != 'A'
- B
+ A

======================================================================
FAIL: test_invalid (__main__.TestStudent)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "c:/Users/12091/Desktop/Python.py", line 43, in test_invalid
    s1.get_grade()
AssertionError: ValueError not raised

----------------------------------------------------------------------
Ran 4 tests in 0.002s

FAILED (failures=2)
'''