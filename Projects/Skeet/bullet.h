#ifndef bullet_h
#define bullet_h

#include "flyingObject.h"

static const float BULLET_SPEED = 10.0;

class Bullet : public FlyingObject
{
private:
public:
	Bullet()
	{
		alive = true;
	}

	virtual void draw();
	void fire(const Point& point, float angle);
};
#endif