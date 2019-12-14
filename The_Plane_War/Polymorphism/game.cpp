#include"acllib.h"
#include"Bullet.h"
#include"UsrSprite.h"
#include "AutoSprite.h"
#include"Enemy2Sprite.h"
#include<time.h>
#include<stdio.h>

using namespace std ;

const int winWidth = 480, winHeight = 700,width1=102,height1=126;
const int width2=57,height2=43;
const int width3=5,height3=11;
const int width4=55,height4=60;
const int Bulletnumber = 1000;
const int maxNum = 10;

CAutoSprite *autosprite[maxNum] = { 0 };
BulletSprite* bullet[Bulletnumber] = { 0 };
CUsrSprite *usr = NULL;

int usrWidth = width1, usrHeight = height1;
int autoWidth = width2, autoHeight = height2;

ACL_Image imgenemy1,imgusr,imgenemy2,imgbullet;
rect winRect;

void timerEvent(int id);
void createSprite(CUsrSprite **usr);
void keyEvent(int key, int event);
void paint();
int nowNum = 0;
int bullet_num = 0;

int Setup()
{
	winRect.x = DEFAULT;
	winRect.y = DEFAULT;
	winRect.width = winWidth;
	winRect.height = winHeight;
	initWindow("Load_image", DEFAULT, DEFAULT, winWidth, winHeight);
	srand((unsigned)time(NULL));

	loadImage("enemy1.jpg", &imgenemy1);
	loadImage("me.jpg", &imgusr);
	loadImage("enemy2.jpg", &imgenemy2);
	loadImage("bullet1.jpg", &imgbullet);

	createSprite(&usr);
	registerTimerEvent(timerEvent);
	registerKeyboardEvent(keyEvent);
	startTimer(0,500);
	startTimer(1,10);
	startTimer(2,300);
	startTimer(3,5);
	startTimer(4,300);
	paint();
	return 0;
}

void timerEvent(int id)
{
	switch (id)
	{
		int t;
		int dx,dy,x,y;
		case 0:
			if(nowNum>=maxNum) return;
			x = rand() % winWidth - autoWidth;
			if (x < 0)x = 0;
			 y = 1;
			dx = rand() % 5 + 1;
			dy = rand() % 5 + 1;
			 t = rand() % 100;
			if(t<50)
				autosprite[nowNum] = new CAutoSprite(x, y, autoWidth, autoHeight, dx, dy, &imgenemy1, winRect,1);
			else
				autosprite[nowNum] = new Enemy2Sprite(x, y, width4, height4, dx, dy, &imgenemy2, winRect,5);
			if(autosprite[nowNum]){
				nowNum++;
			}
			break;
		case 1:
			for (int i = 0; i < nowNum; ++i)
			{
				if (autosprite[i])
				{
					rect ur = usr->getRect();
					autosprite[i]->move(ur);
				}
			}

			for(int k=0;k<bullet_num;++k)
			{
				if(bullet[k])
				{
					rect ur = usr->getRect();
					bullet[k]->move(ur);
				}
			}
			//先不设定usr和敌机的碰撞
			/*for (int i = 0; i < nowNum; ++i)
			{
				if (autosprite[i])
				{
					if (usr->collision(autosprite[i]->getRect()))
					{
						int s = autosprite[i]->getScore();
						if (usr)usr->addScore(s);
						delete(autosprite[i]);
						autosprite[i] = NULL;
					}
				}
			}*/
			paint();
			break;

		case 2:
			bullet[bullet_num] = new BulletSprite(usr->x + 49, usr->y, width3, height3, 0, 15, &imgbullet, winRect);
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
					while(j<nowNum)
					{
						if(autosprite[j])
						{
							if(bullet[i]->collision(autosprite[j]->getRect()))
							{
								int s = autosprite[j]->getScore();
								if (usr)usr->addScore(s);
								delete(autosprite[j]);
								autosprite[j] = NULL;
								k = 0;
								break;
							}
						}
						j++;
					}
				}
				if(k!=1)
				{
					delete(bullet[i]);
					bullet[i]=NULL;
				}
			}
			break;
		case 4:
			for(int i=0;i< bullet_num;++i)
			{
				int k = 1;
				if(bullet[i])
				{
					if(bullet[i]->y<0)
					{
						k=0;
					}
				}
				if(k!=1)
				{
					delete(bullet[i]);
					bullet[i]=NULL;
				}
			}
			break;
	}
}
void createSprite(CUsrSprite **usr)
{
	int x = rand() % winWidth - autoWidth;
	if (x < 0)x = 0;
	int y = rand() % winHeight - autoHeight;
	if (y < 0)y = 0;
	int dx = 15;
	int dy = 15;
	*usr = new CUsrSprite(x, y, usrWidth, usrHeight, dx, dy, &imgusr, winRect);

}
void paint()
{
	beginPaint();
	clearDevice();
	int i = 0;
	for (i = 0; i < nowNum; ++i)
	{
		if (autosprite[i])
		{
			autosprite[i]->drawSprite();
		}
	}
	
	for(i=0;i<bullet_num;++i)
	{
		if(bullet[i])
	 	{
	 		bullet[i]->drawSprite();
	 	}
	}

	if (usr)
	{
		usr->drawSprite();
		char txt[10];
		sprintf_s(txt, "%d", usr->getScore());
		setTextSize(20);
		paintText(10, 10, txt);
	}
	endPaint();
}
void keyEvent(int key, int event)
{
	if (event != KEY_DOWN)
	{
		return;
	}
	if(usr)usr->move(key);
	paint();
}