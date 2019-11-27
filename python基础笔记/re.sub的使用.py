import re


def main():
    content = 'abc124hello46goodbye67shit'
    list1 = re.findall(r'\d+', content)#\d表示数字，+表示至少一次
    print(list1)
    mylist = list(map(int, list1))
    print(mylist)
    print(sum(mylist))
    print(re.sub(r'\d+[hg]', 'foo1', content))
    print("")
    print(re.sub(r'\d+', '456654', content))


if __name__ == '__main__':
    main()
# ['124', '46', '67']
# [124, 46, 67]
# 237
# abcfoo1ellofoo1oodbye67shit

# abc456654hello456654goodbye456654shit