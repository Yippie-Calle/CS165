/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;


// You may find this function helpful...
/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game::Game(Point tl, Point br)
    : topLeft(tl), bottomRight(br)
{
    // Set up the initial conditions of the game
    score = 0;

    for (int i = 0; i < 6; i++)
    {
        Rocks.push_back(createRock());
    }
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
    // TODO: Check to see if there is currently a bird allocated
    //       and if so, delete it.

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
    for (vector <Rock*> ::iterator it = Rocks.begin(); it != Rocks.end(); ++it)
        if (*it != NULL)
        {
            (*it)->advance();
        }
    ship.advance();
    advanceBullets();
    //advanceBird();

    handleCollisions();
    cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
    // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            // this bullet is alive, so tell it to move forward
            bullets[i].advance();

            if (!isOnScreen(bullets[i].getPoint()))
            {
                // the bullet has left the screen
                bullets[i].kill();
            }

        }
    }
}


/**************************************************************************
 * GAME :: CREATE Rock
 * Create a Rock of a random type according to the rules of the game.
 **************************************************************************/
Rock* Game::createRock()
{
    int x = (random(-50, 50));
    int y = (random(-50, 50));
    Point point2(x, y);
    Rock* newRock = new BigRock(point2);
    return newRock;
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game::isOnScreen(const Point& point)
{
    return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
        && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
        && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
        && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game::handleCollisions()
{
    bool dead = TRUE;
    for (int i = 0; i < bullets.size(); i++)
    {
        for (int j = 0; j < Rocks.size(); j++)
        {
            if (Rocks[j] != NULL && bullets[i].isAlive() && Rocks[j]->isAlive())
            {
                getClosestDistance(*Rocks[j], bullets[i]);
                if (getClosestDistance(*Rocks[j], bullets[i]) < (*Rocks[j]).getRadius())
                {
                    (*Rocks[j]).hit(0, Rocks);
                    (*Rocks[j]).kill();
                    int points = (*Rocks[j]).hit(0,Rocks);
                    score += points;
                    bullets[i].kill();
                    
                }
            }
        }
    }
    for (int i = 0; i < Rocks.size(); i++)
    {
        if (Rocks[i] != NULL && ship.isAlive() && Rocks[i]->isAlive())
        {
            getClosestDistance(*Rocks[i], ship);
            if (getClosestDistance(*Rocks[i], ship) < (ship.getRadius() + (*Rocks[i]).getRadius()))
            {
                (*Rocks[i]).kill();
                ship.kill();
                std::cout << "Game Over!";
                dead = 0;
            }
        }
    }

}

/**************************************************************************
 * GAME :: CLEAN UP Rocks
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game::cleanUpZombies()
{
    // Look for dead Rocks
    vector<Rock*>::iterator it = Rocks.begin();
    while (it != Rocks.end())
    {

        Rock* pRock = *it;
        if (!pRock->isAlive())
        {
            // If we had a list of pointers, we would need to delete the memory here...


            // remove from list and advance
            
            delete pRock;
            pRock = NULL;
            it = Rocks.erase(it);
        }
        else
        {
            it++; // advance
        }
    }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface& ui)
{
    /// Change the direction of the rifle
    if (ui.isLeft())
    {
        ship.turnLeft();
    }

    if (ui.isRight())
    {
        ship.turnRight();
    }
    if (ui.isUp())
    {
        ship.thrust();
    }
    if (ui.isDown())
    {
        ship.slowReverse();
    }
    //Check for "Spacebar
    if (ui.isSpace())
    {
        Bullet newBullet;
        newBullet.fire(ship.getPoint(), ship.getAngle());
        bullets.push_back(newBullet);
    }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface& ui)
{
    // draw the Rock

    // TODO: Check if you have a valid Rock and if it's alive
    // then call it's draw method
    for (vector <Rock*> ::iterator it = Rocks.begin(); it != Rocks.end(); ++it)
        if (*it != NULL)
        {
            (*it)->draw();
        }

    // draw the ship
        ship.draw();
    

    // draw the bullets, if they are alive
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].isAlive())
        {
            bullets[i].draw();
        }
    }
    // Put the score on the screen
    Point scoreLocation;
    scoreLocation.setX(topLeft.getX() + 5);
    scoreLocation.setY(topLeft.getY() - 5);

    drawNumber(scoreLocation, score);


}

/*void Game::draw(const Interface& ui)
{
    Point timerLocation;
    timerLocation.setX(topRight.getX() + 5);
    timerLocation.setY(topRight.getY() - 5);

    drawNumber(timerLocation, time);
}*/

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}