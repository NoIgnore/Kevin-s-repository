#include<iostream>//写个stack
using namespace std;
struct sqstack
{
	int* base = new int;
	int* top = new int;
	int stacksize=5;
};
int init_stack(sqstack& s) {
	s.base = new int[s.stacksize];
	s.top = s.base;
	return 1;
}
void destory_stack(sqstack& s) {
	delete[]s.base;
	delete[]s.top;
}
int clear_stack(sqstack& s) {
	while (s.top!=s.base)
	{
		s.top--;
		*s.top = 0;
	}
	return 1;
}
int assert_if_empty(sqstack& s) {
	if (s.top != s.base) {
		return -1;
	}
	else {
		return 1;
	}
}
//int length_of_stack(sqstack& s);
int push_element(sqstack& s, int n) {
	if (s.top - s.base >= s.stacksize) {
		cout << "Overflow...." << endl;
		return 0;
	}
	else {
		*s.top++ = n;
	}
	return 1;
}
int pop_element(sqstack& s) {
	if (s.top - s.base >= 0) {
		s.top--;
		cout << *s.top << endl;
		return 1;
	}
}
int main() {
	sqstack st;
	init_stack(st);
	int n;
	cin >> n;
	st.stacksize = n;
	for (int i = 1; i <= n; i++) {
		push_element(st, i);
	}
	//push_element(st, 1);
	for (int i = 1; i <= n-1; i++) {
		pop_element(st);
	}
	if (assert_if_empty(st)==1) {
		cout << "It is empty..." << endl;
	}
	return 0;
}