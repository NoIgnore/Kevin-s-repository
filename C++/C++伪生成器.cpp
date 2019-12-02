// def generator1():
// 	for i in range(100):
// 		yield i+1
// a = generator1()
// print(next(a))
// print(next(a))
// print(next(a))
// '''
// 1
// 2
// 3
// [Finished in 0.1s]
// '''
//python可以用yield实现简单的实现生成器，于是乎想到了用C++实现伪生成器的底层代码
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