#include "Bullet.h"

BulletSprite::BulletSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1)
	:SpriteBase(x,y,width,height,dx,dy,img,r1)
{

}

BulletSprite::BulletSprite(BulletSprite &sprite):SpriteBase(sprite)
{

}

BulletSprite::~BulletSprite(){}


void BulletSprite::move(rect r1)
{
	y -= dy;
}

int BulletSprite::collision(rect r2)
{
	rect r1 = { x,y, width, height };
	int c = 1;
	if (r1.x < r2.x && r1.x + r1.width >r2.x) {
		if (r1.y > r2.y && r1.y<r2.y + r2.height)return c;
		if (r1.y <r2.y && r1.y + r1.height >r2.y)return c;
	}
	else {
		if (r1.x > r2.x && r2.x + r2.width > r1.x)
		{
			if (r1.y > r2.y && r1.y<r2.y + r2.height)return c;
			if (r1.y <r2.y && r1.y + r1.height >r2.y)return c;
		}
	}
	c = 0;
	return c;
}
