#include <stdio.h>
#include <stdlib.h>
int main()
{
    int k;
    scanf("%d", &k);
    int * a;
	a = (int *)malloc(k * sizeof(int));
    for(int h=0;h<k;h++){
    	scanf("%d", &a[h] );
	}
    int changed;
    int i;  //�Ƚϵ�����
    int j;  //ÿ�ֱȽϵĴ���
    int buf;//��������ʱ���ڴ���м�����
	//*a[0]��int��, ռ4�ֽ�, �����ܵ��ֽ�������4����Ԫ�صĸ���*
    for (i=0; i<k-1; i++) {                   //�Ƚ�n-1��
//        changed = 0;
		for (j=0; j<k-i-1; j++){               //ÿ�ֱȽ�n-1-i��,
            if (a[j] > a[j+1]){
                buf = a[j];
                a[j] = a[j+1];
                a[j+1] = buf;
//                changed=1;
            }
//            if(changed==0){
//            	break;
//			}   
        }  
    }
    int t;
    for (t=0; t<k; t++)
    {
        printf("%d", a[t]);
        if (t<k-1){
        	printf(",");
		}
    }
    free(a);       //�ͷ��ڴ�
    return 0;
}
