/*
#include "Hsah.h"
int main()
{
	Hsah hs;
	// ��Ӽ�¼
	
	hs.append("С��", "�йش�22��", "15675650786");
	hs.append("С��", "�¼Ҵ�58��", "15685638912");
	hs.append("С��", "��ϸ28��", "14226048511");
	hs.append("С��", "���¹�45��", "13226856411");
	hs.append("С��", "����С8��", "13205501111");
	cout << endl;
	//���������
	hs.findnum("15675650786");
	hs.findnum("15685638912");

	hs.findnum("17584511");
	cout << endl;

	//����������
	hs.findname("С��");
	hs.findname("С��");

	hs.findname("С");

	cout << endl;

	//��ʾ�б�
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
	h1.append("С��", "�йش�22��", "15675650786");
	h1.append("С��", "�¼Ҵ�58��", "15685638912");
	h1.append("С��", "��ϸ28��", "14226048511");
	h1.append("С��", "���¹�45��", "13226856411");
	h1.append("С��", "����С8��", "13205501111");
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
