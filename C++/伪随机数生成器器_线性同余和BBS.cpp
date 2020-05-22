#include <iostream>
#include <time.h>
#include<fstream>
#include<cassert>
#include<string>
#include<math.h>
#include<ctime>
using namespace std;
struct my_struct
{
	int a = 0;
	my_struct* next = NULL;
};
struct binstack
{
	int s;
	binstack* next;
};
unsigned int bin_dec(string s)//bin to dec
{
	int length = s.length();
	unsigned int dec = 0;
	for (int i = 0; i < length; i++)
	{
		int j = (s[i] == '1' ? 1 : 0);
		dec += (j == 1 ? pow(2, length - i - 1) : 0);
	}
	return dec;
}
string dec_bin(unsigned int a)
{
	binstack* k1 = new binstack;
	binstack* k2 = k1;
	string s2;
	if (a != 0)
	{
		while (a != 0)
		{
			binstack* kk = new binstack;
			kk->s = a % 2;
			kk->next = k2;
			k2 = kk;
			a = a / 2;
		}
		binstack* k3 = k2;
		while (k3 != k1)
		{
			s2 += to_string(k3->s);
			k3 = k3->next;
		}
	}
	else
	{
		s2 = "0";
	}
	return s2;
}
unsigned int _seed = 1;
const unsigned int _a = 1103515245;
const unsigned int _c = 12345;
const unsigned int _m = 2147483648;
void lcg_srand(unsigned int seed) {
	_seed = seed;
}

unsigned int lcg_rand() {
	_seed = (_seed * _a + _c) % _m;
	return _seed;
}

const int BBS_USE_LAST_BIT = 0;
const int BBS_USE_ODD_BIT = 1;
const int BBS_USE_EVEN_BIT = 2;

// 既定的全局变量，请勿修改以下四个变量值以及变量名，否则测试将不通过
unsigned long _bbs_seed = 3;
const unsigned long _p = 11;
const unsigned long _q = 19;
const unsigned long _n = _p * _q;
unsigned int bbs_rand(int flag) {
	my_struct* head = new my_struct;
	my_struct* tail = head;
	tail->a = 9 % _n;
	for (int i = 0; i < 31; i++)
	{
		my_struct* ab = new my_struct;
		ab->a = ((tail->a * tail->a) % _n);
		tail->next = ab;
		tail = ab;
	}
	string s1, s2;
	if (flag == 0)
	{
		while (head)
		{
			s2 = dec_bin(head->a);
			s1 += s2[s2.length() - 1];
			head = head->next;
		}
	}
	else
	{
		while (head)
		{
			int count_h = 0;
			s2 = dec_bin(head->a);
			for (int i = 0; i < s2.length(); i++)
			{
				count_h += (s2[i] == '1' ? 1 : 0);
			}
			s1 += (flag == 1 ? (count_h % 2 == 1 ? '0' : '1') : (count_h % 2 == 0 ? '0' : '1'));
			head = head->next;
		}
	}
	return bin_dec(s1);
}
void measure_rand_time() {
	clock_t start, end;
	start = clock();
	unsigned int s2;
	for (int i = 0; i < 10; i++)
	{
		lcg_srand((unsigned int)time(NULL));
		s2 = lcg_rand();
	}
	end = clock();
	printf("lcg time is %f us\n", ((double)end - start) / 1000);
	start = clock();
	for (int i = 0; i < 10; i++)
	{
		s2 = (bbs_rand(0));
	}
	end = clock();
	printf("bbs time is %f us\n", ((double)end - start) / 1000);
}
int main()
{
	unsigned int a;
	for (int i = 0; i < 3; i++)
	{
		a = bbs_rand(i);
		cout << a << endl;
		cout << dec_bin(a) << endl;
	}
	/*cout << bin_dec("01101") << endl;*/
	/*string s2 = "1010010";
	int count_h = 0;
	string s1;
	for (int i = 0; i < s2.length(); i++)
	{
		count_h += (s2[i] == '1' ? 1 : 0);
	}
	cout << count_h << endl;
	s1 += (count_h % 2 == 0 ? '0' : '1');
	cout << s1;*/
	return 0;
}
/*3245086401
11000001011011000001011011000001
2487829652
10010100010010010100010010010100
1807137643
1101011101101101011101101101011*/