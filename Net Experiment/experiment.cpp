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
	string subnetname = "0";
	int number = 0;
	ip_list* A = new ip_list;
	ip_subnet* next = nullptr;
};
int address_string_to_int(int n, string s)
{
	int a = 0;
	int b = 0, c = 0, d = 0;
	switch (n)
	{
	case 12:
		a = s[n - 1] - '0';
		break;
	case 13:
		b = s[n - 1] - '0';
		c = s[n - 2] - '0';
		a = c * 10 + b;
		break;
	case 14:
		b = s[n - 1] - '0';
		c = s[n - 2] - '0';
		d = s[n - 3] - '0';
		a = d * 100 + c * 10 + b;
		break;
	}
	return a;
}
void readTxt(string file, ip_list* B)
{
	int abc = 1;
	ifstream infile;
	infile.open(file.data());//将文件流对象与文件连接起来 
	assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行
	string s;
	ip_list* taillist = new ip_list;
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
			ip_list* a = new ip_list;
			a->address = s;
			a->number = address_string_to_int(s.length(), s);
			taillist->next = a;
			taillist = taillist->next;
		}
	}
	infile.close();//关闭文件输入流
}
void read_subnet_Txt(string file, ip_subnet* B)
{
	ifstream infile;
	infile.open(file.data());//将文件流对象与文件连接起来 
	assert(infile.is_open());//若失败,则输出错误消息,并终止程序运行
	string s;
	ip_subnet* taillist = new ip_subnet;
	taillist = B;
	int abc = 1;
	while (getline(infile, s))
	{
		if (abc == 1)
		{
			B->subnetname = s;
			B->number = address_string_to_int(s.length(), s);
			abc = 2;
		}
		else
		{
			ip_subnet* a = new ip_subnet;
			a->subnetname = s;
			a->number = address_string_to_int(s.length(), s);
			taillist->next = a;
			taillist = taillist->next;
		}
	}
	infile.close();//关闭文件输入流
}

int main()
{
	/*ip_subnet* first_head = new ip_subnet;
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
	}*/
	//ip_subnet* second = new ip_subnet;
	//readTxt("11.txt", second);//11.txt在当前目录下
	//ip_list* second_headlist = new ip_list;
	//second_headlist = second->A;
	//while (second_headlist->address != "0")//测试：将文件输出
	//{ 
	//	cout << second_headlist->address << endl;
	//	cout << second_headlist->address[0] << endl;
	//	second_headlist = second_headlist->next;
	//}
	//string s_1 = "123";
	//int a[3] = { 4,5,6 };
	//int b = atoi(s1.c_str());//string转换成int
	//string s2 = to_string(a[0]) + to_string(a[1]) + to_string(a[2]);//int转换成string
	//cout << s1[0] << s1[1] << s1[2] << endl;
	//cout << s2 << b << endl;
	/*cout << strlen((char*)s_1.c_str());
	unsigned char my[3] = "13";
	s_1 = (char*)my;*/
	/*unsigned char my[4] = "133";
	string s = hhj(my);
	cout << s;*/
	//string ipaddress = "192.168.10.226";
	//cout << ipaddress.length();
	//while (second_headlist->address != "0")//测试：将文件输出
	//	{ 
	//		cout << second_headlist->address << " ";
	//		cout << second_headlist->address.length() << endl;
	//		second_headlist = second_headlist->next;
	//	}
	//-----------------------------------------------------
	ip_subnet* Head_of_subnet_list = new ip_subnet;
	read_subnet_Txt("ip子网清单.txt", Head_of_subnet_list);
	ip_subnet* second_headlist = new ip_subnet;
	second_headlist = Head_of_subnet_list;

	ip_list* head_of_ipaddress_list = new ip_list;
	readTxt("ip地址清单.txt", head_of_ipaddress_list);

	while (true)
	{
		int block = 2;
		int low_limit = second_headlist->number - block - 1;
		int high = second_headlist->number - 2;
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
	//---------------------------------------------------------------------
	ip_subnet* fourth_headlist = new ip_subnet;
	fourth_headlist = Head_of_subnet_list;
	ofstream fout;
	fout.open("output.txt");
	while (fourth_headlist)
	{
		ip_list* outputip = new ip_list;
		outputip = fourth_headlist->A->next;
		fout << fourth_headlist->subnetname << " " << ":" << " " << endl;
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
