def findminandmax(x):
    if len(x) != 0:
        a = 100
        b = 0
        for i in x:
            if i <= a:
                a = i
            if i >= b:
                b = i
        c = (a,b)
        print(c)
    else :
        return (None,None)
#findminandmax([7, 1, 3, 9, 5])
findminandmax([7,1])
