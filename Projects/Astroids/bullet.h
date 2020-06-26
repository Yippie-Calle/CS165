#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"

// Put your Bullet class here

class Bullet : public FlyingObject
{
private:
	int life = 0;
public:
	Bullet()
	{
		alive = true;
	}

	virtual void draw();

	void fire(const Point& point, float angle);
};

#endif /* bullet_h */
