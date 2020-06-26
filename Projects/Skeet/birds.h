#ifndef Birds_H
#define Birds_H

#define Birds_Radius 15
#define Bird_X_Speed_Min 3.0
#define Bird_X_Speed_Max 6.0
#define Bird_Y_Speed_Min 0.0
#define Bird_Y_Speed_Max 4.0

#define Points_Normal_Bird 1
#define Points_Tough_Bird 5
#define Points_Sacred_Bird -10
#define Points_Tough_Bird_Hit 1
#define Points_Tough_Bird_Kill 3

#include "flyingObject.h"

class Bird : public FlyingObject
{
private:
public:
	Bird(const Point& point)
	{
		alive = true;
		setPoint(point);
	}
	virtual void draw() = 0;
	virtual int hit() = 0;
};

class NormalBird : public Bird
{
public:
	NormalBird(const Point& point);

	virtual void draw();
	virtual int hit();

};

class ToughBird : public Bird
{
	int health;
public:
	ToughBird(const Point& point);

	virtual void draw();
	virtual int hit();

};

class SacredBird : public Bird
{
public:
	SacredBird(const Point& point) : Bird(point) {};

	virtual void draw();
	virtual int hit();

};
#endif