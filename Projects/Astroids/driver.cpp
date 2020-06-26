/*****************************************************
 * File: Driver.cpp
 * Author: Br. Burton
 *
 * Description: This file contains the main function
 *  that starts the game and the callback function
 *  that specifies what methods of the game class are
 *  called each time through the game loop.
 ******************************************************/
#include "game.h"
#include "uiInteract.h"
#include "ship.h"
#define TRUE 1
#include<conio.h>
#include<dos.h>
#include<Windows.h>

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   Game *pGame = (Game *)p;
   
   pGame->advance();
   pGame->handleInput(*pUI);
   pGame->draw(*pUI);
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
    char start;
    bool dead = TRUE;
    int hour = 0, min = 0, sec = 0; 
    do
    {
        std::cout << "Astroid Game!\n";
        std::cout << "Press S to start the game!\n";
        std::cout << "Press R to display the rules.\n";
        std::cout << "Press Q if you changed your mind.\n";
        std::cin >> start;
        if (start == 's')
        {
                Point topLeft(-200, 200);
                Point bottomRight(200, -200);
                Interface ui(argc, argv, "Asteroids", topLeft, bottomRight);
                Game game(topLeft, bottomRight);
                ui.run(callBack, &game);
        }
        else if (start == 'r')
        {
            std::cout << "UP arrow to thrust forward\n";
            std::cout << "Down arrow to slow down and go back\n";
            std::cout << "Right arrow to go right\n";
            std::cout << "Left arrow to go left\n";
            std::cout << "Spacebar to shoot bullets.\n";
            std::cout << "Press G to go back.\n";
            std::cin >> start;
        }
    } while (start != 'q');
    return 0;
}
           /*do
           {
               Point topLeft(-200, 200);
               Point bottomRight(200, -200);

               Interface ui(argc, argv, "Asteroids", topLeft, bottomRight);
               Game game(topLeft, bottomRight);
               ui.run(callBack, &game);
               dead = 0;
           } while (dead != 0);

           /*while (TRUE) {
               printf("\r \t\t\t\t %2d : %2d : %2d", hour, min, sec);
               sec++;;
               Sleep(1000);
               if (sec == 59) {
                   min++;
                   sec = 0;
               }
               if (min == 59) {
                   hour++;
                   min = 0;
                   sec = 0;
               }
               if (hour == 24) {
                   hour = 0;
                   min = 0;
                   sec = 0;
               }
           }*/