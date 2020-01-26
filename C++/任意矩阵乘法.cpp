#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
const int MAXM = 100;
const int MAXN = 100;
class Matrix
{
public:
    int rank;              //矩阵行数
    int column;            //矩阵列数
    Matrix(int r, int c);
    Matrix();
    Matrix(Matrix& a);
    ~Matrix();
    int M[MAXM][MAXN] = { 0 };
    int GetRank();        //获取（返回）矩阵行数
    int GetColumn();      //获取（返回）矩阵列数
    void ShowMatrix();    //屏幕上输出矩阵
    Matrix operator+(const Matrix& offset);//矩阵相加
    Matrix operator-(const Matrix& offset);//矩阵相减
    Matrix operator*(const Matrix& offset);//矩阵相乘
};

Matrix::Matrix(int r, int c)
{
    this->rank = r;
    this->column = c;
}

Matrix::Matrix()
{
    this->rank = 0;
    this->column = 0;
}

Matrix::Matrix(Matrix& a)
{
    this->rank = a.rank;
    this->column = a.column;
    for (int i = 0; i < a.rank; i++)
    {
        for (int j = 0; j < a.column; j++)
        {
            this->M[i][j] = a.M[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < this->rank; i++)
    {
        for (int j = 0; j < this->column; j++)
        {
            this->M[i][j] = 0;
        }
    }
    this->rank = 0;
    this->column = 0;
}

int Matrix::GetRank()
{
    return this->rank;
}

int Matrix::GetColumn()
{
    return this->column;
}

void Matrix::ShowMatrix()
{
    for (int i = 0; i < rank; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (j < column - 1)
            {
                cout << M[i][j] << " ";
            }
            else
            {
                cout << M[i][j] << endl;
            }
        }

    }
}

Matrix Matrix::operator+(const Matrix& offset)
{
    Matrix tmp;
    tmp.rank = rank;
    tmp.column = column;
    for (int i = 0; i < tmp.rank; i++)
    {
        for (int j = 0; j < tmp.column; j++)
        {
            tmp.M[i][j] = M[i][j] + offset.M[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator-(const Matrix& offset)
{
    Matrix tmp;
    tmp.rank = rank;
    tmp.column = column;
    for (int i = 0; i < tmp.rank; i++)
    {
        for (int j = 0; j < tmp.column; j++)
        {
            tmp.M[i][j] = M[i][j] - offset.M[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator*(const Matrix& offset)
{
    Matrix tmp;
    tmp.rank = rank;
    tmp.column = offset.column;
    int middle = offset.rank;
    tmp.M[MAXM][MAXN] = { 0 };
    for (int i = 0; i < tmp.rank; i++)
    {
        for (int j = 0; j < tmp.column; j++)
        {
            for (int v = 0; v < middle; v++)
            {
                tmp.M[i][j] += M[i][v] * offset.M[v][j];
            }
        }
    }
    return tmp;
}

int main()
{
    Matrix A(2, 3);
    Matrix B(3, 2);
    Matrix C;
    A.M[0][0] = 1;//1 2 1
    A.M[0][1] = 2;//1 3 0
    A.M[0][2] = 1;
    A.M[1][0] = 1;
    A.M[1][1] = 3;
    A.M[1][2] = 0;
    B.M[0][0] = 1;//1 2
    B.M[0][1] = 2;//1 1
    B.M[1][0] = 1;//0 3
    B.M[1][1] = 1;
    B.M[2][0] = 0;
    B.M[2][1] = 3;
    /*A.ShowMatrix();
    B.ShowMatrix();*/
    C = A * B;
    C.ShowMatrix();
    return 0;
}