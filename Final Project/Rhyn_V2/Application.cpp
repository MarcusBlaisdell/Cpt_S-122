#include "Application.h"

// start Game function
void Application::startGame ()
{
	World theWorld;

	sf::Texture spriteSheet;

		// load sprite sheet
	spriteSheet.loadFromFile ("Hero.png");

		// create a window
	mWindow.create (sf::VideoMode (800, 600), "The Adventures of Rhyn" );

	while (mWindow.isOpen () )
	{
		sf::Event gameEvent;

		while (mWindow.pollEvent (gameEvent) )
		{
			if (gameEvent.type == sf::Event::KeyPressed)
			{
				if (gameEvent.key.code == sf::Keyboard::Q)
				{
					mWindow.close ();
				} // end close window if Q is pressed
			} // end if key pressed

			switch (gameEvent.type)
			{
			case sf::Event::Closed:
				mWindow.close ();
				break;
			} // end switch case
		} // end while pollEvent gameEvent loop

		mWindow.clear   ();
		theWorld.draw   (mWindow);
		mWindow.display ();

	} // end while window is open
} // end startGame function