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
    int i;  //比较的轮数
    int j;  //每轮比较的次数
    int buf;//交换数据时用于存放中间数据
	//*a[0]是int型, 占4字节, 所以总的字节数除以4等于元素的个数*
    for (i=0; i<k-1; i++) {                   //比较n-1轮
//        changed = 0;
		for (j=0; j<k-i-1; j++){               //每轮比较n-1-i次,
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
    free(a);       //释放内存
    return 0;
}
