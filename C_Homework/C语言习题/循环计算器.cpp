#include<stdio.h>
double jiafa( double a,double b)
{
	return (a+b);
}
double jianfa( double c,double d)
{
	return (c-d);
}
double chenfa( double e,double f)
{
	return (e*f);
}
double chufa( double g,double h)
{
	return g/h;
}
int main()
{
	int d=1;
	char c,k='y',j;
	double a,b;
while(d>0){	
    scanf("%lf %c %lf", &a,&c,&b);
	if(((a<100000 && a>-100000) && (b<100000 && b>-10000)) && ((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='%'))){
	
	if(c=='+'){
		printf("%.2f + %.2f = %.2f\n", a,b,a+b);
	}else if(c=='-'){
		printf("%.2f - %.2f = %.2f\n", a,b,a-b);
	}else if(c=='*'){
		printf("%.2f * %.2f = %.2f\n", a,b,a*b);
	}else if(c=='/' && b!=0){
		printf("%.2f / %.2f = %.2f\n", a,b,a/b);
	}/*else if(c=='%'){
		printf("%.2f % %.2f = %.2f\n", int(a),int (b),int(a)%int(b));
	}*/else {
		d=-1;
		printf("error");
	}
	    getchar();
		scanf("%c", &j);
		k=j;
	if(k=='y' || k=='Y'){
		d=1;
	}else if (k=='n'){
		d=-1;
	}else{
		d=-1;
		printf("error");
	}
	
   }else{
   	d=-1;
   	printf("error");
   }
  }
	return 0;
} 
