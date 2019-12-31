#include<iostream>
#include<cstring>

using namespace std;

int subFirstMatch(char *str, char *substr) 
{
	int index = -1;
	//。。。。
	int L1=strlen(str),L2=strlen(substr);
	int i,j;
	for(i=0;i<=L1-L2;i++) 
	{ 
		for(j=0;j<L2;j++) 
		{ 
			if(str[i+j]!=substr[j])break; 
		} 
		if(j==L2)
		{
			index=i;
			break;
		}
	}
	//。。。。
	std::cout << "first match=" << index;
	return index;
}

int main(void)
{
	char *str = "hell world hello you hello";
	char *substr = "lo";
	char *substr1 = "word";
	int type;
	cin >> type;
	if(type == 1)
	{
		subFirstMatch(str, substr);
	}
	else 
	{
		subFirstMatch(str, substr1);
	}
	
	return 0;
}
