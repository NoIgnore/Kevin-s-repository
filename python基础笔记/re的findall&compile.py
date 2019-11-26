import re


def main():
    content = 'Hello, I am Jerry, from Chongqing, a montain city, nice to meet you……'
    regex = re.compile('\w*o\w*')#\w表示[A-Za-z0-9_]
    #*表示匹配前面字符0或无限次
    #这里的o是查找带O的字母的意思
    x = regex.findall(content)
    print(x)


if __name__ == '__main__':
    main()
# ['Hello', 'from', 'Chongqing', 'montain', 'to', 'you']