#include "bullet.h"
#include "uiDraw.h"
#include "velocity.h"
#include <cmath>
#define M_PI 3.14

// Put your bullet methods here
void Bullet::draw()
{
	if (alive)
	{
		drawDot(point);
	}
	life++;
	if (life == BULLET_LIFE)
	{
		kill();
	}
}

void Bullet::fire(const Point& point, float angle)
{
	this->point = point;

	velocity.setDx(cos((M_PI / 180.0 * angle)) * BULLET_SPEED);
	velocity.setDy(sin((M_PI / 180.0 * angle)) * BULLET_SPEED);
	alive = true;
}