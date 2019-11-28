#include<iostream>
using namespace std;
int minvalue(int n, int** m, int* p) {
    for (int i = 0; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (int r = 2; r <= n; r++) //r为当前计算的链长（子问题规模）  
    {
        for (int i = 1; i <= n - r + 1; i++)//n-r+1为最后一个r链的前边界  
        {
            int j = i + r - 1;//计算前边界为n-r+1，链长为r的链的后边界  

            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//将链ij划分为A(i) * ( A[i+1:j] ) 
            for (int k = i + 1; k < j; k++)
            {
                //将链ij划分为( A[i:k] )* (A[k+1:j])   
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                }
            }
        }
    }
    return m[1][n];
}
/*详细解释如下
     当r=2时，先迭代计算出：

     m[1:2]=m[1:1]+m[2:2}+p[0]*p[1]*p[2]；

     m[2:3]=m[2:2]+m[3:3]+p[1]*p[2]*p[3];

     m[3:4]=m[3:3]+m[4][4]+p[2]*p[3]*p[4];

     m[4:5]=m[4:4]+m[5][5]+p[3]*p[4]*p[5];

     m[5:6]=m[5][5]+m[6][6]+p[4]*p[5]*p[6]的值；

     当R=3时，迭代计算出：

     m[1:3]=min(m[1:1]+m[2:3]+p[0]*p[1]*p[3],m[1:2]+m[3:3]+p[0]*p[2]*p[3]);

     m[2:4]=min(m[2:2]+m[3:4]+p[1]*p[2]*p[4],m[2:3]+m[4:4]+p[1]*p[3]*p[4]);

     m[4:6]=min(m[4:4]+m[5:6]+p[3]*p[4]*p[6],m[4:5]+m[6:6]+p[3]*p[5]*p[6]);
*/
int main() {
    int n, o, g;
    cout << "请输入矩阵的个数n" << endl;
    cin >> n;
    cout << "请输入n+1个值 " << endl;
    int* p = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        cin >> p[i];
    }
    int** m = new int* [n + 1];
    for (int i = 0; i <= n; i++)
    {
        m[i] = new int[n + 1];
    }
    cout << minvalue(n, m, p);
}
/*{50,10,40,30,5};
矩阵的最少计算次数为：10500
矩阵最优计算次序为：
Multiply A3,3 and A4,4
Multiply A2,2 and A3,4
Multiply A1,1 and A2,4
----------------------解释起来就是(A(B(CD)))
C++项目.exe (进程 15948)已退出，返回代码为: 0。
按任意键关闭此窗口...
*/