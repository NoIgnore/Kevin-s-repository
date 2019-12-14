#ifndef Enemy2Sprite_h
#define Enemy2Sprite_h

#include"acllib.h"
#include "AutoSprite.h"

class Enemy2Sprite :
	public CAutoSprite
{
	int oldx, oldy;
	bool danger(rect ur);
	bool bfirst;
public:
	Enemy2Sprite(int x, int y, int width, int height, int dx, int dy, ACL_Image *img, rect r1,int score);
	Enemy2Sprite(Enemy2Sprite &sprite);
	virtual ~Enemy2Sprite();

	void move(rect ur);
};

#endif
