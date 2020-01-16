#include "World.h"

// default constructor
World::World ()
{

} // end World default constructor

// draw function
void World::draw (sf::RenderWindow &theWindow)
{
	Hero theHero;
	
	mFrameCount.frameCounter = 0;
	mFrameCount.frameSpeed   = 1;
	mFrameCount.frameSwitch  = 0;
	
	mRoom.draw (theWindow, theHero, mFrameCount);
} // end draw function