#include<stdio.h>
struct person{
	int no;
	int age;
	int height;
};
int sort(person * array,int n);
int main()
{
	int n;
	scanf("%d" , &n);
    struct person *hhh;
    sort(hhh, n );
	return 0;
} 
int sort(person * array,int n)
{
	struct person p[n+1];
	array = 0;
	int i,j;
	int changed = 0;
	array = p+1;
	if(n<=0){
		printf("error");
	}else {
	
	for(i=1;array<=p+n;array++,i++){
		scanf("%d %d %d", &array->no,&array->age,&array->height);
//		scanf("%d", &array->age);
//		scanf("%d", &array->height);
	if ((array->no <=0) || (array->age <=0) || (array->height <=0)){
		printf("error");
		return 0;
	}
	}
	
	 
	for(i=1;i<=n;i++){
		changed=0;
		for(j=1;j<=n-i;j++){
			if((p[j].no)>(p[j+1].no)){
				p[0] = p[j];
				p[j] = p[j+1];
				p[j+1]=p[0];
				changed=1;
			}else if((p[j].no)==(p[j+1].no)){
				if((p[j].age)>(p[j+1].age)){
					p[0] = p[j];
				    p[j] = p[j+1];
				    p[j+1]=p[0];
				    changed=1;
				}else if((p[j].age)==(p[j+1].age)){
					if((p[j].height)>(p[j+1].height)){
						p[0] = p[j];
				        p[j] = p[j+1];
				        p[j+1]=p[0];
				        changed=1;
					}
				}
			}
		}
		if (changed==0)
			break;
	}
	}
	
	array = p+1;
	for(;array<=p+n;array++){
		printf("%d %d %d\n",array->no,array->age,array->height);
	}
}
