'''
def twoSum(nums, target):
    hashmap={}
    for ind,num in enumerate(nums):
        hashmap[num] = ind
    for i,num in enumerate(nums):
        #j = hashmap[target - num]
        j = hashmap.get(target - num)
        #如果列表里有两个元素相同，得用j = hashmap.get(target - num)
        if j is not None and i!=j:
        	return [i,j]

nums = [2,7,11,15]
target = 9
a = twoSum(nums,target)
print(a)
nums1 = [1,5,5,7]
target2 = 10
b = twoSum(nums1,target2)
print(b)
'''

'''
enumerate（）用法1
>>>seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
>>> list(enumerate(seasons, start=1))       # 下标从 1 开始
[(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]

enumerate（）用法2
>>>seq = ['one', 'two', 'three']
>>> for i, element in enumerate(seq):
...     print i, element
... 
0 one
1 two
2 three
'''

'''方法四：

类似方法二，不需要 mun2 不需要在整个 dict 中去查找。可以在 num1 之前的 dict 中查找，因此就只需要一次循环可解决。'''

def twoSum(nums, target):
    hashmap={}
    for i,num in enumerate(nums):
        if hashmap.get(target - num) is not None:
            return [i,hashmap.get(target - num)]
        hashmap[num] = i #这句不能放在if语句之前，解决list中有重复值或target-num=num的情况
'''def two_sum(nums, target):
    """这样写更直观，遍历列表同时查字典"""
    dct = {}
    for i, n in enumerate(nums):
        if target - n in dct:
            return [i, dct[target - n]]
        dct[n] = i'''
'''不过方法四相较于方法三的运行速度没有像方法二相较于方法一的速度提升。运行速度在 70ms 多。'''
nums = [2,7,11,15]
target = 9
a = twoSum(nums,target)
print(a)
nums1 = [1,5,5,7]
target2 = 10
b = twoSum(nums1,target2)
print(b)