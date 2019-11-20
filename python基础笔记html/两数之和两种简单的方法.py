'''def twoSum(nums, target):
    lens = len(nums)
    j=-1
    for i in range(lens):
        if (target - nums[i]) in nums:
            if (nums.count(target - nums[i]) == 1)&(target - nums[i] == nums[i]):#如果num2=num1,且nums中只出现了一次，说明找到是num1本身。
                continue
            else:
                j = nums.index(target - nums[i],i+1) #index(x,i+1)是从num1后的序列后找num2（num1为i，num2为x）                
                break
    if j>0:
        return [i,j]
    else:
        return []'''
'''aList = [123, 'xyz', 'runoob', 'abc']

print "xyz 索引位置: ", aList.index( 'xyz' )
print "runoob 索引位置 : ", aList.index( 'runoob', 1, 3 )

以上实例输出结果如下：
xyz 索引位置:  1
runoob 索引位置 :  2'''
'''import time
start=time.perf_counter()'''

'''import datetime
import time
t1 = datetime.datetime.now().microsecond
t3 = time.mktime(datetime.datetime.now().timetuple())'''
def twoSum(nums, target):
    lens = len(nums)
    j=-1
    for i in range(1,lens):
        temp = nums[:i]
        if (target - nums[i]) in temp:
            j = temp.index(target - nums[i])
            break
    if j>=0:
        return [j,i]
nums1 = [2, 7, 11, 15]
target1 = 9
print(twoSum(nums1 , target1 ))
print("-"*30)

'''end=time.perf_counter()
print('Running time: %s Seconds'%(end-start))'''

'''t2 = datetime.datetime.now().microsecond
t4 = time.mktime(datetime.datetime.now().timetuple())
print('funtion time use:%dms' % ((t4 - t3) * 1000 + (t2 - t1) / 1000))'''