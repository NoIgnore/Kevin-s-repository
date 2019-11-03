card_list = []

def show():
    print("This Is The Center Split Line:" + "-" * 60)
    print("0=exit 1=browse 2=rewrite 3=find 4=add")

def browse():
    print ("split line:browse-------------------")
    print ("you choice to browse")
    if len(card_list) == 0:
        print("No record")
        return
    for show_name in ["Your name","Your number"]:
        print (show_name,end="\t")
    print("")
    for x in card_list:
        print("%s\t\t%s" %(x["name"],x["phone_number"]))
        print("")

def to_find():
    print ("split line:find---------------------")
    print ("you choice to find")
    if len(card_list) == 0:
        print("No record")
        return
    find_content = input("please input the name you want to find:   ")
    for f in card_list:
        if f["name"] == find_content:
            print("the result is in the position of %d" %(card_list.index(f)+1))
            for show_name in ["Your name","Your number"]:
                print (show_name,end="\t")
            print("")
            print("%s\t\t%s" %(f["name"],f["phone_number"]))
            break
    else :
        print ("can’t find the fxxing %s name" % find_content)

def rewrite():
    print ("split line:rewrite------------------")
    print ("you choice to rewrite")
    if len(card_list) == 0:
        print("No record")
        return
    b=input("please input the name you want to direct:   ")
    for h in card_list:
        if h["name"] == b:
            for show_name in ["Your name","Your number"]:
                print (show_name,end="\t")
            print("")
            print("%s\t\t%s" %(h["name"],h["phone_number"]))
            print ("1 = change datas ; 2 = exit ; 3 = delete:  ")
            fun_tion = int(input ("please input the funtion number:   "))
            if fun_tion == 1:
                h["name"]=input("chang the name  ")
                h["phone_number"]=input("change the number   ")
            if fun_tion == 2:
                break
            if fun_tion == 3:
                print("delete the number and name   ")
                card_list.remove(h)
                break
        else :
            print ("can’t find the fxxing %s name" % b)



def add():
    print ("split line:----------------------")
    print ("you choice to add")
    name_str=input("please input your name: ")
    phone_str=input("please input your phone number:  ")
    card_dict =  {"name":name_str,"phone_number":phone_str}
    card_list.append(card_dict)
    print (card_list)
    print ("successfully add %s" %name_str )