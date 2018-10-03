// Library includes
#include <cstdlib>

//Project files
#include "Platform.h"
#include "AssetManager.h"

// Constants
#define SIZE_X_MIN 10
#define SIZE_Y_MIN 1
#define SIZE_X_MAX 30
#define SIZE_Y_MAX 5
#define POS_Y_MIN 800
#define POS_Y_MAX 1000


Platform::Platform()
	: m_sprites()
{
	m_sprites.setTexture(AssetManager::GetTexture("graphics/block.png"));
}

void Platform::Spawn()
{
	//choose a random size for our platform
	sf::Vector2i size;
	size.x = rand() % (SIZE_X_MAX - SIZE_X_MIN) + SIZE_X_MIN;
	size.y = rand() % (SIZE_Y_MAX - SIZE_Y_MIN) + SIZE_Y_MIN;
	m_sprites.setScale(size.x, size.y);

	//Choose a random y position
	sf::Vector2f position;
	position.y = rand() % (POS_Y_MAX - POS_Y_MIN) + POS_Y_MIN;
	position.x = 0; //TODO DISTANCE FROM LAST PLATFORM
	m_sprites.setPosition(position);
}

void Platform::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprites);
}