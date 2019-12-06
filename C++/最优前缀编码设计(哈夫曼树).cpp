#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
#include<fstream>
using namespace std;

struct HuffTree			//树结点结构体
{
	char data = 'q';				//数据：字符
	int weight = 0;				//权值
	HuffTree* left = NULL, * right = NULL;	//左右子树
};


typedef pair<char, string> Pair;	//为了方便起见，现将前者简化写法
//pair<T1, T2> p1;            //创建一个空的pair对象（使用默认构造），它的两个元素分别是T1和T2类型，采用值初始化。
//pair<T1, T2> p1(v1, v2);    //创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，second成员初始化为v2。
//make_pair(v1, v2);          // 以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。
//p1 < p2;                    // 两个pair对象间的小于运算，其定义遵循字典次序：如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回true。
//p1 == p2；                  // 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
//p1.first;                   // 返回对象p1中名为first的公有数据成员
//p1.second;                 // 返回对象p1中名为second的公有数据成员
bool space = false;
HuffTree* FinalTree;			//最终的哈夫曼树
vector<Pair> HuffDic;			//存放每个字符的哈夫曼编码
vector<HuffTree*> Huff;			//存放开始的全部哈夫曼树
string DecodeStr;				//对01字符串解码后的字符串

HuffTree* CreateTree(const char c, int i)	//将数据化为小树
{
	HuffTree* t = new HuffTree;
	t->data = c;
	t->weight = i;
	return t;			//返回小树
}

void Initial()
{
	int n, t;
	char c;
	cout << "请输入数据组数:";				//数据组数：欲编码字母个数
	cin >> n;
	while (n--)
	{
		static int k = 1;
		cout << "第" << k++ << "组(字母，权值):";
		cin >> c >> t;
		Huff.push_back(CreateTree(c, t));		//将小树存Huff中去
	}
	cout << "是否输入空格' '的权值？如果是，请输入正整数；如果否，请输入负数:";			//确认是否为空格编码
	cin >> t;
	if (t >= 0)
	{
		Huff.push_back(CreateTree(' ', t));
		space = true;
	}

}

bool SortCmp(HuffTree* h1, HuffTree* h2)		//sort的比较函数重载
{
	return h1->weight < h2->weight;			//按权值升序
}

HuffTree* TreeMerge(HuffTree* t1, HuffTree* t2)		//和并两棵小树，使两棵小树成为大树的孩子
{
	HuffTree* t = new HuffTree;
	t->data = '#';							//以#号表示无字符
	t->weight = t1->weight + t2->weight;		//大树的权值是两棵小树权值之和
	t->left = t1;
	t->right = t2;
	return t;
}

HuffTree* GetFinalTree()
{
	//for (int i = 0; i < Huff.size(); i++)
	//{
	//cout << Huff[i]->weight << ' ' << Huff[i]->data << endl;
	//}
	while (Huff.size() > 1)				//Huff内不止一棵树的时候
	{
		sort(Huff.begin(), Huff.end(), SortCmp);	//把最小的树排序到前面，这里不知道为啥默认了把相同权重值，
		//但带子节点的树放在后面了
		HuffTree* t1, * t2;
		t1 = Huff.front();
		Huff.erase(Huff.begin());//erase是消除的意思
		t2 = Huff.front();
		Huff.erase(Huff.begin());
		Huff.push_back(TreeMerge(t1, t2));		//合并最小的两棵树
	}
	return Huff.front();				//返回最后剩余的一棵树，即FinalTree
}

void Encode(HuffTree* t, string s)
{
	//if (isalpha(t->data))
	if (t->data != '#')
		HuffDic.push_back(Pair(t->data, s));		//如果字符不是#，则和相应的01字符串一起存入HuffDic中
	if (t->left)						//如果有左子树
	{
		string sl = s;
		sl.push_back('0');					//左边为1，放入string
		Encode(t->left, sl);				//递归
	}
	if (t->right)					//如果有右子树
	{
		string sr = s;
		sr.push_back('1');					//右边为0，放入string
		Encode(t->right, sr);				//递归
	}
}

