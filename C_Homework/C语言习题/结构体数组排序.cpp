#include<stdio.h>
typedef struct Person{
	int no;
	int age;
	int height;
}Person; 
void sort(struct Person *array,int n)
{
    int i,j;
    Person t;
    for(i=0;i<n-1;++i)
    {
        for(j=0;j<n-i-1;++j)
        {
            if(array[j].no>array[j+1].no)
            {
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
            }
            else if(array[j].no==array[j+1].no&&array[j].age>array[j+1].age)
            {
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
            }
            else if(array[j].no==array[j+1].no&&array[j].age==array[j+1].age&&array[j].height>array[j+1].height)
            {
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;
            }
        }
    }
}
int main(void)

{

    int n,i,x;
    struct Person array[100];
    x=scanf("%d",&n);
    if(x!=1)
    printf("error");
    else
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i].no);
        scanf("%d",&array[i].age);
        scanf("%d",&array[i].height);
    }
    sort(array,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",array[i].no);
        printf("%d ",array[i].age);
        printf("%d \n",array[i].height);
    }
    return 0;
}

