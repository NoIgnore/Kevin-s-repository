/*main����д��������ʽ��
struct node
{
int data;
struct node *next;
};
int main(int data[],int n)��
Ȼ��������data������������ɴ�ͷ���ĵ�����ͷָ��header��Ϊmain�����ķ���ֵ,��Ҫ��ͷָ��ת��Ϊint���ء�
����ͷָ�룺struct node * header;��ômain��������ʱ��Ҫreturn (int)header;
headerָ��ָ��ĵ��������ݺ�data��������˳��һ�¡�
����data��ŵ�������1 2 3,��n=3���ҵ�����header��ָ�����ݽ�����������Ϊ1,2,3��
������ִ��������"error"��������NULL��
ͷ��㶨�����£�
struct node
{
int data;
struct node *next;
};*/ 
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main(int data[],int n)
{
	struct node *header=NULL;
	struct node *prev,*current;
	header=(struct node *)malloc(sizeof(struct node));
	header->next=NULL;
	for(int i=0;i<n;i++){
		current=(struct node *)malloc(sizeof(struct node));
		if(!header->next)
		    header->next=current;
		else
		prev->next=current;
		current->next=NULL;
		current->data=data[i];
		prev=current;
	}
	return (int)header;
}
