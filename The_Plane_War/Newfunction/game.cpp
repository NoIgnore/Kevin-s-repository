#include"acllib.h"
#include"Bullet.h"
#include"UsrSprite.h"
#include"AutoSprite.h"
#include"Enemy2Sprite.h"
#include<time.h>
#include<stdio.h>

using namespace std;

const int winWidth = 960, winHeight = 800,width1=102,height1=126;
const int width2=57,height2=43;
const int width3=5,height3=11;
const int width4=55,height4=60;
const int width_partial_bullet=11,height_partial_bullet=5;
const int width_partial_supply=58,height_partial_supply=88;
const int width_bigbullet=63,height_bigbullet=57;
const int width_supply=60,height_supply=107;
const int maxNum = 40;
const int Bulletnumber = 1000;
const int max_bigbullet_number = 100;
const int supply_number = 100;
const int max_partial_bullet_number=300;
const int partial_supply_number=100;

CAutoSprite* autosprite[maxNum] = { 0 };

CAutoSprite* supply[supply_number] = { 0 };
CAutoSprite* partial_supply[partial_supply_number] = { 0 };

BulletSprite* bullet[Bulletnumber] = { 0 };

BulletSprite* bigbullet[max_bigbullet_number] = { 0 };

BulletSprite* partial_bullet1[max_partial_bullet_number] = { 0 };
BulletSprite* partial_bullet2[max_partial_bullet_number] = { 0 };
CUsrSprite* usr = NULL;

int usrWidth = width1, usrHeight = height1;
int autoWidth = width2, autoHeight = height2;

ACL_Image imgenemy1,imgusr,imgenemy2,imgbullet,imgbigbullet,imgbigbullet_supply,imgpartialbullet,imgpartialbullet_supply;
rect winRect;

void timerEvent(int id);
void createSprite(CUsrSprite **usr);
void keyEvent(int key, int event);
void paint();

int nowNum = 0;

int bullet_num = 0;

int bigbullet_now_number = 0;
int supply_now = 0;

int partial_now_bullet1 = 0;
int partial_now_bullet2 = 0;
int partial_supply_now = 0;

int if_get_partial_supply = 0;

int if_get_supply = 0;

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
	loadImage("bigbullet.jpg", &imgbigbullet);//63,57
	loadImage("bigbullet_supply.jpg", &imgbigbullet_supply);//60,107
	loadImage("partial_bullet.jpg", &imgpartialbullet);//11,5
	loadImage("partial_bullet_supply.jpg", &imgpartialbullet_supply);//58,88

	createSprite(&usr);
	registerTimerEvent(timerEvent);
	registerKeyboardEvent(keyEvent);
	startTimer(0,1500);//初始化敌机
	startTimer(1,1);//移动的绘画&补给碰撞的检测
	startTimer(2,800);//产生小子弹
	startTimer(3,5);//查看小子弹是否碰撞
	startTimer(4,4);//这个是Y坐标小于0时所有子弹清空，加上一个补给大于窗口y轴就消除
	startTimer(5,8000);//8秒一个大子弹补给
	startTimer(6,5);//查看是否发射大子弹
	startTimer(7,5);//查看大子弹是否碰撞

	startTimer(8,8000);//8s一个偏移子弹补给
	startTimer(9,5);//查看是否发射partial子弹
	startTimer(10,5);//查看partial1子弹是否碰撞
	startTimer(11,5);//查看partial2子弹是否碰撞
	startTimer(12,3);//补给大于窗口y轴就消除,


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

			for (int i = 0; i < supply_now; ++i)
			{
				if (supply[i])
				{
					rect ur = usr->getRect();
					supply[i]->move(ur);
				}
			}

			for (int i = 0; i < partial_supply_now; ++i)
			{
				if (partial_supply[i])
				{
					rect ur = usr->getRect();
					partial_supply[i]->move(ur);
				}
			}

			for(int h=0;h<bigbullet_now_number;++h)
			{
				if(bigbullet[h])
				{
					rect ur = usr->getRect();
					bigbullet[h]->move(ur);
				}
			}

			for(int h=0;h<partial_now_bullet1;++h)
			{
				if(partial_bullet1[h])
				{
					rect ur = usr->getRect();
					partial_bullet1[h]->move(ur);
				}
			}

			for(int h=0;h<partial_now_bullet2;++h)
			{
				if(partial_bullet2[h])
				{
					rect ur = usr->getRect();
					partial_bullet2[h]->move(ur);
				}
			}
			//先不设定usr和敌机的碰撞
			for (int i = 0; i < supply_now; ++i)
			{
				if (supply[i])
				{
					if (usr->collision(supply[i]->getRect()))
					{
						delete(supply[i]);
						supply[i] = NULL;
						if_get_supply = 1;
					}
				}
			}

			for (int i = 0; i < partial_supply_now; ++i)
			{
				if (partial_supply[i])
				{
					if (usr->collision(partial_supply[i]->getRect()))
					{
						delete(partial_supply[i]);
						partial_supply[i] = NULL;
						if_get_partial_supply = 1;
					}
				}
			}
			paint();
			break;
