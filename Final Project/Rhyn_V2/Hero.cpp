#include "Hero.h"

// default constructor
Hero::Hero ()
{
	cout << "Hero default constructor" << endl;
	this->mSource.x    = 0;
	this->mSource.y    = 0;
	this->mSize.height = 32;
	this->mSize.width  = 32;
	this->mFlag        = false;
	this->mTexture.loadFromFile ("../Resources/Hero.png");
	this->mSprite.setTexture (mTexture); // must load the texture before parsing it
	this->mSprite.setTextureRect (sf::IntRect (0, 32, 32, 32) ); // parse the texture map
} // end Hero default constructor

// initialized constructor
Hero::Hero (sf::Vector2i theSource, mSize_t theSize, bool theFlag)
{
	this->mSource.x    = theSource.x;
	this->mSource.y    = theSource.y;
	this->mSize.height = theSize.height;
	this->mSize.width  = theSize.width;
	this->mFlag        = theFlag;
	this->mTexture.loadFromFile ("../Resources/Hero.png");
	this->mSprite.setTextureRect (sf::IntRect (0, 32, 32, 32) );
} // end Hero initialized constructor
	
// destructor
Hero::~Hero ()
{
	cout << "Hero Destructor called" << endl;
} // end Hero Destructor


	// getters
// get Source
sf::Vector2i Hero::getSource ()
{
	return mSource;
} // end getSource function

// get Size
mSize_t Hero::getSize ()
{
	return mSize;
} // end getSize function

// get Texture
sf::Texture Hero::getTexture ()
{
	return mTexture;
} // end getTexture function

// get Sprite
sf::Sprite Hero::getSprite ()
{
	return mSprite;
} // end getSprite function

// get Flag
bool Hero::getFlag ()
{
	return mFlag;
} // end getFlag function

	// setters

// set Source
void Hero::setSource (sf::Vector2i theSource)
{
	this->mSource = theSource;
} // end setSource function

// set Size
void Hero::setSize (mSize_t theSize)
{
	this->mSize = theSize;
} // end setSize function

// set Flag
void Hero::setFlag (bool theFlag)
{
	this->mFlag = theFlag;
} // end setFlag function

// set source x
void Hero::setSourceX (int theXDirection)
{
	this->mSource.x = theXDirection;
} // end setSourceX

// set source y
void Hero::setSourceY (int theYDirection)
{
	this->mSource.y = theYDirection;
} // end setSourceY

// set size width
void Hero::setSizeW (int theWidth)
{
	this->mSize.height = theWidth;
} // end setSizeW

// set size height
void Hero::setSizeH (int theHeight)
{
	this->mSize.height = theHeight;
} // end getSize

// set Texture
void Hero::setTexture (sf::Texture theTexture)
{
	this->mTexture = theTexture;
} // end setTexture function

// set Sprite
void Hero::setSprite (sf::Sprite theSprite)
{
	this->mSprite = theSprite;
} // end setSprite function


	// functions

// sword attack
void Hero::attackSword ()
{
} // end attackSword function

// fireball attack
void Hero::attackFireball ()
{
} // end attackFireball function