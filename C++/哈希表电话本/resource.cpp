/*
#include "Hsah.h"
int main()
{
	Hsah hs;
	// 添加记录
	
	hs.append("小东", "中关村22号", "15675650786");
	hs.append("小智", "下家村58号", "15685638912");
	hs.append("小明", "详细28号", "14226048511");
	hs.append("小南", "月月光45号", "13226856411");
	hs.append("小北", "明朗小8号", "13205501111");
	cout << endl;
	//按号码查找
	hs.findnum("15675650786");
	hs.findnum("15685638912");

	hs.findnum("17584511");
	cout << endl;

	//按姓名查找
	hs.findname("小明");
	hs.findname("小南");

	hs.findname("小");

	cout << endl;

	//显示列表
	hs.showphone();
	cout << endl;
	hs.showname();
	return 0;
}*/


#include "Hsah.h"
void append_new_record(Hsah h1) {
	/*char str1[11], str2[16], str3[21];
	//cin.get(str1, 11);
	//cin.get(str2, 16);
	//cin.get(str3, 21);
	cin >> str1;
	cin >> str2;
	cin >> str3;
	//cin >> str1 >> str2 >> str3;
	h1.append(str1, str2, str3);
	h1.findname(str1);
	cout << endl;
	h1.findnum(str3);*/
	h1.append("小东", "中关村22号", "15675650786");
	h1.append("小智", "下家村58号", "15685638912");
	h1.append("小明", "详细28号", "14226048511");
	h1.append("小南", "月月光45号", "13226856411");
	h1.append("小北", "明朗小8号", "13205501111");
	cout << "step1 successfully append..."<<endl;
}
void search_name_output(Hsah h1) {
	char str1[11];
	cin >> str1;
	h1.findname(str1);
}
void search_phone_output(Hsah h1) {
	char str1[21];
	cin >> str1;
	h1.findnum(str1);
}
void out_put_num(Hsah h1) {
	h1.showphone();
}
void out_put_name(Hsah h1) {
	h1.showname();
}

int main()
{
	Hsah hs;
	int n;
	while (true) {
		cout << "input your choice:  "<< endl;
		cout << "输入0：增加一条记录。" << endl;
		cout << "输入1：根据输入的姓名搜索记录并输出。" << endl;
		cout << "输入2：根据输入的电话搜索记录并输出。" << endl;
		cout << "输入3：根据电话表输出全部记录。" << endl;
		cout << "输入4：根据姓名表输出全部记录。" << endl;
		cout << "输入5：退出。" << endl;
		cin >> n;
		if (n == 5) {
			return 0;
		}
		switch (n){
		case 0:
			char str1[11], str2[16], str3[21];
			cin >> str1;
			cin >> str2;
			cin >> str3;
			hs.append(str1, str2, str3);
			cout << "step1 successfully append..." << endl;
			break;
		case 1:
			char str4[11];
			cin >> str4;
			hs.findname(str4);
			break;
		case 2:
			char str5[11];
			cin >> str5;
			hs.findnum(str5);
			break;
		case 3:
			hs.showphone();
			break;
		case 4:
			hs.showname();
			break;
		}
	}
}