void Decode(HuffTree* t, string s)
{
	if (t->left == NULL || s.empty())			//当没有孩子或01字符串完了的时候
	{
		DecodeStr.push_back(t->data);				//为相应的字母，取出放到DecodeStr中
		if (!s.empty())
			Decode(FinalTree, s);			//如果s还不为空的话，继续下一个字符的解码
	}
	else
	{
		char front = s.front();             //有孩子且还有01字符串时，去掉首字符，继续遍历
		s.erase(s.begin());
		//首字符为0向左，首字符为1向右
		Decode((front == '0' ? t->left : t->right), s);
	}

}
//一、begin函数
//
//函数原型 :
//
//iterator begin();
//
//const_iterator begin();
//
//功能：
//
//返回一个当前vector容器中起始元素的迭代器
//三、front函数
//
//函数原型：
//
//reference front();
//
//const_reference front();
//
//功能：
//
//返回当前vector容器中起始元素的引用。
/*
void FileAction()
{
	fstream f("C:\\Users\\12091\\Desktop\\test.txt", ios::out);			//打开文件，若不存在便创建
	if (!f)
	{
		cout << "FileError!! Can't read and write file 'test.txt'!!";	//打不开文件即退出函数
		return;
	}
	for (int i = 0; i < HuffDic.size(); i++)
	{
		f << HuffDic[i].first << "——" << HuffDic[i].second << endl;		//将HuffDic中保存的字母及其编码写入文件
	}
	f << DecodeStr;						//将DecodeStr写入文件
	f.close();
	cout << "结果已保存至——'test.txt'!" << endl;
}
*/
void Results()
{
	sort(HuffDic.begin(), HuffDic.end());					//将小的字符排在前，进行打印
	cout << "哈夫曼编码:" << endl;
	for (int i = 0; i < HuffDic.size(); i++)
	{
		cout << HuffDic[i].first << "——" << HuffDic[i].second << endl;	//输出格式
	}
	cout << "请输入欲编码的字符串:";
	//cin >> test;
	char c[100] = { 0 };
	getchar();
	cin.getline(c, 100);				//getline以输入带空格的字符串
	string test(c, c + 100);
	int sym = 0;
	for (string::iterator it = test.begin(); it != test.end(); it++)
	{
		sym = 0;
		for (vector<Pair>::iterator i = HuffDic.begin(); i != HuffDic.end() & !sym; i++)
			if (i->first == *it) sym = 1;			//在HuffDic中是否有对应的编码
		if (sym)			//如果有
		{
			if (*it == ' ')
				cout << HuffDic.front().second;		//如果是空格
			else if (*it)
				cout << HuffDic[*it - 65 + int(space)].second;			//输出测试数据中每个字母的哈夫曼编码
		}
		//else
		//{
		//	cout << "字符串中有未编码字符，编码停止，你可以检查并再次运行.";
		//	system("pause");
		//	exit(0);
		//}
	}
	if (sym)
		cout << "字符串中有未编码字符，编码结果可能错误";
	cout << endl << "请输入欲解码的01编码: ";
	cin >> test;
	Decode(FinalTree, test);				//输入编码，进行解码
	cout << DecodeStr << endl;
}

int main()
{
	Initial();
	FinalTree = GetFinalTree();
	Encode(FinalTree, "");
	Results();
	//FileAction();
	return 0;
}
/*
请输入数据组数:4
第1组(字母，权值) : A
10
第2组(字母，权值) : B
20
第3组(字母，权值) : C
30
第4组(字母，权值) : D
40
是否输入空格' '的权值？如果是，请输入正整数；如果否，请输入负数 : -1
哈夫曼编码 :
	A——110
	B——111
	C——10
	D——0
	请输入欲编码的字符串 : B
	111
	请输入欲解码的01编码 : 110
	A
	结果已保存至——'test.txt'!

	Project2.exe(进程 11736)已退出，返回代码为: 0。
	按任意键关闭此窗口...
*/
//---------------------------------------------------------------------------------------------------------------
/*请输入数据组数:3
第1组(字母，权值):A
13
第2组(字母，权值):B
24
第3组(字母，权值):C
45
是否输入空格' '的权值？如果是，请输入正整数；如果否，请输入负数:-1
哈夫曼编码:
A——00
B——01
C——1
请输入欲编码的字符串:A
00
请输入欲解码的01编码: 1
C

Project2.exe (进程 16052)已退出，返回代码为: 0。
按任意键关闭此窗口...
*/