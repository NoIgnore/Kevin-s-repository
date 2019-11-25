#include "Hsah.h"
Hsah::Hsah()
{
	this->phone = new Node[20]; //��������ռ�洢��ϣ��
	this->nam = new Node[20];
	for (int i = 0; i < 20; i++)   // ����ϣ�������nextָ���Ϳ�
	{
		this->phone[i].pNext = nullptr;
		this->nam[i].pNext = nullptr;
	}
}

Hsah::~Hsah()
{
	delete[] phone;
	delete[] nam;
}

int Hsah::hashphone(char* num) //�绰����ɢ�б���
{
	// if(num==nullptr)
	// {
	// }
	int key = 0;
	while (*num != '\0')
	{
		key += (*num) - 48;
		num++;
	}

	return key % 20;
}

int Hsah::hashname(char* name) //������ɢ�б���
{
	int key = 0;
	int i = 0;
	while (name[i] != NULL)
	{
		key += int(name[i]);
		i++;
	}
	return abs(key % 20); //absΪ����ֵ������֤keyΪ��ֵ
}
Node* Hsah::push(char* pname, char* add, char* pnum)//����洢�ռ�
{
	Node* p = new Node;
	int len1 = strlen(pname);
	int len2 = strlen(add);
	int len3 = strlen(pnum);

	p->name = new char[len1 + 1];
	strcpy_s(p->name, len1 + 1, pname);
	(p->name)[len1] = '\0';

	p->address = new char[len2 + 1];
	strcpy_s(p->address, len2 + 1, add);
	(p->address)[len2] = '\0';

	p->num = new char[len3 + 1];
	strcpy_s(p->num, len3 + 1, pnum);
	(p->num)[len3] = '\0';

	p->pNext = nullptr;
	return p;
}

void Hsah::append(char* pname, char* add, char* pnum)
{

	Node* newphone = new Node;
	Node* newname = new Node;
	newphone = push(pname, add, pnum);
	newname = push(pname, add, pnum);
	newphone->pNext = nullptr;
	newname->pNext = nullptr;//��Ѱ˼push�ﲻ���Ѿ��ÿ�����

	if (phone[hashphone(pnum)].pNext == nullptr)//����phone������ַָ���
	{
		newphone->pNext = phone[hashphone(pnum)].pNext;
		phone[hashphone(pnum)].pNext = newphone;
	}
	else//�����ͬ��ϣֵ�ĵ�ַ��nextָ��ǿգ����½�һ��pָ���ܵ��գ�Ȼ��newphone׷�ӵ�ĩβ
	{
		Node* p = phone[hashphone(pnum)].pNext;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		p->pNext = newphone;
	}

	if (nam[hashname(pname)].pNext == nullptr)//����name������ַָ���
	{
		newname->pNext = nam[hashname(pname)].pNext;
		nam[hashname(pname)].pNext = newname;
	}
	else
	{
		Node* p = nam[hashname(pname)].pNext;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		p->pNext = newname;
	}
}

Node* Hsah::findnum(char* pnum)//���������
{
	Node* p = phone[hashphone(pnum)].pNext;
	while (p != nullptr)
	{
		if (strcmp(pnum, p->num) == 0)
			break;
		p = p->pNext;
	}
	if (p)
	{
		cout << p->name << "_" << p->address << "_" << p->num << endl;
	}
	else
	{
		cout << "û�д��˼�¼��" << endl;
		return nullptr;
	}

	return p;
}

Node* Hsah::findname(char* pname)//����������
{
	Node* p = nam[hashname(pname)].pNext;
	while (p != nullptr)
	{
		if (strcmp(pname, p->name) == 0)
			// strcmp������string compare(�ַ����Ƚ�)����д�����ڱȽ������ַ��������ݱȽϽ������������
			// ����ʽΪstrcmp(str1,str2)��
			// ��str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�������
			break;
		p = p->pNext;
	}
	if (p)
	{
		cout << p->name << "_" << p->address << "_" << p->num << endl;
	}
	else
	{
		cout << "û�д��˼�¼��" << endl;
		return nullptr;
	}
	return p;
}

void  Hsah::showphone()
{
	for (int i = 0; i < 20; i++)
	{
		if (phone[i].pNext == nullptr)
		{
			continue;
		}
		else
		{
			Node* p = phone[i].pNext; //����phone[i].pNext��λ��
			while (p)
			{
				cout << p->name << "_" << p->address << "_" << p->num << endl;
				p = p->pNext;
			}
		}
	}

}

void  Hsah::showname()
{
	for (int i = 0; i < 20; i++)
	{
		if (nam[i].pNext == nullptr)
		{
			continue;
		}
		else
		{

			Node* p = nam[i].pNext; //����nam[i].pNext��λ��
			while (p)
			{
				cout << p->name << "_" << p->address << "_" << p->num << endl;
				p = p->pNext;
			}

		}

	}
}