circle_1 = list('zwsxedcrfvtgbyhnujmikolpaq')
circle_2 = list('ertyuiopasdfghjklzxcvbnmqw')
circle_3 = list('wryipsfhkxvnqetuoadgjlzcbm')
mapping  = list('nmlkjihgfedcbazyxwvutsrqpo')
def num_plus(abc):
    test_char = abc[0]
    for a in range(26):
        if a != 25:
            abc[a] = abc[a + 1]
        else:
            abc[a] = test_char
q = 0
w = 0
s1 = input("please input lowercase: ")
len_of_string = len(s1)
input_string = list(s1)
for cal in range(len_of_string):
    e = ord(input_string[cal]) - 97
    input_string[cal] = circle_1[e]
    num_plus(circle_1)
    q += 1
    if q == 26:
        num_plus(circle_2)
        q = 0
        w += 1
    e = ord(input_string[cal]) - 97
    input_string[cal] = circle_2[e]
    if w == 26:
        num_plus(circle_3)
        w = 0
    e = ord(input_string[cal]) - 97
    input_string[cal] = circle_3[e]
    e = ord(input_string[cal]) - 97
    input_string[cal] = mapping[e]
input_string = ''.join(input_string)
print("The cipher is: " + input_string)