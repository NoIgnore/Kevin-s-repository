#include "Hsah.h"
void append_new_record(Hsah *h1) {
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
	h1->append("С��", "�йش�22��", "15675650786");
	h1->append("С��", "�¼Ҵ�58��", "15685638912");
	h1->append("С��", "��ϸ28��", "14226048511");
	h1->append("С��", "���¹�45��", "13226856411");
	h1->append("С��", "����С8��", "13205501111");
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
		cout << "����0������һ����¼��" << endl;
		cout << "����1���������������������¼�������" << endl;
		cout << "����2����������ĵ绰������¼�������" << endl;
		cout << "����3�����ݵ绰�����ȫ����¼��" << endl;
		cout << "����4���������������ȫ����¼��" << endl;
		cout << "����5���˳���" << endl;
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
