#ifndef BulletSprite_h
#define BulletSprite_h

#include "SpriteBase.h"

class BulletSprite :public SpriteBase
{
	public:
		BulletSprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1);
		BulletSprite(BulletSprite &sprite);
		~BulletSprite();

		void move(rect r);

		int collision(rect r1);

};

#endif
