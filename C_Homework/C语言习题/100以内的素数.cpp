#include<stdio.h>
#include<math.h>
int main()
{
//	int i;
//	int isPrime=1;
//	int k;
//	for(i=3;i<100;i++){
//		for ( k=2;k<i; k++){//�� kд��<=��n/2���Ϳ��Բ������״�����hhhh 
//			if (i%k==0){
//				isPrime=0;
//				break; 
//			}
//			
//		}
//	
//		if (isPrime==1){
//			printf("%d\n",i);
//		}
//		}
////	} k<sqrt((float)i)
    int i;
	
	for( i=2; i<=200; i++){
		int isPrime = 1;//isprimeҪд������Ϊѭ��һ�ξ����¸�ֵ��1һ�Σ����� 
		int k;
		for ( k=2; k<i; k++){
			if (i%k==0){
				isPrime = 0;
				break;
			}
		}
		//�ж�i�Ƿ�Ϊ����
		if (isPrime==1){
			printf("%d,",i);
		} 
	}
	
	return 0;
} 
