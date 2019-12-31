#include <iostream>
using namespace std;

template <class T> T get_min(T* m, int n) 
{
	T min1 = 9999;
	for (int i = 0; i < n; i++)
	{
		if (m[i] < min1)min1 = m[i];
	}
	return min1;
}

int main()
{
	int arr_int[6] = { 1, 2, 3, 4, 5, 6 };
	double arr_double[6] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	cout << get_min(arr_int, 6) << endl;
	cout << get_min(arr_double, 6) << endl;
	return 0;
}
