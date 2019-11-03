#include<stdio.h>
#include<string.h>
int main()
{
	const int s=20;
	int n;
	char b[s];
	scanf("%s", &b);
	n=strlen(b);
	//int i;
//	for(i=0;i<n;i++){
//		if(n!=0 && ((b[i]>='A'&&b[i]<='Z') || (b[i]>='a'&&b[i]<='z'))){
////			int j;
////			for(j=0;j<n;j++){
////				b[j] += 4;
//            if ( b[i]>='a' && b[i]<='z' ) {
//            	int j;
//			for(j=0;j<n;j++){
//	              b[i]=(b[i]-'a'+4)%26+'a';
//		    }
//		    }
//		    else if ( b[i]>='A' && b[i]<='Z' ) {
//		    			int j;
//			for(j=0;j<n;j++){
//	              b[i]=(b[i]-'A'+4)%26+'A';
//		    }
//	                       
//				}
//			 
//			printf("%s\n",b);
//			break;
//		}else{
//			printf("error\n");
//			break;
//		}
//	}
//vwxyza VWXYZA
      int i=0;
	  if (n==0 || ((b[i]<'A' || b[i]>'Z') && (b[i]<'a' || b[i]>'z')) ){
      	printf("error\n");
		}
    else{
	 while ( b[i]!=0 ) {
    if ( b[i]>='a' && b[i]<='z' ) {
	    b[i]=(b[i]-'a'+4)%26+'a';
	    i++;
    }else if ( b[i]>='A' && b[i]<='Z' ) {
	    b[i]=(b[i]-'A'+4)%26+'A';
        i++;
	}//else if (n=0 || b[i]<='A' && b[i]>='Z' ||  b[i]<='a' && b[i]>='z') {
//	{	printf("error\n");
//		break;
//	}
	}
	printf("%s\n",b);
	}
    
   
    return 0;
 } 
