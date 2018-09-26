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
	//Only process the animation if ity is playing
	if (m_playing)
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

				//should we loop
				if (m_loop)
				{
					//Wrap around to the beginning
					m_currentFrame = 0;
				}
				else
				{
					//we shouldnt loop

					//set our frame as the last in the list
					m_currentFrame = m_frames.size() - 1;

					//stop playback
					m_playing = false;
				}			
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
}

void Animation::Play()
{
	// update our sprite to the current frame immidiatly
	if (m_sprite)
	{
		m_sprite->setTexture(*m_frames[m_currentFrame]);
	}
	//only start playing and set playtime if playback speed isnt zero 
	if (m_playBackSpeed != 0)
	{
		//set playback to true
		m_playing = true;

		//Determine time for next frsame change
		float timeToChange = 1.0f / m_playBackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}
}

void Animation::Pause()
{
	//stop playback keeping current frame as it is
	m_playing = false;
}

void Animation::Stop()
{
	// Stop playback and reset frame to first frame
	m_playing = false;
	m_currentFrame = 0;
}

bool Animation::IsPlaying()
{
	//Tell the calling code if it is being played
	return m_playing;
}

void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(&_newFrame);
}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;
}

void Animation::SetPlayBackSpeed(float _framesPerSecond)
{
	m_playBackSpeed = _framesPerSecond;

	//If the playback speed is 0 pause to protect from divide by 0 error
	if (m_playBackSpeed == 0)
		Pause();
}

void Animation::SetLoop(bool _loop)
{
	m_loop = _loop;
}