#include"acllib.h"
#include"CautoSprite.h"
#include"CusrSprite.h"
#include<stdlib.h>
#include<time.h>

const int winWidth = 480, winHeight = 700,width1=102,height1=126;
const int width2=57,height2=43;
const int MAXNUM=10;
CautoSprite *autos[MAXNUM]={NULL};
CusrSprite *usr=NULL;
CusrSprite *nubaa=NULL;
void timerEvent(int id);
void paintSprites();
void keyEvent(int key,int e);
int d=0;
int Setup()
{
	initWindow("load_image", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));
	int x,y,dx,dy;
	x=rand()%winWidth;
	y=rand()%winHeight;
	if(x>winWidth-width1)x=winWidth-width1;
	if(y>winHeight-height1)y=winHeight-height1;
	dx=dy=10;
	//int mewidth = 102;
	//int meheight = 126;
	//int enemywidth = 57;
	//int enemyheigth = 43;
	usr=new CusrSprite("me.jpg",x,y,dx,dy,width1,height1,winWidth,winHeight);
	registerTimerEvent(timerEvent);
	startTimer(0,100);
	startTimer(1,10);
	registerKeyboardEvent(keyEvent);
	paintSprites();
	return 0;
}
void timerEvent(int id)
{
	switch(id)
	{
	case 0:
		if(d>=MAXNUM) return;
		int x,y,dx,dy;
		x=rand()%winWidth;
		y = 1 ;
		if(x>winWidth-width2)x=winWidth-width2;
		if(y>winHeight-height2)y=winHeight-height2;
		dx=rand()%5+1;
		dy=rand()%5+1;
		autos[d]=new CautoSprite("enemy1.jpg",x,y,dx,dy,width2,height2,winWidth,winHeight);
		if(autos[d]) 
			d++;
		break;
	case 1:
		for(int i=0;i<d;++i){
			if(autos[i]){
				autos[i]->move();
			}
		}
		for(int i=0;i<d;++i)
		{
			if(autos[i])
			{
				if(usr->collision(*autos[i]))
				{
					delete autos[i];
					autos[i]=NULL;
				}
			}
		}

		paintSprites();

		break;
	}
}
void paintSprites()
{
	int i;
	beginPaint();
	clearDevice();
	for(i=0;i<d;++i)
	{
		if(autos[i])
		{
			autos[i]->drawScale(width2,height2);
		}
	}
	usr->drawScale(width1,height1);
	endPaint();
}
void keyEvent(int key,int e)
{
	if(e!=KEY_DOWN)return;
	usr->keyMove(key);
	
	paintSprites();
}