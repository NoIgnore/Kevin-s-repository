#include"acllib.h"
#include"CautoSprite.h"
#include"CusrSprite.h"
#include"Bullet.h"
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std ;
const int winWidth = 480, winHeight = 700,width1=102,height1=126;
const int width2=57,height2=43;
const int width3=5,height3=11;
const int MAXNUM=10;
const int Bulletnumber = 1000;
CautoSprite* autos[MAXNUM] = { NULL };
CusrSprite* usr = NULL;
BulletSprite* bullet[Bulletnumber] = { NULL };
void timerEvent(int id);
void paintSprites();
void keyEvent(int key,int e);
int d=0;
int bullet_num = 0;
int Setup()
{
	initWindow("load_image", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));
	int dx,dy,x,y;
	x=rand()%winWidth;
	y=rand()%winHeight;
	if(x>winWidth-width1)x=winWidth-width1;
	if(y>winHeight-height1)y=winHeight-height1;
	dx=dy=10;
	int x1;
	int y1;
	usr=new CusrSprite("me.jpg",x,y,dx,dy,width1,height1,winWidth,winHeight);
	registerTimerEvent(timerEvent);
	startTimer(0,500);
	startTimer(1,10);
	startTimer(2,300);
	startTimer(3,5);
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
		for(int i=0;i<d;++i)
			if(autos[i]) 
				autos[i]->move();
		for(int i=0;i<bullet_num;++i)
			if(bullet[i])
				bullet[i]->move();
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
	case 2:
		bullet[bullet_num] = new BulletSprite("bullet1.jpg", usr->x + 49, usr->y, 0, 15, width3, height3, winWidth, winHeight);
		if (bullet[bullet_num]) {
			bullet_num++;
		}
		break;
	case 3:
		for(int i=0;i< bullet_num;++i)
		{
			int k = 1;
			if(bullet[i])
			{
				int j=0;
				while(j<d)
				{
					if(autos[j])
					{
						if(bullet[i]->collision(*autos[j]))
						{
							delete autos[j];
							autos[j]=NULL;
							k = 0;
							break;
						}
					}
					j++;
				}
			}
			if(k!=1)
			{
				delete bullet[i];
				bullet[i]=NULL;
			}
		}
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
	for(i=0;i<bullet_num;++i)
	{
		if(bullet[i])
	 	{
	 		bullet[i]->drawScale(width3,height3);
	 	}
	}
	usr->drawScale(width1,height1);
	endPaint();
}
void keyEvent(int key,int e)
{
	int g = 49;
	if(e!=KEY_DOWN){
		return;
	}
	usr->keyMove(key);
	paintSprites();
}