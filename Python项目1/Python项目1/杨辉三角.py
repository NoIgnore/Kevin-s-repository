def triangles():
    L = [1]
    while 1:
        yield L
        L = [0] + L + [0]
        L = [L[i] + L[i + 1] for i in range(len(L) - 1)]#L=[1+0] + [0+1]=[1,1]?   yes！！！
n = 0
results = []
for t in triangles():
    results.append(t)
    n = n + 1
    if n == 10:
        break

for t in results:
    print(t)
#L = [x * x for x in range(10)]
#L = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81] L是列表

for k in range(10):
    print(k)#0-9
'''
    [1],
    [1, 1],
    [1, 2, 1],
    [1, 3, 3, 1],
    [1, 4, 6, 4, 1],
    [1, 5, 10, 10, 5,1],
    [1, 6, 15, 20, 15, 6,1],
    [1, 7, 21, 35, 35, 21, 7, 1],
    [1, 8, 28, 56, 70, 56, 28, 8, 1],
    [1, 9, 36, 84, 126, 126, 84, 36, 9, 1]
'''