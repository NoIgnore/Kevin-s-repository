#include<stdio.h>
int main()
{
	int i;
	int x[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};//�Զ�����Ϊ3��4�еľ��� 
	for (i=0;i<3;i++){
		printf("%d ",x[i][3-i] );
	}
	return 0;
}
