#include <iostream> 
using namespace std;

const int L = 5;

int LookupChain(int i, int j, int** m, int** s, int* p);
int MemoizedMatrixChain(int n, int** m, int** s, int* p);

void Traceback(int i, int j, int** s);//构造最优解

int MemoizedMatrixChain(int n, int** m, int** s, int* p)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            m[i][j] = 0;
        }
    }
    return LookupChain(1, n, m, s, p);//1~n表示第1个矩阵计算到第n个
}

int LookupChain(int i, int j, int** m, int** s, int* p)
{
    if (m[i][j] > 0)
    {
        return m[i][j];
    }
    if (i == j)
    {
        return 0;
    }

    int u = LookupChain(i, i, m, s, p) + LookupChain(i + 1, j, m, s, p) + p[i - 1] * p[i] * p[j];
    s[i][j] = i;
    for (int k = i + 1; k < j; k++)
    {
        int t = LookupChain(i, k, m, s, p) + LookupChain(k + 1, j, m, s, p) + p[i - 1] * p[k] * p[j];
        if (t < u)
        {
            u = t;
            s[i][j] = k;
        }
    }
    m[i][j] = u;
    return u;
}

void Traceback(int i, int j, int** s)
{
    if (i == j) return;
    Traceback(i, s[i][j], s);
    Traceback(s[i][j] + 1, j, s);
    cout << "Multiply A" << i << "," << s[i][j];
    cout << " and A" << (s[i][j] + 1) << "," << j << endl;
}
int main()
{
    //int p[L] = { 30,35,15,5,10,20,25 };
    int p[L] = {50,10,40,30,5};
    int** s = new int* [L];
    int** m = new int* [L];
    for (int i = 0; i < L; i++)
    {
        s[i] = new int[L];//二维数组：每一行都分配七列
        m[i] = new int[L];//二维数组：每一行都分配七列
    }

    cout << "矩阵的最少计算次数为：" << MemoizedMatrixChain(4, m, s, p) << endl;
    cout << "矩阵最优计算次序为：" << endl;
    Traceback(1, 4, s);
    return 0;
}
/*矩阵的最少计算次数为：10500
矩阵最优计算次序为：
Multiply A3,3 and A4,4
Multiply A2,2 and A3,4
Multiply A1,1 and A2,4
----------------------解释起来就是(A(B(CD)))
C++项目.exe (进程 15948)已退出，返回代码为: 0。
按任意键关闭此窗口...
*/