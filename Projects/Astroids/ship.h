#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#include "flyingObject.h"


// Put your Ship class here
class Ship : public FlyingObject
{
private:
	float angle;
public:
	int getRadius() { return SHIP_SIZE; }
	void draw();
	void thrust();
	void turnLeft();
	void turnRight();
	void slowReverse();
	float getAngle() { return angle; };
	Ship() { this->alive = true; };
};

#endif /* ship_h */
