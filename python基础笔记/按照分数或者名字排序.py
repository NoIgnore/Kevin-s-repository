import requests
L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
def by_name(t):
    return t[0]
def by_score(t):
    return -t[1]#返回列表中元组的第二个值，并且返回的是负数，由sort由大到小排序
L2 = sorted(L, key=by_score)
print("按照分数排序： ",L2)
L1 = sorted(L, key=by_name)
print("按照名字排序： ",L1)
