/*#include <stdio.h>
struct score
{
    int id;
    char name[50];
    float chinese;
    float math;
    float english;
    float ave;
    float sum;
};
#define n 16
int main()
{
    int i,j;
    struct score stu[n+1];
    FILE *fp=NULL;
	fp=fopen("student source.text","rt");
	if(fp==NULL){
		printf("error");
		return -1;
	}
//    FILE *fp;
// 
//    fp=fopen("E:\\stuScores.text","r");
//    if (fp==NULL)
//    {
//        printf("无法打开文件!\n");
//        return 0;
//    }
    for(i=0;i<16;i++)
    {
        fscanf(fp,"%d",&stu[i].id);
        fscanf(fp,"%s",stu[i].name); ///-----------
        fscanf(fp,"%f",&stu[i].chinese);
        fscanf(fp,"%f",&stu[i].math);
        fscanf(fp,"%f",&stu[i].english); 
         
        stu[i].sum=stu[i].chinese+stu[i].id+stu[i].english;
        stu[i].ave=stu[i].sum/3;
        if ( feof(fp) )
            break;
    }
    fclose(fp);
    j=i;
    for(i=0;i<j;i++)
    {
        printf("%d\t",stu[i].id);
        printf("%s\t",stu[i].name);
        printf("%f\t",stu[i].chinese);
        printf("%f\t",stu[i].math);
        printf("%f\t",stu[i].english) ; 
        printf("%f\t%f\n",  stu[i].sum, stu[i].ave );
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

typedef struct contact 
{
	char number[10];
	char name[10];
}CON,*PCON;
int main (void)
{
	int i;
	FILE * fp = NULL;
	struct contact con[4];
	for(i=0;i<4;++i)
	{
		printf("请输入第%d个联系人的姓名\n",i+1);
		scanf("%s",&con[i].name);
		printf("请输入第%d个联系人的电话号码\n",i+1);
		scanf("%s",&con[i].number);
	} 
	fp = fopen ("phone book.txt","w");
	fwrite (con,sizeof(struct contact),4,fp);
	fread (con,sizeof(struct contact),4,fp);
	for(i=0;i<4;++i)
	{
		printf("%s  %s",con[i].name,con[i].number);
	}
	fclose (fp);
	return 0;
}

