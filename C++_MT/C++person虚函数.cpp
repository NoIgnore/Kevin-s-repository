#include <iostream>
using namespace std;
/*
给定PersonFactory接口，要求实现该类，并以PersonFactory为父类派生学生（Student）与老师（Teacher）两个子类。
学生有年级(int grade)，老师有部门（char department[50])。
基类的PrintInfo依次输出编号，姓名，年龄；学生的PrintInfo除了输出基类信息，还要输出年级；
老师的PrintInfo除了输出基类信息，还要输出部门。各个输出项之间用回车换行符分隔。
基类如下：
class PersonFactory
{
	int id;
	char name[50];
	int age;
	public:
	PersonFactory(int i = 0, char * nm = 0, int a = 15);//i:id;nm:name;a:age
	virtual ~PersonFactory() {};

	virtual void PrintInfo()
	{
		cout << id << endl;
		cout << name << endl;
		cout << age << endl;
	};
	PersonFactory * CreateStudent(int id, char *name, int age, int  grade);
	PersonFactory * CreateTeacher(int id, char *name, int age, char *department);
};
其中构造函数、CreateStudent与CreateTeacher需要您完成函数定义。
Student与Teacher类需要您完成所有类的编写。

部分代码已给出，请将代码补充完整。
*/
#include<iostream>

#include<cstring>

using namespace std;

class PersonFactory

{

	int id;

	char name[50];

	int age;

public:

	PersonFactory(int i = 0, char* nm = NULL, int a = 15);//i:id;nm:name;a:age

	virtual ~PersonFactory() {};

	virtual void PrintInfo()

	{

		cout << id << endl;

		cout << name << endl;

		cout << age << endl;

	};

	PersonFactory* CreateStudent(int id, char* name, int age, int grade);

	PersonFactory* CreateTeacher(int id, char* name, int age, char* department);

};
//...
class Teacher :public PersonFactory
{
public:
	void PrintInfo()
	{
		cout << id << endl;
		cout << name << endl;
		cout << age << endl;
		cout << department << endl;
	};
	Teacher(int id, char* name, int age, char* department);
	~Teacher();
private:
	char department[50];
	int id;
	char name[50];
	int age;
};
Teacher::Teacher(int id, char* name, int age, char* department)
{
	this->id = id;
	strcpy_s(this->name, 50, name);
	this->age = age;
	strcpy_s(this->department, 50, department);
}
Teacher::~Teacher()
{
}
class Student :public PersonFactory
{
public:
	void PrintInfo()
	{
		cout << id << endl;
		cout << name << endl;
		cout << age << endl;
		cout << grade << endl;
	};
	Student(int id, char* name, int age, int grade);
	~Student();
private:
	int grade;
	int id;
	char name[50];
	int age;
};
Student::Student(int id, char* name, int age, int grade)
{
	this->id = id;
	strcpy_s(this->name, 50, name);
	this->age = age;
	this->grade = grade;
}
Student::~Student()
{
}
PersonFactory::PersonFactory(int i, char* nm, int a)
{
	id = i;
	strcpy_s(name, 50, name);
	age = a;
}
PersonFactory* PersonFactory::CreateStudent(int id, char* name, int age, int grade)
{
	return new Student(id, name, age, grade);
}
PersonFactory* PersonFactory::CreateTeacher(int id, char* name, int age, char* department)
{
	return new Teacher(id, name, age, department);
}
int main()

{

	PersonFactory vn;

	PersonFactory* ps, * pt;

	int id, age, grade;

	char name[50], department[50];

	cin >> id >> name >> age >> department;

	ps = vn.CreateTeacher(id, name, age, department);

	ps->PrintInfo();

	cin >> id >> name >> age >> grade;

	ps = vn.CreateStudent(id, name, age, grade);

	ps->PrintInfo();

	return 0;

}

