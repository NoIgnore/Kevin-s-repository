void createlisthead( linklist *l, int n )
{
	linklist p;
	int i;
	srand(time (0));
	*l = (linklist)malloc(sizeof(Node));
	for(i-0; i<n;i++){
		p=(linklist)malloc(sizeof(Node));//�����½ڵ� 
		p->date= rand()%100+1;//��ʾ��һ��һ�ٵ������
		p->next= (*l)->next;
		(*l)->next= p; 
	} 
}
