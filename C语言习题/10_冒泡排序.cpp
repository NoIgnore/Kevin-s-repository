#include<stdio.h>
int main()
{
	//int n;
	int a[10];
	int b;
	//scanf("%d",&n);
    for(b=0;b<10;b++){
    	scanf("%d",&a[b]);
	}
    int n;  //�������a��Ԫ�صĸ���
    int i;  //�Ƚϵ�����
    int j;  //ÿ�ֱȽϵĴ���
    int buf;//��������ʱ���ڴ���м�����
    n = sizeof(a) / sizeof(a[0]);             //*a[0]��int��, ռ4�ֽ�, �����ܵ��ֽ�������4����Ԫ�صĸ���*
    for (i=0; i<9; ++i) {                   //�Ƚ�n-1��
        for (j=0; j<9-i; ++j){               //ÿ�ֱȽ�n-1-i��,
                if (a[j] > a[j+1]){
                buf = a[j];
                a[j] = a[j+1];
                a[j+1] = buf;
            }
        }  
    }
    for (i=0; i<10; ++i)
    {
        printf("%d", a[i]);
        if (i<9){
        	printf(",");
		}
    }
	return 0;
 } 
