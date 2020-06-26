###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Alvey, CS165
# Author:
#     Bryan Calle
# Summary:
#     The beginning of the project.  
# Above and Beyond
#     I begun the aspect of creating a start menu,
#	This start menu will allow user to pick option of seeing
#	the instructions, or starting the game. I chose this because
#	Although I knew what the game was I others who play may not.
#	Also by giving a start menu we give user time to get ready.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
lander.o: lander.h lander.cpp point.h
	g++ -c lander.cpp

velocity.o: velocity.h velocity.cpp point.h
	g++ -c velocity.cpp
###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
