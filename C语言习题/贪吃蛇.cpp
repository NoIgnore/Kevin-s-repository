#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//光标设置的API 
#include <time.h>//食物随机 
#include <conio.h>//按键监控 

#define mapheight 25 //窗口的属性 
#define mapwidth 60
#define snakesize 50 //蛇的最大节数 
struct {
	//如何去定位：坐标 
	int x;
	int y; 
}food;//食物的结构体

struct {
	int x[snakesize];
	int y[snakesize];
	int len;//蛇的长度 
	int speed;//蛇的移动速度 
}snake; 

//全局变量
int key = 'w';//初始化移动方向向上 
int changeflag=0;//蛇的变化的标记

void drawmap();
void creatfood();
void keydown();// 按键操作
int snakestatus();//蛇的状态：判断是否结束游戏
void gotoxy(int x, int y); //光标移动 

int main()
{
//1. 设置光标	gotoxy(20,20);
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
	//■蛇身的符号  ⊙食物的符号 
	srand((unsigned int)time(NULL));//随机函数种子 
	
	//1.圈地图 
	//围左右墙 
	for(int i = 0; i<= mapheight;i++){
		gotoxy(0, i);
		printf("■");
		gotoxy(mapwidth,i);
		printf("■");
	}
	//围上下墙 
	for(int i = 0; i<= mapwidth;i+=2){
		gotoxy(i,0);
		printf("■");
		gotoxy(i,mapheight);//想象一个坐标轴左上角为原点，向下为X轴正向，向右为Y轴正向 
		printf("■");
	}
	//2.画蛇
	snake.len=3;
	snake.speed = 243;
	
	snake.x[0] = mapwidth/2;
	snake.y[0] = mapheight/2;//开始时蛇头在屏幕中间 
	
	gotoxy(snake.x[0],snake.y[0]);//画蛇头 
	printf("■");//一节 ■是2长度 
	
	for (int k= 1;k<snake.len;k++){//画剩下的身体 
	    snake.x[k] = snake.x[k-1]+2;
	    snake.y[k] = snake.y[k-1];
	    gotoxy(snake.x[k],snake.y[k]);
	    printf("■");
	} 
	
	//3.画食物 
//	  food.x=rand()%(mapwidth-4)+2;
//	  food.y=rand()%(mapheight-2)+1;
	  int j=1;
	    for(;j>0;){
			int flag= 1 ;
			food.x=rand()%(mapwidth-4)+2;
	        food.y=rand()%(mapheight-2)+1;
	        //不能在蛇的身上
			for(int k=0;k<snake.len;k++){
				if(snake.x[k]==food.x&&snake.y[k]==food.y){
					flag=0;//不合适
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
	    printf("⊙");
		} 
//	  gotoxy(food.x,food.y);
//	  printf("⊙"); 
}
void creatfood(){
/*	int j=1;
	//while(j=0){
	    if(j>0){
			int flag= 1 ;
			food.x=rand()%(mapwidth-4)+2;
	        food.y=rand()%(mapheight-2)+1;
	        //不能在蛇的身上
			for(int k=0;k<snake.len;k++){
				if(snake.x[k]==food.x&&snake.y[k]==food.y){
					flag=0;//不合适
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
	    printf("⊙");
		} 
		
//	}*/
	if(snake.x[0]==food.x&&snake.y[0]==food.y){
		srand((unsigned int)time(NULL));
		snake.len++;
		changeflag=1;//蛇的标记是一
		//产生的食物坐标要是偶数，因为蛇头坐标是偶数
		while(1){
			int flag= 1 ;
			food.x=rand()%(mapwidth-4)+2;
	        food.y=rand()%(mapheight-2)+1;
	        //不能在蛇的身上
			for(int k=0;k<snake.len;k++){
				if(snake.x[k]==food.x&&snake.y[k]==food.y){
					flag=0;//不合适
					break; 
			    }
			} 
			if(food.x%2==0&&flag){
				break;
			}
		}  
	}
	gotoxy(food.x,food.y);
	printf("⊙");
}
void keydown(){
	//无按键的处理
	if(_kbhit()){
		fflush(stdin);
		key=_getch();
	} 
	//擦除 ,不是撞墙，是长度不变，移动过程中，最后一节暂时两节空格覆盖，然后全部前移，三个方块并没有改变，只是最后一个被覆盖了 
	if(!changeflag){
		gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
		printf("  ");
	}
	//后面的蛇身节数
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
	printf("■");
	changeflag=0;
	gotoxy(mapheight+2,0);//把光标从蛇头移开 
}
int snakestatus(){
//1. 设置光标	
    if (snake.x[0]==0 || snake.x[0]==mapwidth-2 || snake.y[0]==0 || snake.y[0]==mapheight-2) 
    {
	   return 0;
	}
    //头不能撞自己 
    for(int k=1;k<snake.len;k++){
    	if(snake.x[0]==snake.x[k]&&snake.y[0]==snake.y[k]){
    		return 0;
		}
	} 
	return 1;
}
void gotoxy(int x, int y)//光标移动 
{
	//调用win API 去设置控制台的光标位置
	//1.找到控制台的这个窗口
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//2.设置光标结构体
	COORD coord;
	//2.设置光标 
	coord.X=x;
	coord.Y=y;
	//4.同步到控制台 设置控制台光标的位置 
	SetConsoleCursorPosition(handle,coord); 
} 
