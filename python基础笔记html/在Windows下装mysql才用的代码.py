import pymysql
# 打开数据库连接
conn = pymysql.connect("localhost","root","password","test" )
# 使用 cursor() 方法创建一个游标对象
cursor = conn.cursor()

# 如果表存在则删除
cursor.execute("DROP TABLE IF EXISTS user")
# 创建 user表
cursor.execute('create table user (id varchar(20) primary key, name varchar(20))')
# 插入一行记录，注意MySQL的占位符是%s
cursor.execute('insert into user (id, name) values (%s, %s)', ['1', 'Michael'])
# 提交事务
conn.commit()

# 运行查询
cursor.execute('select * from user where id = %s', ('1',))
values = cursor.fetchall()
for v in values:
    print('查询结果：', v)

# 关闭Cursor和Connection
cursor.close()
conn.close()