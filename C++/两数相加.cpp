#include<iostream>
#include<cmath>
using namespace std;
struct ListNode
{
	int val = 0;
	ListNode* next = nullptr;
};
class Solution {
public:
	Solution();
	~Solution();
	int n1;
	int n2;
	int* p1;
	int* p2;
	ListNode* l1 = new ListNode;
	ListNode* l2 = new ListNode;
	ListNode* creat_a_new_list(int* k,int f);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};
Solution::Solution() {
	cout << "input the length of arrays(1): " << endl;
	cin >> this->n1;
	cout << "input the length of arrays(2): " << endl;
	cin >> this->n2;
	this->p1 = new int[this->n1];
	this->p2 = new int[this->n2];
	for (int i = 0; i < this->n1; i++) {
		int j;
		cout << "please input the element(1): ";
		cin >> j;
		if (i < this->n1 - 1) {
			cout << " -> ";
		}
		this->p1[i] = j;
	}
	for (int i = 0; i < this->n2; i++) {
		int j;
		cout << "please input the element(2): ";
		cin >> j;
		if (i < this->n2 - 1) {
			cout << " -> ";
		}
		this->p2[i] = j;
	}
	this->l1 = creat_a_new_list(p1, this->n1);
	this->l2 = creat_a_new_list(p2, this->n2);
}
ListNode* Solution::creat_a_new_list(int* k,int f) {
	ListNode* q = new ListNode;
	for (int i = 0; i < f; i++) {
		ListNode* g = new ListNode;
		g->val = k[i];
		g->next = q;
		q = g;
	}
	return q;
}
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	int a1,sum1=0,l11;
	a1 = (int)pow(10, this->n1 - 1);
	for (int i = 0; i < this->n1; i++) {
		if (l1->next != nullptr) {
			l11 = l1->val;
			sum1 += l11 * a1;
			l1 = l1->next;
			a1 = a1 / 10;
		}
	}
	int a2, sum2 = 0, l22;
	a2 = (int)pow(10, this->n2 - 1);
	for (int i = 0; i < this->n2; i++) {
		if (l2->next != nullptr) {
			l22 = l2->val;
			sum2 += l22 * a2;
			l2 = l2->next;
			a2 = a2 / 10;
		}
	}
	int SUM = sum1 + sum2;
	ListNode* newnewpoint1 = new ListNode;
	ListNode* newnewpoint3 = new ListNode;
	newnewpoint1 = newnewpoint3;
	while (SUM > 0) {
		ListNode* newnewpoint2 = new ListNode;
		newnewpoint2->val = SUM % 10;
		newnewpoint2->next = nullptr;
		newnewpoint3->next = newnewpoint2;
		newnewpoint3 = newnewpoint2;
		SUM = SUM / 10;
	}
	//newnewpoint1 = newnewpoint1->next;
	return newnewpoint1;
}
Solution::~Solution() {
	delete[] this->p1;
	delete[] this->p2;
}
int main() {
	Solution a;
	ListNode* l3 = a.addTwoNumbers(a.l1,a.l2);
	while (l3->next!=nullptr)
	{
		cout << l3->next->val;
		l3 = l3->next;
		if (l3->next != nullptr) {
			cout << " -> ";
		}
	}
	return 0;
}
//input the length of arrays(1) :
//	4
//	input the length of arrays(2) :
//	3
//	please input the element(1) : 8
//	->please input the element(1) : 6
//	->please input the element(1) : 5
//	->please input the element(1) : 1
//	please input the element(2) : 3
//	->please input the element(2) : 7
//	->please input the element(2) : 2
//	1 -> 4 -> 8 -> 1
//  1568+273=1841
//	C++.exe(进程 9444)已退出，返回代码为: 0。
//	按任意键关闭此窗口...
