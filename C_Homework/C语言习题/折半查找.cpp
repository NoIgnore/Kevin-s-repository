#include<stdio.h>
 
int Binary(int a[], int h, int found)
{
    int low = 0;
    int high = h - 1;
    int mid;
    do{
        mid = (low + high) / 2;
        if(found == a[mid])
            return mid;
        else if(found < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }while(low <= high);
     return -1;
}
int main()
{
	int n;
    int found;
    scanf("%d", &n);
	int a[n];
	if (n==0){
		printf("1");
	}
  if(n>0 && n<100){
    for(int i=0;i<n;i++){
    	if (i<n-1){
    		scanf("%d,", &a[i]);
		} else {
			scanf("%d", &a[i]);
		}
    	
	}
	scanf("%d",&found);
    
    printf("%d\n", Binary(a,n,found)+1);
    //else printf("no");

    return 0;
  }
}//Õâ¸öÂëÍ¼±àÒë´íÎó 
/*#include <stdio.h>
int binsearch(int *sortedSeq, int seqLength, int keyData);
int main()
{
    int array[100], i;
    int location;
    int target;
    int length;
    scanf("%d", &length);
    for(i = 0; i < length; i++)
        scanf("%d,", &array[i]);
    scanf("%d", &target);
    location = binsearch(array, length, target) + 1;
    printf("%d\n", location);
    return 0;
}
int binsearch(int *sortedSeq, int seqLength, int keyData)
{
    int low = 0, mid, high = seqLength - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (keyData < sortedSeq[mid])
        {
            high = mid - 1;
        }
        else if (keyData > sortedSeq[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return 0;
}*/
