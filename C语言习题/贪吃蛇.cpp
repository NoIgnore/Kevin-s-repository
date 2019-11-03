#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//������õ�API 
#include <time.h>//ʳ����� 
#include <conio.h>//������� 

#define mapheight 25 //���ڵ����� 
#define mapwidth 60
#define snakesize 50 //�ߵ������� 
struct {
	//���ȥ��λ������ 
	int x;
	int y; 
}food;//ʳ��Ľṹ��

struct {
	int x[snakesize];
	int y[snakesize];
	int len;//�ߵĳ��� 
	int speed;//�ߵ��ƶ��ٶ� 
}snake; 

//ȫ�ֱ���
int key = 'w';//��ʼ���ƶ��������� 
int changeflag=0;//�ߵı仯�ı��

void drawmap();
void creatfood();
void keydown();// ��������
int snakestatus();//�ߵ�״̬���ж��Ƿ������Ϸ
void gotoxy(int x, int y); //����ƶ� 

int main()
{
//1. ���ù��	gotoxy(20,20);
	drawmap();
	while(1){
		creatfood();
		Sleep(snake.speed);
		keydown();
		if(!snakestatus()){
			break;
		}
		
	}
	gotoxy(mapwidth/2,mapheight/2);
	printf("Game over");
    return 0;
}
void drawmap(){
	//������ķ���  ��ʳ��ķ��� 
	srand((unsigned int)time(NULL));//����������� 
	
	//1.Ȧ��ͼ 
	//Χ����ǽ 
	for(int i = 0; i<= mapheight;i++){
		gotoxy(0, i);
		printf("��");
		gotoxy(mapwidth,i);
		printf("��");
	}
	//Χ����ǽ 
	for(int i = 0; i<= mapwidth;i+=2){
		gotoxy(i,0);
		printf("��");
		gotoxy(i,mapheight);//����һ�����������Ͻ�Ϊԭ�㣬����ΪX����������ΪY������ 
		printf("��");
	}
	//2.����
	snake.len=3;
	snake.speed = 243;
	
	snake.x[0] = mapwidth/2;
	snake.y[0] = mapheight/2;//��ʼʱ��ͷ����Ļ�м� 
	
	gotoxy(snake.x[0],snake.y[0]);//����ͷ 
	printf("��");//һ�� ����2���� 
	
	for (int k= 1;k<snake.len;k++){//��ʣ�µ����� 
	    snake.x[k] = snake.x[k-1]+2;
	    snake.y[k] = snake.y[k-1];
	    gotoxy(snake.x[k],snake.y[k]);
	    printf("��");
	} 
	
	//3.��ʳ�� 
//	  food.x=rand()%(mapwidth-4)+2;
//	  food.y=rand()%(mapheight-2)+1;
	  int j=1;
	    for(;j>0;){
			int flag= 1 ;
			food.x=rand()%(mapwidth-4)+2;
	        food.y=rand()%(mapheight-2)+1;
	        //�������ߵ�����
			for(int k=0;k<snake.len;k++){
				if(snake.x[k]==food.x&&snake.y[k]==food.y){
					flag=0;//������
					break; 
			    }
			} 
			if(food.x%2==0&&flag){
				j=-1;
				break;
			}
		} 
		if(j<0){
		gotoxy(food.x,food.y);
	    printf("��");
		} 
//	  gotoxy(food.x,food.y);
//	  printf("��"); 
}
void creatfood(){
/*	int j=1;
	//while(j=0){
	    if(j>0){
			int flag= 1 ;
			food.x=rand()%(mapwidth-4)+2;
	        food.y=rand()%(mapheight-2)+1;
	        //�������ߵ�����
			for(int k=0;k<snake.len;k++){
				if(snake.x[k]==food.x&&snake.y[k]==food.y){
					flag=0;//������
					break; 
			    }
			} 
			if(food.x%2==0&&flag){
				j=-1;
				break;
			}
		} 
		if(j<0){
		gotoxy(food.x,food.y);
	    printf("��");
		} 
		
//	}*/
	if(snake.x[0]==food.x&&snake.y[0]==food.y){
		srand((unsigned int)time(NULL));
		snake.len++;
		changeflag=1;//�ߵı����һ
		//������ʳ������Ҫ��ż������Ϊ��ͷ������ż��
		while(1){
			int flag= 1 ;
			food.x=rand()%(mapwidth-4)+2;
	        food.y=rand()%(mapheight-2)+1;
	        //�������ߵ�����
			for(int k=0;k<snake.len;k++){
				if(snake.x[k]==food.x&&snake.y[k]==food.y){
					flag=0;//������
					break; 
			    }
			} 
			if(food.x%2==0&&flag){
				break;
			}
		}  
	}
	gotoxy(food.x,food.y);
	printf("��");
}
void keydown(){
	//�ް����Ĵ���
	if(_kbhit()){
		fflush(stdin);
		key=_getch();
	} 
	//���� ,����ײǽ���ǳ��Ȳ��䣬�ƶ������У����һ����ʱ���ڿո񸲸ǣ�Ȼ��ȫ��ǰ�ƣ��������鲢û�иı䣬ֻ�����һ���������� 
	if(!changeflag){
		gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
		printf("  ");
	}
	//������������
	for (int i=snake.len-1;i>0;i--){
		snake.x[i]=snake.x[i-1];
		snake.y[i]=snake.y[i-1];
	}
	switch(key){
		case 'w':
		case 'W':
			snake.y[0]--;
		   break;
		case 's':
		case 'S':
			snake.y[0]++;
		   break;
		case 'A':
		case 'a':
			snake.x[0]-=2;
		   break;
		case 'd':
		case 'D':
			snake.x[0]+=2;
		   break;
	}
	gotoxy(snake.x[0],snake.y[0]);
	printf("��");
	changeflag=0;
	gotoxy(mapheight+2,0);//�ѹ�����ͷ�ƿ� 
}
int snakestatus(){
//1. ���ù��	
    if (snake.x[0]==0 || snake.x[0]==mapwidth-2 || snake.y[0]==0 || snake.y[0]==mapheight-2) 
    {
	   return 0;
	}
    //ͷ����ײ�Լ� 
    for(int k=1;k<snake.len;k++){
    	if(snake.x[0]==snake.x[k]&&snake.y[0]==snake.y[k]){
    		return 0;
		}
	} 
	return 1;
}
void gotoxy(int x, int y)//����ƶ� 
{
	//����win API ȥ���ÿ���̨�Ĺ��λ��
	//1.�ҵ�����̨���������
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//2.���ù��ṹ��
	COORD coord;
	//2.���ù�� 
	coord.X=x;
	coord.Y=y;
	//4.ͬ��������̨ ���ÿ���̨����λ�� 
	SetConsoleCursorPosition(handle,coord); 
} 
