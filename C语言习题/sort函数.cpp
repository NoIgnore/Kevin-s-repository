#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main ()
{
	//int i;
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	for(int i=0;i<10;i++)
    printf("%d \n", a[i]);
	sort(a,a+10);
	for (int i=0;i<10;i++)
	printf("%d ", a[i]);
	return 0;
}
//int comp(const void*a,const void*b)//�������Ƚϵĺ�����
//{
//    return *(int*)a-*(int*)b;
//}
//int main()
//{
//    int a[10] = {2,4,1,5,5,3,7,4,1,5};//��������顣
//    int i;
//    qsort(a,n,sizeof(int),comp);//����qsort����
//    for(i=0;i<10;i++)//�������������
//    {
//        printf("%d\t",array[i]);
//    }
//    return 0;
//} 
