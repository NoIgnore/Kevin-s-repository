/*
String类的定义如下：
class String{
private:
	char *mystr;    //字符串
	int len;    //字符串长度
public:
	String(){
		len =0;
		mystr =NULL;
	}
	String(const char* p){
		len = strlen(p);
		mystr = new char[len+1];
		strcpy(mystr,p);
	}
	String(String &s){
		len = s.len;
		if (len !=0)
		{
			mystr = new char[len+1];
			strcpy(mystr,s.mystr);
		}
	}
	~String(){
		 if (mystr != NULL)
		 {
			 delete []mystr;
			 mystr =NULL;
			 len = 0;
		 }
	}
	char *GetStr(){return mystr;}
	void ShowStr(){cout<<mystr;}
	bool IsSubstring(const char *str);
	bool IsSubstring(const String &str);
	int str2num();
	void toUppercase();
};
实现String类的成员方法：
bool IsSubstring(const char *str) 判定字符串str是否为当前String对象的子串，是则返回true,否则返回false。
bool IsSubstring(const String &str) 判断String对象str是否为当前String对象的子串，是则返回true,否则返回false。
int str2num() 将当前String对象转化为数字，转换时忽略出数字以外的字符，
不考虑溢出的情况，如当前字符串为1t2e3s4y5,执行str2num 返回12345。
void toUppercase()将String的字符串的字母全部转化为大写字母。
*/
#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
	char* mystr;
	int len;
public:
	String() {
		len = 0;
		mystr = NULL;
	}
	String(const char* p) {
		len = strlen(p);
		mystr = new char[len + 1];
		strcpy(mystr, p);
	}
	String(String& s) {
		len = s.len;
		if (len != 0)
		{
			mystr = new char[len + 1];
			strcpy(mystr, s.mystr);
		}
	}
	~String() {
		if (mystr != NULL)
		{
			delete[]mystr;
			mystr = NULL;
			len = 0;
		}
	}
	char* GetStr()const { return mystr; }
	void ShowStr() { cout << mystr; }
	bool IsSubstring(const char* str);
	bool IsSubstring(const String& str);
	int str2num();
	void toUppercase();
};
//.....

bool String::IsSubstring(const char* str)
{
	return (strstr(mystr, str) == NULL) ? false : true;
}

bool String::IsSubstring(const String& str)
{
	return (strstr(mystr, str.mystr) == NULL) ? false : true;
}

int String::str2num()
{
	int i=0,sum=0;
	for(i=0;mystr[i]!='\0';i++)
	{
		if (mystr[i] >= '0'&& mystr[i] <= '9')
		{
			sum*=10;
			sum+=mystr[i]-'0';
		}
	}
	return sum;
}

void String::toUppercase()
{
	int i = 0;
	while (mystr[i] != '\0')
	{
		if (mystr[i] >= 'a' && mystr[i] <= 'z') {
			mystr[i] -= 32;
		}
		i++;
	}
}

int main() {

	int type;

	cin >> type;

	String s1("TestclassstRing1");

	String s2("class");

	String s3("s3t4r8i4n7ew9r");

	switch (type) {

	case 1:

		cout << (s1.IsSubstring("class") ? "Y" : "N") << endl;

		break;

	case 2:

		cout << (s1.IsSubstring(s2) ? "Y" : "N") << endl;

		break;

	case 3:

		cout << s3.str2num() << endl;

		break;

	case 4:

		s1.toUppercase();

		cout << s1.GetStr() << endl;

		break;
	}
	return 0;

}