// Project includes
#include "Animation.h"

Animation::Animation()
	: m_frames ()
	, m_sprite (nullptr)
	, m_playBackSpeed (15.0f)
	, m_loop (false)
	, m_playing (false)
	, m_nextFrameChange ()
	, m_currentFrame (0)
{

}

void Animation::Update(sf::Time _frameTime)
{
	//Is it time to change to a new frame
	m_nextFrameChange -= _frameTime;
	if (m_nextFrameChange.asSeconds() <= 0)
	{
		//It is time to change frame

		//Change to the next frame
		++m_currentFrame;

		//did we reach the end frame
		if (m_currentFrame >= m_frames.size())
		{
			//we reached the end

			//TODO WHAT IF NO LOOP

			//Wrap around to the beginning
			m_currentFrame = 0;
		}
		//update the sprites texture to match the frame of the animation
		//does our sprite exist
		if (m_sprite)
		{
			m_sprite->setTexture(*m_frames[m_currentFrame]);
		}

		//Determine time for next frsame change
		float timeToChange = 1.0f / m_playBackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}
}

void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(&_newFrame);
}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;
}

