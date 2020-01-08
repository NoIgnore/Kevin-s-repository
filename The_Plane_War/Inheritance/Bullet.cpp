#include "Bullet.h"

BulletSprite::BulletSprite(BulletSprite & a)
:CusrSprite(a)
{}

BulletSprite::BulletSprite(char const *name,int x,int y,int dx,int dy,int w,int h,int wWidth,int wHeight)
:CusrSprite(name,x,y,dx,dy,w,h,wWidth,wHeight)
{}

BulletSprite::~BulletSprite(void){}

int BulletSprite::collision(CautoSprite &a){
	return CusrSprite::collision(a);
}

void BulletSprite::drawScale(int w,int h)
{
	CusrSprite::drawScale(w,h);
}

void BulletSprite::move(){
	y -= dy;
}


