#ifndef HERO_H
#define HERO_H

#define _CRT_SECURE_NO_WARNINGS

#include "Actor.h"

typedef struct
{
	int width;
	int height;
} mSize_t;

enum Direction {DOWN, UP, LEFT, RIGHT, SWING};

class Hero : public Actor
{
public:
		// default constructor
	Hero ();

		// initialized constructor
	Hero (sf::Vector2i theSource, mSize_t theSize, bool theFlag);
	
		// destructor
	~Hero ();

		// getters
	sf::Vector2i getSource  ();
	mSize_t      getSize    ();
	bool         getFlag    ();
	sf::Texture  getTexture ();
	sf::Sprite   getSprite  ();

		// setters
	void setSource  (sf::Vector2i theSource);
	void setSize    (mSize_t      theSize);
	void setFlag    (bool         theFlag);
	void setSourceX (int          theXDirection);
	void setSourceY (int          theYDirection);
	void setSizeW   (int          theWidth);
	void setSizeH   (int          theHeight);
	void setTexture (sf::Texture  theTexture);
	void setSprite  (sf::Sprite   theSprite);

		// functions
	void attackSword ();
	void attackFireball ();

// private:
protected:
	sf::Vector2i mSource;
	mSize_t      mSize;
	bool         mFlag;
	sf::Texture  mTexture;
	sf::Sprite   mSprite;
};

#endif