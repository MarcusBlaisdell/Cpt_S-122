#ifndef ACTOR_H
#define ACTOR_H

#define _CRT_SECURE_NO_WARNINGS

#include "Object.h"

class Actor : public Object
{
	friend class Room;
public:
		// default constructor
	Actor ();

		// initialized constructor
	Actor (double theHealth, double theArmor, double theShield, double theAttack, 
		   double theMovement, double theSpeed, sf::Texture theTexture, 
		   sf::Sprite theSprite);

		// copy constructor
	Actor (Actor &copyObject);
	
		// destructor
	~Actor ();

		// overloaded assignment operator
	Actor & operator = (Actor &rhs);

		// Getters:
	double      getHealth   ();
	double      getArmor    ();
	double      getShield   ();
	double      getAttack   ();
	double      getMovement ();
	double      getSpeed    ();
	sf::Texture getTexture  ();
	sf::Sprite  getSprite   ();

		// Setters:
	void setHealth   (double      theHealth);
	void setArmor    (double      theArmor);
	void setShield   (double      theShield);
	void setAttack   (double      theAttack);
	void setMovement (double      theMovement);
	void setSpeed    (double      theSpeed);
	void setTexture  (sf::Texture theTexture);
	void setSprite   (sf::Sprite  theSprite);

		// functions
	void evaluateAttack (double theHealth, double theArmor, double theShield, double theAttack,
		                 double theMovement, double theSpeed);

// private:
protected:
	double mHealth;
	double mArmor;
	double mShield;
	double mAttack;
	double mMovement;
	double mSpeed;
	// sf::Texture mTexture;
	// sf::Sprite mSprite;

};

#endif