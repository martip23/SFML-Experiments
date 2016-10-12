SFML Personal Exploration Project
==================

:Author: Patrick L. Martinez
:Date: 10/7/2016
:Version: 0.1

This is a test of my first use of SFML, small fast multimedia library, so I can begin learning it to create games.


To be able to build these files, you need the SFML libraries.
********************

To install on linux use::

	sudo apt-get install libsfml-dev

For MacOS and Windows, use the corresponding tutorial.
http://www.sfml-dev.org/tutorials/2.4/

The Program
*******************

The program currently read 4 types of events and displays messages in the console. Work is in progress. The makefile has the following commands.

:make: Build executable and .o files
:make run: Run the exectuable
:make clean: Clean up because we're not animals

Gameplay
******************

SFML Experiments is a minimalist role playing dungeon crawler currently lacking dungeons, an inventory system, monsters, health point system among other things. 

To play, run the executable. Use the arrow keys to move left, right, up or down. 
Use shift to sprint!

Careful not to go to the edge of the screen! Nothing happens, but it's a glaring flaw in the game that we'd rather keep under wraps. 

Enjoy!

Update Log
******************

v0.2 - Now we're talkin':
=========

-Added character sprite
-Added badass background
-Added moving logic
-Added sprint option (hold shift to sprint)
-Added frame limiter (primitive)

v0.1 - Initial Update:
=========

-Created gameplay window logic
-Added mouse events that appear to console


