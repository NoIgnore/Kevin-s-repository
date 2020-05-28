#include <bits/stdc++.h>
#include <openssl/bn.h>
#include <string.h>
using namespace std;
string mod_exp(string a, string e, string m) 
{
	BIGNUM *ret1 = BN_new(), *ret2 = BN_new();
	BIGNUM *ret3 = BN_new(), *ret4 = BN_new();
	BN_CTX *ctx;
	ctx = BN_CTX_new();
	int i;
	char *p = NULL;

	BN_dec2bn(&ret1, a.c_str());
	BN_dec2bn(&ret2, e.c_str());
	BN_dec2bn(&ret3, m.c_str());
	//----
	//BIGNUM * BN_ bin2bn(const unsigned char *s， int len，BIGNUM *ret)
	// 将s中的换为大数，
	// 入参
	// S
	// :为内存地址，
	// len :为数据长度, 
	// 出参:
	// ret :为返回值。

	//6.3
	// char *BN_ bn2dec(const BIGNUM *a)
	// 将大数转换成整数字符串。
	// return :返回值中存放整数字符串，它由内部分配空间，
	// 用户必须在外部用OPENSSL_ _free函 数释放该空间。
	// int BN_ dec2bn(BIGNUM **a, const char *str); //将 整数字符串转换成大数。
	// 6.4

	i = BN_mod_exp(ret4, ret1, ret2, ret3, ctx);
	p = BN_bn2dec(ret4);
	//----
	BN_free(ret1);
	BN_free(ret2);
	BN_free(ret3);
	BN_free(ret4);
	BN_CTX_free(ctx);
	string s1(p);
	OPENSSL_free(p);
	return s1;
}

// 该函数用于进行大数求乘法逆元
//  参数:
//      string类型, 求解a关于mod m的乘法逆元, 表示为10进制数字符串
//  返回值:
//      string类型, 返回计算的结果, 表示为10进制数字符串
string mod_inverse(string a, string m) 
{
	BIGNUM *ret1 = BN_new(), *ret2 = BN_new();
	BIGNUM *ret3 = BN_new(), *ret4 = BN_new();
	BN_CTX *ctx;
	ctx = BN_CTX_new();
	char *p = NULL;

	BN_dec2bn(&ret1, a.c_str());
	BN_dec2bn(&ret2, m.c_str());
	ret4 = BN_mod_inverse(NULL, ret1, ret2, ctx);
	p = BN_bn2dec(ret4);


	BN_free(ret1);
	BN_free(ret2);
	BN_free(ret3);
	BN_free(ret4);
	BN_CTX_free(ctx);
	string s1(p);
	OPENSSL_free(p);
	return s1;
}
