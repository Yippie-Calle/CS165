#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#define BIG_ROCK_SPEED 1
#define MEDIUM_ROCK_SPEED 1.1
#define SMALL_ROCK_SPEED 1.2

#define BIG_ROCK_POINTS 1
#define MEDIUM_ROCK_POINTS 2
#define SMALL_ROCK_POINTS 3
#include "flyingObject.h"
#include <vector>

// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
protected:
	int radius;
	int orientation;
public:
	Rock(const Point& point);
	virtual int getRadius();
	virtual void draw() = 0;
	virtual int hit(float angle, std::vector<Rock*>& Rocks) = 0;
};
//   BigRock
class BigRock : public Rock
{
public:
	BigRock(const Point& point);
	virtual void advance();
	virtual void draw();
	virtual int hit(float angle, std::vector<Rock*>& Rocks);
};
//  MediumRock
class MediumRock : public Rock
{
public:
	MediumRock(const Point& point);
	virtual void advance();
	virtual void draw();
	virtual int hit(float angle, std::vector<Rock*>& Rocks);
};
//   SmallRock
class SmallRock : public Rock
{
public:
	SmallRock(const Point& point);
	virtual void advance();
	virtual void draw();
	virtual int hit(float angle, std::vector<Rock*>& Rocks);
};


#endif /* rocks_h */
