#include "lander.h"
#include "uiDraw.h"

void Lander::applyGravity(float amount)
{
	Velocity v1;
	v1.setDy(-1 * amount);
	velocity.add(v1);

}

void Lander::applyThrustLeft()
{
	// if canThrust? add thrust to velocity
	if (canThrust())
	{
		Velocity v1;
		v1.setDx(0.1);
		velocity.add(v1);
		fuel = fuel - 1; // consume fuel at this point
	}
}

void Lander::applyThrustRight()
{
	// if canThrust? add thrust to velocity
	if (canThrust())
	{
		Velocity v1;
		v1.setDx(-0.1); // opposite of Left
		velocity.add(v1);
		fuel = fuel - 1; // consume fuel at this point
	}
}

void Lander::applyThrustBottom()
{
	// velocity fun 
	Velocity v1;
	v1.setDy(0.3);
	velocity.add(v1);
	// fuel fun
	fuel = fuel - 3;
}

void Lander::advance()
{
	point.addX(velocity.getDx()); // get direction from velocity
	point.addY(velocity.getDy()); // get direction from velocity
}

bool Lander::canThrust()
{
	return(isAlive() && !isLanded() && fuel > 0);
}


void Lander::draw() const 
{
	if (isAlive())
	{
		drawLander(point);
	}
}

