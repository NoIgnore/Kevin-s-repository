#include<stdio.h>
#define true 1
#define false 0
typedef struct node{
int data;
struct node* next;
}Node,*ptrNode,*list;
int JudgeTwoListCrossed(list l1,list l2);
int JudgeTwoListCrossed(list l1,list l2){
	if(l1==NULL || l2==NULL) return false;
	Node *temp1 = l1,*temp2 = l2;
	int len1 = 0,len2 = 0;
	    while(temp1->next != NULL)
	{
		temp1 = temp1->next;
		len1++;
	}
	while(NULL != temp2->next)
	{
		temp2 = temp2->next;
		len2++;
	}

	if(temp1 == temp2)
	{

		if(len1 > len2)                    //���list1 ����list1����len1 - len2��
			while(len1 - len2 >0)
			{
				l1 = l1->next;
				len1--;
			}
		if(len2 > len1)                    //���list2 ����list2����len2 - len1��
			while(len2 - len1 >0)
			{
				l2 = l2->next;
				len2--;
			}
		while(l1 != l2)             //list1��list2һ���ߣ�������ͬ�Ľ����ǽ���
		{
			l1 = l1->next;
			l2 = l2->next;
		}
		
		return true;		
	}
	else
		return false;
} 
/*bool IsIntersect(Node *list1,Node *list2,Node *&value)
{//�ж�����������(�޻�)�Ƿ񽻲�
	value = NULL;
	if(NULL == list1 || NULL == list2)
		return false;

	Node *temp1 = list1,*temp2 = list2;
	int len1 = 0,len2 = 0;

	while(NULL != temp1->next)
	{
		temp1 = temp1->next;
		len1++;
	}
	while(NULL != temp2->next)
	{
		temp2 = temp2->next;
		len2++;
	}

	if(temp1 == temp2)
	{

		if(len1 > len2)                    //���list1 ����list1����len1 - len2��
			while(len1 - len2 >0)
			{
				list1 = list1->next;
				len1--;
			}
		if(len2 > len1)                    //���list2 ����list2����len2 - len1��
			while(len2 - len1 >0)
			{
				list2 = list2->next;
				len2--;
			}
		while(list1 != list2)             //list1��list2һ���ߣ�������ͬ�Ľ����ǽ���
		{
			list1 = list1->next;
			list2 = list2->next;
		}
		value = list1;
		return true;		
	}
	else
		return false;
}*/ 
