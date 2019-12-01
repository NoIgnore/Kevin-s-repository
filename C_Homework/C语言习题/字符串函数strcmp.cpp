#include<stdio.h>
//#include<string.h>
int mycmp(const char*s1,const char*s2)
{
	int idx =0;
//	while(s1[idx]==s2[idx]&& s1[idx]!='\0'){
//		//if (s1[idx] != s2[idx]){
//		//	break;
//		//}else if ( s1[idx]=='\0'){
//		//	break;
//		//}
//		idx++;    //这是使用数组的 
    while (*s1==*s2 && *s1 != '\0'){
    	s1++;
    	s2++;
	} 
	return *s1 - *s2;//用指针计算的 
	//return s1[idx]- s2[idx];
}
int main(int argc , char const *argv[])
{
	char s1[] = "abc";
	char s2[] = "Abc";
	printf("%d\n", mycmp(s1,s2));
	printf("%d\n", 'a'-'A');
	return 0;
} 
