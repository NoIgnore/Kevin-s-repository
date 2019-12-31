#include<iostream>
using namespace std;

class Base{
    public:
        Base(int op1, int op2) : op1(op1), op2(op2) {

        }
        //。。。。
        friend Base operator+(int n,Base& c) 	
        { 		c.op1 += n; 		c.op2 += n; 		return c; 	}
        //。。。。
        int get_op1() const {
            return op1;
        }

        int get_op2() const {
            return op2;
        }
    private:
        int op1;
        int op2;
};

int main() {
    int op1, op2;
    cin >> op1 >> op2;
    Base base = Base(op1, op2);
    Base sum = 3 + base;
    cout << sum.get_op1() << sum.get_op2() << endl;
    return 0;
}

