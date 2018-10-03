#pragma once
//Library include
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

//Project Includes
#include "AnimationSystem.h"


class Player
{

public:

	Player();

	void Input(sf::Event _gameEvent);
	void Update(sf::Time _frameTime);
	void Draw(sf::RenderTarget& _target);

	void Spawn();

	sf::Vector2f GetPosition();

	void HandleCollision(std::vector<sf::FloatRect> _platform);

private:

	//assets
	sf::Sprite m_sprite;
	sf::Sound m_jumpSound;
	sf::Sound m_deathSound;
	sf::Sound m_landSound;
	AnimationSystem m_animation;

	//State
	sf::Vector2f m_velocity;
	bool m_touchingGround;
};