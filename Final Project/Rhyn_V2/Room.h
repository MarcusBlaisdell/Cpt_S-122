#ifndef ROOM_H
#define ROOM_H

#include "Hero.h"
#include "TileMap.h"

typedef struct frames
{
  float frameCounter;
  float frameSwitch;
  float frameSpeed;
  sf::Clock mClock;
} frameTools;

class Room
{
public:
	// default constructor
	Room ();

		// initialized constructor
	Room (string filePath);

	  // Functions
  void draw(sf::RenderWindow &theWindow, Hero &theHero, frameTools &frameCount);

private:
	TileMap mGameMap;
};

#endif