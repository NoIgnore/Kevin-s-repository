#include "Hsah.h"
Hsah::Hsah()
{
	this->phone = new Node[20]; //分配数组空间存储哈希表
	this->nam = new Node[20];
	for (int i = 0; i < 20; i++)   // 将指针滞空
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

int Hsah::hashphone(char* num) //电话号码散列表函数
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

int Hsah::hashname(char* name) //姓名的散列表函数
{
	int key = 0;
	int i = 0;
	while (name[i] != NULL)
	{
		key += int(name[i]);
		i++;
	}
	return abs(key % 20); //abs函数保证key为正值
}
Node* Hsah::push(char* pname, char* add, char* pnum)//分配存储空间
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
	newname->pNext = nullptr;

	if (phone[hashphone(pnum)].pNext == nullptr)
	{
		newphone->pNext = phone[hashphone(pnum)].pNext;
		phone[hashphone(pnum)].pNext = newphone;
	}
	else
	{
		Node* p = phone[hashphone(pnum)].pNext;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		p->pNext = newphone;
	}

	if (nam[hashname(pname)].pNext == nullptr)
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

Node* Hsah::findnum(char* pnum)//按号码查找
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
		cout << p->name << "　" << p->num << " " << p->address << endl;
	}
	else
	{
		cout << "没有此人记录！" << endl;
		return nullptr;
	}


	return p;
}

Node* Hsah::findname(char* pname)//按姓名查找
{
	Node* p = nam[hashname(pname)].pNext;
	while (p != nullptr)
	{
		if (strcmp(pname, p->name) == 0)
			break;
		p = p->pNext;
	}
	if (p)
	{
		cout << p->name << "　" << p->num << " " << p->address << endl;
	}
	else
	{
		cout << "没有此人记录！" << endl;
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
			Node* p = phone[i].pNext; //还是phone[i].pNext部位空
			while (p)
			{


				cout << "姓名：" << p->name << endl;
				cout << "电话号码：" << p->num << endl;
				cout << "住宅地址：" << p->address << endl;


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

			Node* p = nam[i].pNext; //还是nam[i].pNext部位空
			while (p)
			{
				cout << "姓名：" << p->name << endl;
				cout << "电话号码：" << p->num << endl;
				cout << "住宅地址：" << p->address << endl;
				p = p->pNext;
			}

		}

	}
	cout << "请按任意键继续:";
	cin.get();
}