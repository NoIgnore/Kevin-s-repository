import heapq

data = [19, 9, 4, 10, 11]
heapq.heapify(data)

print(data)


'''
heapq.heapify(data)将data从无序转化成一个最小堆

             4
    9                 19
10       11
'''