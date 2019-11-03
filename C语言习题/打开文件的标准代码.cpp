#include<stdio.h>

int main(int argc, char const *argv[])
{
	FILE*fp=fopen("12.in","r");//文件名12.in//r表示打开文件然后读 
	if(fp){
		int num;
		fscanf(fp, "%d", &num);//读取文件 
	    printf("%d\n",num);
	    fclose(fp);
	} else{
		printf("无法打开文件\n");
	}
	return 0;
} 

