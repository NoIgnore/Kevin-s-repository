import mysql.connector
# 注意把password设为你的root口令:
conn = mysql.connector.connect(user='root', password='不告诉你好吧', database='test')
'''cursor = conn.cursor()
# 创建user表:
cursor.execute('create table user (id varchar(20) primary key, name varchar(20))')
# 插入一行记录，注意MySQL的占位符是%s:
cursor.execute('insert into user (id, name) values (%s, %s)', ['1', 'Michael'])
cursor.rowcount
# 提交事务:
conn.commit()
cursor.close()'''
#因为我已经添加了表和信息了，所以我注释了
#解决方案MySQL-connector可以帮助我们创建table，但是不能帮助我们创建database。
#首先需要去安装：打开命令提示符——输入：mysql -u root -p，回车，然后输入密码进入mysql,然后输入CREATE DATABASE test;
# 运行查询:
cursor = conn.cursor()
cursor.execute('select * from user where id = %s', ('1',))
values = cursor.fetchall()
# 关闭Cursor和Connection:
cursor.close()
conn.close()
print("success!")