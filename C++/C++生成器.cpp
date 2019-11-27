#include<iostream>
using namespace std;
struct jiegouti
{
	int data;
	jiegouti* next;
};
class SC {
public:
	SC(int n);
	~SC();
	jiegouti* shuzu;
	jiegouti* zhizhen;
	int h;
};
SC::SC(int n) {
	this->shuzu = new jiegouti[n];
	this->zhizhen = new jiegouti[1];
	zhizhen->next = shuzu;
	this->h = 1;
	for (int i = 0; i < n; i++)
	{
		shuzu->data = i;
		//cout << shuzu->data << endl;
		shuzu++;
	}
	shuzu->next = nullptr;
	//cout << p->next->data << endl;
	zhizhen = zhizhen->next;
}
SC::~SC() {
	h += 1;
}
void next_hanshu(SC *a) {
	cout << a->zhizhen->data << endl;
	a->zhizhen++;
}

int main() {
	SC u(3);
	next_hanshu(&u);
	next_hanshu(&u);
	next_hanshu(&u);
	return 0;
}