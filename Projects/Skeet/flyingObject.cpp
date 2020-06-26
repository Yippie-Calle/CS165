#include "flyingObject.h"
#include "uiDraw.h"


void FlyingObject::advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
}