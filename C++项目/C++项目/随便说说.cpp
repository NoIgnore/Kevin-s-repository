#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int Status;
typedef int ElemType;
typedef int Position;
typedef struct
{
	ElemType Data[MaxSize];   // 存储元素的数组
	Position Top;       //栈顶指针
} SeqStack;
Status Push(SeqStack& L, ElemType e);
Status Pop(SeqStack& L);
Status StackEmpty(SeqStack s);  //判断栈s是否为空
Status prinStack(SeqStack& L);
Status convNum(int n, int R);
//其中 L 和 e 都是用户传入的参数。 L 是带头结点的头指针； e 是数据元素。
Status prinStack(SeqStack& L)
{
	while (StackEmpty(L))
	{
		Pop(L);
	}
	return 1;
}
/*void work1()
{
	SeqStack L;
	L.Top = 0;
	Push(L, 1);
	Push(L, 0);
	prinStack(L);
	//8->2:1 0 0 0
}*/
Status Pop(SeqStack& L)
{
	if (L.Top == 0)
	{
		return 0;
	}
	int n = L.Data[--L.Top];/////////新增的字母哦
	if (n > 10) {
			char c;
			c = n - 10 + 'A';
			printf("%c ", c);
			return 1;
	}else{
		printf("%d ", n);
		return 1;
	}
}
Status Push(SeqStack& L, ElemType e)
{
	if (L.Top == MaxSize - 1)//讲道理我觉得这里应该写成maxsize
	{
		return 0;
	}
	L.Data[L.Top++] = e;//如果要写成ma'x'size是不是应该写成L.Data[L.Top] = e;，然后在上面的if之上加 top++;
	return 1;
}
//判断栈s是否为空
Status StackEmpty(SeqStack s)
{
	if (s.Top != 0)
	{
		return 1;
	}
	//printf("The stack is empty ");
	return 0;
}
//输入一个十进制正整数n和一个目标进制R（１<R<10)，将ｎ转换为R进制。
Status convNum(int n, int R)
{
	SeqStack L;
	L.Top = 0;
	while (n != 0)
	{
		//将每次产生的余数防入栈低
		Push(L, n % R);
		n /= R;
	}
	prinStack(L);
	return 1;
}
int main()
{
	int a, b;
	printf("请输入需要转化的数： ");
	scanf_s("%d", &a);
	printf("通过的进制： ");
	scanf_s("%d", &b);
	convNum(a, b);
	return 0;
}