//产生小子弹
		case 2:
			bullet[bullet_num] = new BulletSprite(usr->x + 49, usr->y, width3, height3, 0, 15, &imgbullet, winRect);
			if (bullet[bullet_num]) {
				bullet_num++;
			}
			break;
		case 3://查看小子弹是否碰撞
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
		case 4://这个是Y坐标小于0时所有子弹清空，加上一个补给大于窗口y轴就消除
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

			for(int i=0;i<bigbullet_now_number;++i)
			{
				int k=1;
				if(bigbullet[i])
				{
					if(bigbullet[i]->y<0)
					{
						k=0;
					}
				}
				if(k!=1)
				{
					delete(bigbullet[i]);
					bigbullet[i]=NULL;
				}
			}

			for(int i=0;i<partial_now_bullet1;++i)
			{
				int k=1;
				if(partial_bullet1[i])
				{
					if(partial_bullet1[i]->x<0)
					{
						k=0;
					}
				}
				if(k!=1)
				{
					delete(partial_bullet1[i]);
					partial_bullet1[i]=NULL;
				}
			}

			for(int i=0;i<partial_now_bullet2;++i)
			{
				int k=1;
				if(partial_bullet2[i])
				{
					if(partial_bullet2[i]->x>winWidth)
					{
						k=0;
					}
				}
				if(k!=1)
				{
					delete(partial_bullet2[i]);
					partial_bullet2[i]=NULL;
				}
			}
			break;
		case 5:
			if(supply_now>=supply_number) return;
			x = rand() % winWidth - width_supply;
			if (x < 0)x = 0;
			 y = 1;
			dx = rand() % 5 + 1;
			dy = rand() % 5 + 1;
			supply[supply_now] = new CAutoSprite(x, y, width_supply, height_supply, dx, dy, &imgbigbullet_supply, winRect,0);
			if(supply[supply_now]){
				supply_now++;
			}
			break;
		case 6:
			if(if_get_supply == 0) return;
			bigbullet[bigbullet_now_number] = new BulletSprite(usr->x + 20, usr->y, width_bigbullet, height_bigbullet, 0, 10, &imgbigbullet, winRect);
			if (bigbullet[bigbullet_now_number]) {
				bigbullet_now_number++;
			}
			if_get_supply = 0;
			break;
		case 7:
			for(int i=0;i< bigbullet_now_number;++i)
			{
				int k=0;
				if(bigbullet[i])
				{
					for(int v=0;v<nowNum;v++){
						if(autosprite[v])
						{
							if(bigbullet[i]->collision(autosprite[v]->getRect()))
							{
								int s = autosprite[v]->getScore();
								if (usr)usr->addScore(s);
								delete(autosprite[v]);
								autosprite[v] = NULL;
								k+=1;
							}
						}
						if(k==5)
						{
							break;
						}
					}
				}
				if(k==5)
				{
					delete(bigbullet[i]);
					bigbullet[i]=NULL;
					k=0;
				}
			}
			break;
		case 8:
			if(partial_supply_now>=partial_supply_number) return;
			x = rand() % winWidth - width_partial_supply;
			if (x < 0)x = 0;
			 y = 1;
			dx = rand() % 5 + 1;
			dy = rand() % 5 + 1;
			partial_supply[partial_supply_now] = new CAutoSprite(x, y, width_partial_supply, height_partial_supply, dx, dy, &imgpartialbullet_supply, winRect,0);
			if(partial_supply[partial_supply_now]){
				partial_supply_now++;
			}
			break;
		case 9:
			if(if_get_partial_supply == 0) return;
			partial_bullet1[partial_now_bullet1] = new BulletSprite(usr->x, usr->y+26, width_partial_bullet, height_partial_bullet, 10, 0, &imgpartialbullet, winRect);
			partial_bullet2[partial_now_bullet2] = new BulletSprite(usr->x+126, usr->y+26, width_partial_bullet, height_partial_bullet, -10, 0, &imgpartialbullet, winRect);
			if (partial_bullet1[partial_now_bullet1]) 
			{
				partial_now_bullet1++;
			}
			if (partial_bullet2[partial_now_bullet2]) 
			{
				partial_now_bullet2++;
			}
			if_get_partial_supply = 0;
			break;
		case 10:
			for(int i=0;i< partial_now_bullet1;++i)
			{
				int k = 1;
				if(partial_bullet1[i])
				{
					int j=0;
					while(j<nowNum)
					{
						if(autosprite[j])
						{
							if(partial_bullet1[i]->collision(autosprite[j]->getRect()))
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
					delete(partial_bullet1[i]);
					partial_bullet1[i]=NULL;
				}
			}
			break;
		case 11:
			for(int i=0;i< partial_now_bullet2;++i)
			{
				int k = 1;
				if(partial_bullet2[i])
				{
					int j=0;
					while(j<nowNum)
					{
						if(autosprite[j])
						{
							if(partial_bullet2[i]->collision(autosprite[j]->getRect()))
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
					delete(partial_bullet2[i]);
					partial_bullet2[i]=NULL;
				}
			}
			break;
		case 12:
			for(int i=0;i<supply_now;i++)
			{
				int k=1;
				if(supply[i])
				{
					if(supply[i]->y>692)//800-107-1
					{
						k=0;
					}
				}
				if(k!=1)
				{
					delete(supply[i]);
					supply[i]=NULL;
				}
			}

			for(int i=0;i<partial_supply_now;i++)
			{
				int k=1;
				if(partial_supply[i])
				{
					if(partial_supply[i]->y>692)//800-88-1
					{
						k=0;
					}
				}
				if(k!=1)
				{
					delete(partial_supply[i]);
					partial_supply[i]=NULL;
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

	for (i = 0; i < supply_now; ++i)
	{
		if (supply[i])
		{
			supply[i]->drawSprite();
		}
	}

	for(i=0;i<bigbullet_now_number;++i)
	{
		if(bigbullet[i])
		{
			bigbullet[i]->drawSprite();
		}
	}

	for(i=0;i<partial_supply_now;++i)
	{
		if(partial_supply[i])
		{
			partial_supply[i]->drawSprite();
		}
	}

	for(i=0;i<partial_now_bullet1;++i)
	{
		if(partial_bullet1[i])
		{
			partial_bullet1[i]->drawSprite();
		}
	}

	for(i=0;i<partial_now_bullet2;++i)
	{
		if(partial_bullet2[i])
		{
			partial_bullet2[i]->drawSprite();
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