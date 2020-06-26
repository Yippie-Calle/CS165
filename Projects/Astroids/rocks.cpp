#include "rocks.h"
#include "uiDraw.h"
#include <cmath>
#include <vector>
#define M_PI 3.14
// Put your Rock methods here
Rock::Rock(const Point& point)
{
	float angle = random(0, 360); 
	float x = random(-200, 200);
	float y = random(-200, 200);
	this->point.setX(x);
	this->point.setY(y);
	velocity.setDx(-cos((M_PI / 180.0 * angle)) * BIG_ROCK_SPEED);
	velocity.setDy(sin((M_PI / 180.0 * angle)) * BIG_ROCK_SPEED);
}
int Rock::getRadius()
{
	return radius;
}
BigRock::BigRock(const Point& point) : Rock(point)
{
	radius = BIG_ROCK_SIZE;
}
void BigRock::draw()
{
	if (alive)
	{
		drawLargeAsteroid(point, orientation);
	}
}

void BigRock::advance()
{
	FlyingObject::advance();
	orientation += BIG_ROCK_SPIN;
}
int BigRock::hit(float angle, std::vector<Rock*> &Rocks)
{
	float x =point.getX();
	float y = point.getY();
	kill();
	Rock* newMRock1 = new MediumRock(this->getPoint());
	this->point.setX(x);
	this->point.setY(y);
	velocity.setDy(getVelocity().getDy() + 1);
	newMRock1->setVelocity(this->getVelocity());
	Rocks.push_back(newMRock1);

	Rock* newMRock2 = new MediumRock(this->getPoint());
	this->point.setX(x);
	this->point.setY(y);
	velocity.setDy(getVelocity().getDy() - 1);
	newMRock2->setVelocity(this->getVelocity());
	Rocks.push_back(newMRock2);

	Rock* newSRock1 = new SmallRock(this->getPoint());
	this->point.setX(x);
	this->point.setY(y);
	velocity.setDx(getVelocity().getDy() + 2);
	newSRock1->setVelocity(this->getVelocity());
	Rocks.push_back(newSRock1);
	return BIG_ROCK_POINTS;
}

MediumRock::MediumRock(const Point& point): Rock(point)
{
	radius = MEDIUM_ROCK_SIZE;
}

void MediumRock::draw()
{
	if (alive)
	{
		drawMediumAsteroid(point, orientation);
	}
}

void MediumRock::advance()
{
	FlyingObject::advance();
	orientation += MEDIUM_ROCK_SPIN;
}
int MediumRock::hit(float angle, std::vector<Rock*>& Rocks)
{
	float x = point.getX();
	float y = point.getY();
	kill();
	velocity.setDx(getVelocity().getDx() + 3);
	Rock* newSRock2 = new SmallRock(this->getPoint());
	this->point.setX(x);
	this->point.setY(y);
	newSRock2->setVelocity(this->getVelocity());
	velocity.setDx(getVelocity().getDx() - 3);
	Rocks.push_back(newSRock2);

	Rock* newSRock3 = new SmallRock(this->getPoint());
	this->point.setX(x);
	this->point.setY(y);
	newSRock3->setVelocity(this->getVelocity());
	Rocks.push_back(newSRock3);
	Rock* newRock = new SmallRock(this->getPoint());


	return MEDIUM_ROCK_POINTS;
}


SmallRock::SmallRock(const Point& point) : Rock(point)
{
	radius = SMALL_ROCK_SIZE;
}

void SmallRock::draw()
{
	if (alive)
	{
		drawSmallAsteroid(point, orientation);
	}
}

void SmallRock::advance()
{
	FlyingObject::advance();
	orientation += SMALL_ROCK_SPIN;
}
int SmallRock::hit(float angle, std::vector<Rock*>& Rocks)
{
	kill();
	return SMALL_ROCK_POINTS;
}
