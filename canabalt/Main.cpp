// --------------------------------------
// Includes
// --------------------------------------
// Libraries
#include <SFML/Graphics.hpp>

//project includes
#include "AssetManager.h"

int main()
{
	// --------------------------------------
	// Game Setup
	// --------------------------------------

	// Render Window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack A Critter",
		sf::Style::Titlebar | sf::Style::Close);

	// Timer functionality
	sf::Clock gameClock;

	//create assetmanager
	AssetManager assets;

	//testing assetmanager
	sf::Sprite testSprite;
	testSprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));

	sf::Sound testSound;
	testSound.setBuffer(AssetManager::GetSoundBuffer("audio/death.wav"));
	testSound.play();

	// end game setup
	// --------------------------------------


	// --------------------------------------
	// Game Loop
	// --------------------------------------
	while (gameWindow.isOpen())
	{
		// --------------------------------------
		// Input
		// --------------------------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			} // End if (closed)
		} // end event polling loop

		// end input
		// --------------------------------------


		// --------------------------------------
		// Update
		// --------------------------------------
		sf::Time frameTime = gameClock.restart();

		// end update
		// --------------------------------------



		// --------------------------------------
		// Draw
		// --------------------------------------

		// Clear the window to a single colour
		gameWindow.clear();

		// Draw Everything
		gameWindow.draw(testSprite);

		// Display the window contents to the screen
		gameWindow.display();

		// end draw
		// --------------------------------------

	} // end of the game while loop

	// end game loop
	// --------------------------------------

	// exit point for the program
	return 0;

} // end of the main() function
