#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int id;
	char name[50];
	float chinese;
	float math;
	float english;
	float sum;
}student;
int ReadStuInfoFromFile(char *name, student **stu);
int NoPass(student stu[], int n, student **noPassStudent, int *m);
int Pass(student stu[], int n, student **PassStudent, int *m);
int SortStudents(student stu[], int n);
int PrintStudents(student stu[], int n);
int SearchStudent(student stu[], int n, int id,int *rank, student *rstu);
int ReadStuInfoFromFile(char *name, student **stu){
	FILE *fp=fopen("name","r");
	if(fp==NULL) return 0;
    int count;
    student *s=*stu;
    while((fread(s, sizeof(student), 1, fp))!=EOF){
		s->sum=s->chinese+s->math+s->english;
		s++;
		count++;
	} 
    fclose(fp);
    return count;
} 
int NoPass(student stu[], int n, student **noPassStudent, int *m){
	student * no=*noPassStudent;
	if(stu==NULL||n<1)
	return -1;
	for(int i=0;i<n;i++){
		if(stu[i].sum/3<60){
			no=&stu[i];
			*m++;
			no++;
		}
	}
	* noPassStudent= no; 
	return 0;
}
int Pass(student stu[], int n, student **PassStudent, int *m){
	student * pass=*PassStudent;
	if(stu==NULL||n<1)
	return -1;
	for(int i=0;i<n;i++){
		if(stu[i].sum/3>=60){
			pass=&stu[i];
			*m++;
			pass++;
		}
	}
	*PassStudent=pass;
	return 0;
}
int SortStudents(student stu[], int n){
	if(stu==NULL||n<1)
	return -1;
	int i=0,j=0;
	for(j=0;j<n-1;j++)
	for(i=0;i<n-j-1;i++){
		student x=stu[i];
		if(stu[i+1].sum>stu[i].sum)
		{
			x=stu[i+1];
			stu[i+1]=stu[i];
			stu[i]=x;
		}
	}
	return 0;
}
int SearchStudent(student stu[], int n, int id,int *rank, student *rstu){
	rstu=NULL;
	for(int i=0;i<n;i++){
		if(stu[i].id==id){
			*rank=i+1;
			rstu=&stu[i];
		}
	}
	if(rstu==NULL||n<1)
	return -1;
	else
	return 0;
}
