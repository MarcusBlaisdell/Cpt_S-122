#include "Room.h"

	// Default constructor
Room::Room ()
{
	cout << "Room default constructor" << endl;
	const int level[] = {19, 18,  6,  7,  3,  3, 11,  0,   1,  1,  1,  1, 17,  5,  5,  6,
                         14, 15,  6,  3, 11,  3,  7,  4,   5,  5,  5,  5,  5,  5,  5,  6,
                         19, 18,  6,  7,  3,  0,  1, 17,   5, 12,  9,  9,  9,  9,  9, 10,
                          9,  9,  3,  3, 11,  4,  5,  5,  12, 10,  3, 11,  3,  0,  2,  7};

	/*THIS IS OUR BACKGROUND*/

	mGameMap.load("../Resources/Tileset-1.png", sf::Vector2u(16, 16), level, 16, 4);
} // end default constructor

// initialized constructor
Room::Room (string filePath)
{
	cout << "Room initialized constructor" << endl;

    // tile pixel dimensions are 16X16
    // this is an array of tiles to create the map,
    // the map as follows is defined as 16 columns by 4 rows
    // first 16 integers are the first row, second 16 second row, ...

  const int level[] = {19, 18,  6,  7,  3,  3, 11,  0,   1,  1,  1,  1, 17,  5,  5,  6,
                       14, 15,  6,  3, 11,  3,  7,  4,   5,  5,  5,  5,  5,  5,  5,  6,
                       19, 18,  6,  7,  3,  0,  1, 17,   5, 12,  9,  9,  9,  9,  9, 10,
                        9,  9,  3,  3, 11,  4,  5,  5,  12, 10,  3, 11,  3,  0,  2,  7};

  /*THIS IS OUR BACKGROUND*/

  mGameMap.load("../Resources/Tileset-1.png", sf::Vector2u(16, 16), level, 16, 4);
} // end Room initialized constructor 2

// draw function
void Room::draw(sf::RenderWindow &theWindow, Hero &theHero, frameTools &frameCount)
{
	sf::Texture testTexture;
	testTexture.loadFromFile ("../Resources/Hero.png");

	sf::Sprite testSprite;
	testSprite.setTexture (testTexture);

	Actor theActor;
	// theActor.mTexture.loadFromFile ("../Resources/Hero.png");
	// theActor.mSprite.setTextureRect (sf::IntRect (0, 32, 32, 32) );

	/*
	sf::Event event;

    while (window.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyPressed:
        theHero.setFlag(false);
        if(event.key.code == sf::Keyboard::Up)
        {
          theHero.setSourceX(UP);
          theHero.setSizeW(32);
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
          theHero.setSourceX(DOWN);
          theHero.setSizeW(32);
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
          theHero.setSourceX(RIGHT);
          theHero.setSizeW(-32);
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
          theHero.setSourceX(LEFT);
          theHero.setSizeW(32);
        }
        else if (event.key.code == sf::Keyboard::F)
        {
          theHero.setSourceX(SWING);
          theHero.setSizeW(-32);
          frameCount.frameSwitch = 25;
        }
      break;
      case sf::Event::KeyReleased:
        theHero.setFlag(true);
      break;
      }

    }
	
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) )
    {
      theHero.getSprite ().move(0, -.1);
	  cout << "Up" << endl;
    } // end if key pressed is up arrow
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      theHero.getSprite ().move(0, .1);
	  cout << "Down" << endl;
    } // end if key pressed is down arrow
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      theHero.getSprite ().move(.1, 0);
	  cout << "Right" << endl;
    } // end if key pressed is right arrow
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      theHero.getSprite ().move(-.1, 0);
	  cout << "Left" << endl;
    } // end if key pressed is left arrow
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
    //	swing sword ??
    } // end else if keypressed is F

    frameCount.frameCounter += frameCount.frameSpeed*frameCount.mClock.restart().asSeconds();

    if (frameCount.frameCounter >= frameCount.frameSwitch)
    {
      frameCount.frameCounter = 0;
      theHero.setSourceY(theHero.getSource().y + 1);

      if ((theHero.getSource ().y * 32) >= theHero.getTexture ().getSize ().y )
      {
        theHero.setSourceY(0);
      } // end if theHero source y*32 >= theHero y-size
    } // end if frameCounter >= frameSwitch
	*/

	cout << "Room::draw" << endl;
	// sf::View mainBackground (sf::Vector2f (0, 0), sf::Vector2f (1, 1) );
	sf::View mainBackground (sf::Vector2f (theHero.getSprite ().getPosition ().x, 
		                     theHero.getSprite ().getPosition ().y ),
                             sf::Vector2f (16, 16) );
	// cout << "X: " << theHero.getSprite ().getPosition ().x
	//	 << "Y: " << theHero.getSprite ().getPosition ().y << endl;
	mainBackground.setSize (48, 48);
	mainBackground.setCenter (0, 0);
	mainBackground.zoom (5);
	
	/*
	if (!theHero.getFlag () )
    {
		cout << "getFlag = false" << endl;
      theHero.getSprite ().setTextureRect (sf::IntRect (theHero.getSource ().x * 32,
                                           theHero.getSource ().y * 32,
                                           theHero.getSize ().width, 32) );
    } // end if getFlag is false
    else
    {
		cout << "getFlag = true" << endl;
      theHero.getSprite ().setTextureRect (sf::IntRect (0, 32, 32, 32) );
    } // end else, getFlag is true
	*/

	// theHero.getSprite ().setTextureRect (sf::IntRect (0, 32, 32, 32) );
	// theHero.getSprite ().setTextureRect (sf::IntRect (0, 32, 32, 32) );
	// theHero.getSprite ().setTexture (theHero.getTexture () );
	// theHero.getSprite ().setTexture (testTexture);
	
	
		// load default image to testSprite
	testSprite.setTextureRect (sf::IntRect (32, 32, 32, 32) ); // this works
	theHero.setSprite (testSprite); // set theHero.mSprite with testSprite

	theWindow.clear (sf::Color::White);
	theWindow.setView (mainBackground);
	// sf::RenderWindow newWindow;
	// newWindow.create (sf::VideoMode (800, 600), "Test" );
	// newWindow.draw (mGameMap);
	theWindow.draw(mGameMap);
	// theWindow.draw(theHero.getSprite () );
	theWindow.draw (theHero.getSprite () );
	// cout << "theHero.getSource.x: " << theHero.getSource ().x << endl;
	// theWindow.draw (theActor.mSprite);
	// theWindow.draw (testSprite);

} // end draw function