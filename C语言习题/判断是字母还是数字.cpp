#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
#include <conio.h>
int main()
{    int i,m,b,r;
//     double x, n;
//	 double A =0;
//     r=scanf("%lf%lf", &x ,&n);
    char ch;  //指定字符；
    ch = getchar();
    if (ch >= '0' && ch <= '9')
//	 if (r==1 && n>0)
	 {
	 	 r=1;
		 printf("h");
	 }
	 else{ 
		 printf("error");
		 } 
//	 system("pause");
	 return 0;
}
//# include <stdio.h>
//# include <conio.h>       //引用头文件，Conio=Console Input/Output 简称Coni(input)o(output)
//int main(void)
//{
//    char ch;  //指定字符；
//    printf("请输入您想要判断的任意字符:"); //输出需求
//    ch = getchar(); //ch相当于一个字符变量，现在需要Get（得到）这个字符变量的内容
//    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') //判断：如果ch字符的值大于a,并且小于z；ch字符的值大于A,并且小于Z
//        printf("您输入的是字母！\n"); //输出是字母
//    else if (ch >= '0' && ch <= '9') //另外如果ch字符的值大于0并且小于9的话
//        printf("您输入的是数字！\n"); //输出是数字
//    else //否则
//        printf("你输入的是其他的字符！\n"); //输出是其他字符
//    return 0; //程序结束
//}
