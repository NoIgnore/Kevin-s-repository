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
}