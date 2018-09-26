//Library include
#include <assert.h>

// Project include
#include "AnimationSystem.h"

AnimationSystem::AnimationSystem()
	: m_sprite (nullptr)
	, m_animations ()
	, m_currentAnimation (nullptr)
{

}

void AnimationSystem::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;

	//Update all sprite for the animations already in the map
	for (auto it = m_animations.begin(); it != m_animations.end(); ++it)
	{
		it->second.SetSprite(_sprite);
	}
}

Animation& AnimationSystem::CreateAnimation(std::string _name)
{
	//throw an error if this animation is already in the system
	assert(m_animations.find(_name) == m_animations.end());

	// Create the animation using array notation
	Animation& newAnimation = m_animations[_name];

	//set up the sprite for the animation
	if (m_sprite)
	{
		newAnimation.SetSprite(*m_sprite);
	}

	return newAnimation;
}