#include <iostream>
using namespace std;

namespace nsA
{
	int x = 1, y = 2; 	
	int add_something(int n) 	{ 		return n + 1; 	} 	
	namespace nsB 	
	{ 		
		char x = 'a'; 		
		char y = 'b'; 		
		int add_something(int n) 		
		{ 			return n + 2; 		} 	
	}
}

int main()
{
	using namespace nsA;
	cout << x << "," << y << endl;
	cout << nsA::nsB::x << "," << nsA::nsB::y << endl;
	cout << add_something(10) << endl;
	cout << nsA::nsB::add_something(10) << endl;
    return 0;
}

