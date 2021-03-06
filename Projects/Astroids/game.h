/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H
#include <vector>
#define TRUE 1
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "rocks.h"
#include "ship.h"
#include "bullet.h"

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
    /*********************************************
     * Constructor
     * Initializes the game
     *********************************************/
    Game(Point tl, Point br);
    ~Game();

    /*********************************************
     * Function: handleInput
     * Description: Takes actions according to whatever
     *  keys the user has pressed.
     *********************************************/
    void handleInput(const Interface& ui);

    /*********************************************
     * Function: advance
     * Description: Move everything forward one
     *  step in time.
     *********************************************/
    void advance();

    /*********************************************
     * Function: draw
     * Description: draws everything for the game.
     *********************************************/
    void draw(const Interface& ui);
    //void drawT(const Interface& ui);

    Rock* createRock();
    float getClosestDistance(const FlyingObject& obj1, const FlyingObject& obj2) const;

private:
    // The coordinates of the screen
    Point topLeft;
    Point bottomRight;
    Point topRight;
    int score;
    Ship ship;
   std::vector<Bullet> bullets;
   std::vector<Rock*> Rocks;

    /*************************************************
     * Private methods to help with the game logic.
     *************************************************/
    bool isOnScreen(const Point& point);
    void advanceBullets();

    void handleCollisions();

    void cleanUpZombies();
};


#endif /* GAME_H */
