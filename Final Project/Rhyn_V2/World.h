#ifndef WORLD_H
#define WORLD_H

#include "Room.h"

class World
{
public:	
		// default constructor
	World ();

		// Functions
	void draw (sf::RenderWindow &theWindow);
private:
	Room mRoom;
	Hero mHero;
	frameTools mFrameCount;
};

#endif