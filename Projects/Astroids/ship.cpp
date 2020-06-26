#include "ship.h"
#include "uiDraw.h"
#include <cmath>
#define M_PI 3.14
// Put your ship methods here
void Ship::thrust()
{
	Velocity v1;
	v1.setDx(cos((M_PI / 180.0 * angle)) * THRUST_AMOUNT);
	v1.setDy(sin((M_PI / 180.0 * angle)) * THRUST_AMOUNT);
	velocity.add(v1);
}
void Ship::turnLeft()
{
	angle += ROTATE_AMOUNT;
}
void Ship::turnRight()
{
	angle -= ROTATE_AMOUNT;
}
void Ship::slowReverse()
{
	Velocity v1;
	v1.setDx(-(cos((M_PI / 180.0 * angle)) * THRUST_AMOUNT));
	v1.setDy(-(sin((M_PI / 180.0 * angle)) * THRUST_AMOUNT));
	velocity.add(v1);
}
void Ship::draw()
{
	if (isAlive())
	{
		drawShip(point, angle-90, 0);
	}
}