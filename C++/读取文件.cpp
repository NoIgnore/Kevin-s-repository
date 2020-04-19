#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
struct ip_list
{
	string address = "0"; 
	ip_list* next = nullptr;
};
struct ip_subnet
{
	ip_list* A = new ip_list;
	ip_subnet* next = nullptr;
};
void readTxt(string file , ip_subnet* B)
{
	int abc = 1;
	ifstream infile;
	infile.open(file.data());//将文件流对象与文件连接起来 
	assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行
	string s;
	ip_list* taillist = new ip_list;
	taillist = B->A;
	while (getline(infile, s))
	{
		if (abc == 1)
		{
			B->A->address = s;
			abc = 2;
		}
		else
		{
			ip_list* a = new ip_list;
			a->address = s;
			taillist->next = a;
			taillist = taillist->next;
		}
	}
	infile.close();//关闭文件输入流
}
int main()
{
	ip_subnet* first_head = new ip_subnet;
	ip_list* headlist = new ip_list;
	first_head->A->address = "123.123.343.545";
	first_head->A->next = headlist;
	cout << first_head->A->address << endl;
	cout << first_head->A->next->address << endl;
	headlist->address = "123.123.343.545";
	if (headlist->address == first_head->A->address)
	{
		cout << "1" << endl;
	}
	if (first_head->A->next->address == first_head->A->address)
	{
		cout << "2" << endl;
	}
	ip_subnet* second = new ip_subnet;
	readTxt("11.txt",second);
	ip_list* second_headlist = new ip_list;
	second_headlist = second->A;
	while (second_headlist->address != "0")
	{
		cout << second_headlist->address << endl;
		second_headlist = second_headlist->next;
	}
	return 0;
}
/*
123.123.343.545
0
1
2
12354465463
21356
786
43543
512312
123.234.345.456

按任意键关闭此窗口...
*/