#pragma once
#include<iostream>
using namespace std;
struct Node
{
	char* name; //����
	char* address;//��ַ
	char* num;//�绰
	Node* pNext;
};

class Hsah
{
private:
	Node* phone;//ָ��洢ɢ�б�����ַ��
	Node* nam;

public:
	Hsah();
	~Hsah();
	int hashphone(char* num); //�绰����ɢ�б���
	int hashname(char* name); //������ɢ�б���
	Node* push(char* pname, char* add, char* pnum);
	void append(char* pname, char* add, char* pnum);//��Ӽ�¼
	Node* findnum(char* pnum);//���������
	Node* findname(char* pname);//����������
	void showphone();
	void showname();
};
