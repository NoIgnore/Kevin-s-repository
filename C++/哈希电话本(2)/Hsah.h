#pragma once
#include<iostream>
using namespace std;
struct Node
{
	char* name; //姓名
	char* address;//地址
	char* num;//电话
	Node* pNext;
};

class Hsah
{
private:
	Node* phone;//指针存储散列表，链地址法
	Node* nam;

public:
	Hsah();
	~Hsah();
	int hashphone(char* num); //电话号码散列表函数
	int hashname(char* name); //姓名的散列表函数
	Node* push(char* pname, char* add, char* pnum);
	void append(char* pname, char* add, char* pnum);//添加记录
	Node* findnum(char* pnum);//按号码查找
	Node* findname(char* pname);//按姓名查找
	void showphone();
	void showname();
};
