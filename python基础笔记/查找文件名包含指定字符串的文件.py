import os
def search(path,str):   #输入路径和字符串名称
    for file in os.listdir(path):    #列出当前目录下所有文件及文件夹
        this_path = os.path.join(path,file)     #将文件路径及该路径下的文件进行合并
        if os.path.isfile(this_path):       #判断当前路径是目录还是文件
           if str in file:
              print(this_path)
        elif os.path.isdir(this_path):
            if str in file:
                print(this_path)
            else:                                  #如果不是文件就继续递归执行
                search(this_path,str)

if __name__ == '__main__':
   search(os.path.abspath('.'),'check.txt')
   search(os.path.abspath('.'),'偏函数进制转换.py')
   search(os.path.abspath('.'),'day07_markdown')
   search(os.path.abspath('.'),'check2.txt')
   if '12' in '123':
       print("1")
#编译成功
#PS C:\Users\Desktop\C和C++和Php\python基础笔记html> & "C:/Program Files (x86)/Microsoft Visual Studio/Shared/Python37_64/python.exe" 
#c:/Users/Desktop/C和C++和Php/python基础笔记html/查找文件名包含指定字符串的文件.py

#C:\Users\Desktop\C和C++和Php\python基础笔记html\python基础笔记html1\day07_markdown\check.txt
#C:\Users\Desktop\C和C++和Php\python基础笔记html\偏函数进制转换.py
#C:\Users\Desktop\C和C++和Php\python基础笔记html\python基础笔记html1\day07_markdown
#C:\Users\Desktop\C和C++和Php\python基础笔记html\python基础笔记html1\day07_markdown\day07\media7\14993074876434\check2.txt
#1
