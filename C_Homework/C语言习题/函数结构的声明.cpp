#include <stdio.h>
struct date{
		int month;
		int day;
		int year;
};
int main(int argc, char const *argv[])
{
	
	struct date today;
	today=(struct date){03,23,2019} ;//����ȡ���������� 
//	today.month=03;
//	today.day=23;
//	today.year=2019;
	printf("Today's date is %i/%i/%i.\n",
	    today.year,today.month,today.day);
    return 0;
}
   
