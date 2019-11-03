#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int Status;
typedef int ElemType;
typedef int Position;
typedef struct
{
	ElemType Data[MaxSize];   // �洢Ԫ�ص�����
	Position Top;       //ջ��ָ��
} SeqStack;
Status Push(SeqStack& L, ElemType e);
Status Pop(SeqStack& L);
Status StackEmpty(SeqStack s);  //�ж�ջs�Ƿ�Ϊ��
Status prinStack(SeqStack& L);
Status convNum(int n, int R);
//���� L �� e �����û�����Ĳ����� L �Ǵ�ͷ����ͷָ�룻 e ������Ԫ�ء�
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
	int n = L.Data[--L.Top];/////////��������ĸŶ
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
	if (L.Top == MaxSize - 1)//�������Ҿ�������Ӧ��д��maxsize
	{
		return 0;
	}
	L.Data[L.Top++] = e;//���Ҫд��ma'x'size�ǲ���Ӧ��д��L.Data[L.Top] = e;��Ȼ���������if֮�ϼ� top++;
	return 1;
}
//�ж�ջs�Ƿ�Ϊ��
Status StackEmpty(SeqStack s)
{
	if (s.Top != 0)
	{
		return 1;
	}
	//printf("The stack is empty ");
	return 0;
}
//����һ��ʮ����������n��һ��Ŀ�����R����<R<10)������ת��ΪR���ơ�
Status convNum(int n, int R)
{
	SeqStack L;
	L.Top = 0;
	while (n != 0)
	{
		//��ÿ�β�������������ջ��
		Push(L, n % R);
		n /= R;
	}
	prinStack(L);
	return 1;
}
int main()
{
	int a, b;
	printf("��������Ҫת�������� ");
	scanf_s("%d", &a);
	printf("ͨ���Ľ��ƣ� ");
	scanf_s("%d", &b);
	convNum(a, b);
	return 0;
}