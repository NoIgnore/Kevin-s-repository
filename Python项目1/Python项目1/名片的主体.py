import realize
while 1>0 :
    realize.show()
    a=input("input your choice： ")
    the_list=["0","1","2","3","4"]
    if not (a in the_list):
        print("invalid input")
    else:
        if a == the_list[0]:
            print ("you choice to leave")
            break
        elif a == the_list[1]:
            realize.browse()
        elif a == the_list[2]:
            realize.rewrite()
        elif a == the_list[3]:
            realize.to_find()
        else :
            realize.add()

