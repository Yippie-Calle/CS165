#include "flyingObject.h"
#include "uiDraw.h"


// Put your FlyingObject method bodies here
void FlyingObject::advance()
{
    if (point.getX() > 200)
    {
        point.setX(-200);
    }
    else if (point.getX() < -200)
    {
        point.setX(200);
    }
    else if (point.getY() > 200)
    {
        point.setY(-200);
    }
    else if (point.getY() < -200)
    {
        point.setY(200);
    }
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
}