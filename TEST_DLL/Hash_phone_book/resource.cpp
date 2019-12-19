#include "Hsah.h"
void append_new_record(Hsah *h1) {
	char  a[9] = "xiaodong";
	char  b[13] = "zhongguancun";
	char  c[12]= "15675650786";
	h1->append(a,b,c);
	// h1->append("小智", "下家村58号", "15685638912");
	// h1->append("小明", "详细28号", "14226048511");
	// h1->append("小南", "月月光45号", "13226856411");
	// h1->append("小北", "明朗小8号", "13205501111");
	cout << "step1 successfully append..."<<endl;
}

void search_name_output(Hsah *h1) {
	char str1[11];
	cin >> str1;
	h1->findname(str1);
}
void search_phone_output(Hsah *h1) {
	char str1[21];
	cin >> str1;
	h1->findnum(str1);
}
void out_put_num(Hsah *h1) {
	h1->showphone();
}
void out_put_name(Hsah *h1) {
	h1->showname();
}

int main()
{
	Hsah* hs = new Hsah[1];
	int n;
	while (true) {
		cout << endl;
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
			append_new_record(hs);
			break;
		case 1:
			search_name_output(hs);
			break;
		case 2:
			search_phone_output(hs);
			break;
		case 3:
			out_put_num(hs);
			break;
		case 4:
			out_put_name(hs);
			break;
		}
	}
}
