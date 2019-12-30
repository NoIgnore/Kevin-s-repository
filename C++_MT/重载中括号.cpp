/*
下标操作符 [] 通常用于访问数组元素。重载该运算符用于增强操作 C++ 数组的功能。

在下面代码中完成重载[]函数，使程序能够正常运行，当数组下标越界时输出"InvalidIndex"并返回数组下标为0的元素。


*/
#include <iostream>

using namespace std;

const int SIZE = 10;

class safearay {

private:

	int arr[SIZE];

public:

	safearay()
	{

		register int i;

		for (i = 0; i < SIZE; i++)

		{

			arr[i] = i;

		}

	}
	//...
	int operator[](int s)
	{
		if (s >= 0 && s < SIZE)
		{
			return arr[s];
		}
		else
		{
			cout << "InvalidIndex" << endl;
			return arr[0];
		}
	}
};

int main()

{

	safearay A;

	int index;

	cin >> index;

	cout << A[index] << endl;

	return 0;

}