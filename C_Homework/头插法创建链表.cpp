void createlisthead( linklist *l, int n )
{
	linklist p;
	int i;
	srand(time (0));
	*l = (linklist)malloc(sizeof(Node));
	for(i-0; i<n;i++){
		p=(linklist)malloc(sizeof(Node));//生成新节点 
		p->date= rand()%100+1;//表示从一到一百的随机数
		p->next= (*l)->next;
		(*l)->next= p; 
	} 
}
