#include<stdio.h>

int main(int argc, char const *argv[])
{
	FILE*fp=fopen("12.in","r");//�ļ���12.in//r��ʾ���ļ�Ȼ��� 
	if(fp){
		int num;
		fscanf(fp, "%d", &num);//��ȡ�ļ� 
	    printf("%d\n",num);
	    fclose(fp);
	} else{
		printf("�޷����ļ�\n");
	}
	return 0;
} 

