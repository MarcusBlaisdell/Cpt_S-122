#include "Actor.h"

// default constructor
Actor::Actor ()
{
	this->mHealth   = 0;
	this->mArmor    = 0;
	this->mShield   = 0;
	this->mAttack   = 0;
	this->mMovement = 0;
	this->mSpeed    = 0;
	// this->mTexture.loadFromFile ("../Resources/Hero.png");
	// this->mSprite.setTextureRect (sf::IntRect (0, 32, 32, 32) );
} // end Actor default constructor

// initialized constructor
Actor::Actor (double theHealth, double theArmor, double theShield, double theAttack, 
		   double theMovement, double theSpeed, sf::Texture theTexture, 
		   sf::Sprite theSprite)
{
	this->mHealth   = theHealth;
	this->mArmor    = theArmor;
	this->mShield   = theShield;
	this->mAttack   = theAttack;
	this->mMovement = theMovement;
	this->mSpeed    = theSpeed;
	// this->mTexture  = theTexture;
	// this->mSprite   = theSprite;
} // end Actor initialized constructor

// copy constructor
Actor::Actor (Actor &copyObject)
{
	this->mHealth   = copyObject.mHealth;
	this->mArmor    = copyObject.mArmor;
	this->mShield   = copyObject.mShield;
	this->mAttack   = copyObject.mAttack;
	this->mMovement = copyObject.mMovement;
	this->mSpeed    = copyObject.mSpeed;
	// this->mTexture  = copyObject.mTexture;
	// this->mSprite   = copyObject.mSprite;
} // end Actor copy constructor
	
// destructor
Actor::~Actor ()
{
} // end Actor destructor

// overloaded assignment operator
Actor & Actor::operator = (Actor &rhs)
{
	this->mHealth   = rhs.mHealth;
	this->mArmor    = rhs.mArmor;
	this->mShield   = rhs.mShield;
	this->mAttack   = rhs.mAttack;
	this->mMovement = rhs.mMovement;
	this->mSpeed    = rhs.mSpeed;
	// this->mTexture  = rhs.mTexture;
	// this->mSprite   = rhs.mSprite;

	return *this;
} // end Actor overloaded assignment operator

	// Getters:

// get Health
double Actor::getHealth ()
{
	return mHealth;
} // end getHealth function

// get Armor
double Actor::getArmor ()
{
	return mArmor;
} // end getArmor function

// get Shield
double Actor::getShield ()
{
	return mShield;
} // end getShield function

// get Attack
double Actor::getAttack ()
{
	return mAttack;
} // end getAttack function

// get Movement
double Actor::getMovement ()
{
	return mMovement;
} // end getMovement function

// get Speed
double Actor::getSpeed ()
{
	return mSpeed;
} // end getSpeed function

/*
// get Texture
sf::Texture Actor::getTexture ()
{
	return mTexture;
} // end getTexture function


// get Sprite
sf::Sprite Actor::getSprite ()
{
	return mSprite;
} // end getSprite function
*/

		// Setters:

// set Health
void Actor::setHealth (double theHealth)
{
	this->mHealth = theHealth;
} // end setHealth function

// set Armor
void Actor::setArmor (double theArmor)
{
	this->mArmor = theArmor;
} // end setArmor function

// set Shield
void Actor::setShield (double theShield)
{
	this->mShield = theShield;
} // end setShield function

// set Attack
void Actor::setAttack (double theAttack)
{
	this->mAttack = theAttack;
} // end setAttack function

// set Movement
void Actor::setMovement (double theMovement)
{
	this->mMovement = theMovement;
} // end setMovement function

// set Speed
void Actor::setSpeed (double theSpeed)
{
	this->mSpeed = theSpeed;
} // end setSpeed function

/*
// set Texture
void Actor::setTexture (sf::Texture theTexture)
{
	this->mTexture = theTexture;
} // end setTexture function

// set Sprite
void Actor::setSprite (sf::Sprite theSprite)
{
	this->mSprite = theSprite;
} // end setSprite function
*/

// evalaluate the attack and adjust variables accordingly
void Actor::evaluateAttack (double theHealth, double theArmor, double theShield, double theAttack,
		                 double theMovement, double theSpeed)
{
	// reduce health by the amount of the attack
	// less the amount of the armor and the shield
	// may be affected by movement and speed later but not now

	this->mHealth = this->mHealth - (theAttack - theArmor - theShield);
} // end evaluateAttack function