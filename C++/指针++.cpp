#include<iostream>
using namespace std;
struct shengchengqi_1
{
	int data;
	shengchengqi_1* next;
};
void shengchenhanshu(int n) {
	shengchengqi_1* shuzu = new shengchengqi_1[n];
	shengchengqi_1* p = new shengchengqi_1[1];
	p->next = shuzu;
	for (int i = 0; i < n; i++)
	{
		shuzu->data = i;
		//cout << shuzu->data << endl;
		shuzu++;
	}
	shuzu->next = nullptr;
	cout << p->next->data << endl;
	p = p->next;
	for (int i = 0; i < n; i++) {
		if (p->data) {
			cout << p->data;
			cout << endl;
		}
		p++;
	}
}