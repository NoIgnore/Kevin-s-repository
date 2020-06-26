#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
struct ip_list
{
	string address = "0";
	ip_list* next = nullptr;
	int if_included = 0;
	int number = 0;
};
struct ip_subnet
{	
	string address = "0";
	int number = 0;
	ip_list* A = new ip_list;
	ip_subnet* next = nullptr;
};
int address_string_to_int(int n, string s)
{
	int a = 0;
	int b = 0, c = 0, d = 0;
	long long hhj = n;
	switch (n)
	{
	case 12:
		a = s[hhj - 1] - '0';
		break;
	case 13:
		b = s[hhj - 1] - '0';
		c = s[hhj - 2] - '0';
		a = c * 10 + b;
		break;
	case 14:
		b = s[hhj - 1] - '0';
		c = s[hhj - 2] - '0';
		d = s[hhj - 3] - '0';
		a = d * 100 + c * 10 + b;
		break;
	}
	return a;
}
template <class T>
void readTxt(string file, T * B)
{
	int abc = 1;
	ifstream infile;
	infile.open(file.data());//将文件流对象与文件连接起来 
	assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行
	string s;
	T* taillist = new T;
	taillist = B;
	while (getline(infile, s))
	{
		if (abc == 1)
		{
			B->address = s;
			B->number = address_string_to_int(s.length(), s);
			abc = 2;
		}
		else
		{
			T* a = new T;
			a->address = s;
			a->number = address_string_to_int(s.length(), s);
			taillist->next = a;
			taillist = taillist->next;
		}
	}
	infile.close();//关闭文件输入流
}
void ipsubnet_link_iplist(ip_subnet* second_headlist, ip_list* head_of_ipaddress_list)
{
	while (true)
	{
		int block = 4;
		int low_limit = second_headlist->number + 1;
		int high = second_headlist->number + block - 2;
		ip_list* third_headlist = new ip_list;
		third_headlist = head_of_ipaddress_list;
		ip_list* fifth_headlist = new ip_list;
		fifth_headlist = second_headlist->A;
		while (true)
		{
			if (third_headlist->if_included == 0)
			{
				if (third_headlist->number >= low_limit && third_headlist->number <= high)
				{
					fifth_headlist->next = third_headlist;
					fifth_headlist = fifth_headlist->next;
					third_headlist->if_included = 1;
				}
			}
			third_headlist = third_headlist->next;
			if (third_headlist == NULL)
			{
				fifth_headlist->next = nullptr;
				break;
			}
		}
		second_headlist = second_headlist->next;
		if (!second_headlist)break;
	}
}
int main()
{
	ip_subnet* Head_of_subnet_list = new ip_subnet;
	readTxt("ip子网清单.txt", Head_of_subnet_list);
	ip_subnet* second_headlist = new ip_subnet;
	second_headlist = Head_of_subnet_list;

	ip_list* head_of_ipaddress_list = new ip_list;
	readTxt("ip地址清单.txt", head_of_ipaddress_list);
	//---------------------------------------------------------------------
	ipsubnet_link_iplist(second_headlist, head_of_ipaddress_list);
	//---------------------------------------------------------------------
	ip_subnet* fourth_headlist = new ip_subnet;
	fourth_headlist = Head_of_subnet_list;
	ofstream fout;
	fout.open("output.txt");
	while (fourth_headlist)
	{
		ip_list* outputip = new ip_list;
		outputip = fourth_headlist->A->next;
		fout << fourth_headlist->address << " " << ":" << " " << endl;
		int count = 0;
		while (outputip)
		{
			count++;
			fout << outputip->address << " ";
			outputip = outputip->next;
		}
		fout << endl << "共" << count << "个" << endl << endl;
		fourth_headlist = fourth_headlist->next;
	}
	fout << flush;
	fout.close();
	return 0;
}