#include "birds.h"
#include "uiDraw.h"

NormalBird::NormalBird(const Point& point) : Bird(point)
{
	float dx = random(3, 6);
	float dy = random(0, 4);

	if (point.getY() > 0)
	{
		dy *= -1;
	}

	Velocity newVelocity;
	newVelocity.setDx(dx);
	newVelocity.setDy(dy);

	setVelocity(newVelocity);

}
ToughBird::ToughBird(const Point& point) : Bird(point) 
{
	health = Points_Tough_Bird_Kill; 

	float dx = random(3, 6);
	float dy = random(0, 4);

	if (point.getY() > 0)
	{
		dy *= -1;
	}

	Velocity newVelocity;
	newVelocity.setDx(dx);
	newVelocity.setDy(dy);

	setVelocity(newVelocity);

};
void NormalBird::draw()
{
	if (alive)
	{
		drawCircle(point, Birds_Radius);
	}
}

int NormalBird::hit()
{
	kill();
	return Points_Normal_Bird;
}


void ToughBird::draw()
{
	if (alive)
	{
		drawCircle(point, Birds_Radius);
	}
}

int ToughBird::hit()
{
	health--;
	if (health == 0)
	kill();
	return Points_Tough_Bird;
}
void SacredBird::draw()
{
	if (alive)
	{
		drawCircle(point, Birds_Radius);
	}
}

int SacredBird::hit()
{
	kill();
	return Points_Sacred_Bird;
}