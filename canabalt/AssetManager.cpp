//Library Includes
#include <assert.h>

//project includes
#include "AssetManager.h"

//initialise the static reference to our instance - to nullptr aka zero
AssetManager* AssetManager::s_instance = nullptr;

//constructor
AssetManager::AssetManager()
	: m_textures ()
	, m_soundBuffers ()
	, m_fonts ()
{
	// throw an error and stop execution (in debug mode) if a copy of this class had already been created
	assert(s_instance == nullptr);

	//assign ourselves to the instance pointer
	// -this is the new instance of the class that has just been created
	s_instance = this;
}


sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	//create an iterator to hold a key and value pair
	// and search for the required key using the passed in file name
	auto keyValuePair = s_instance->m_textures.find(_fileName);
	//auto is in this case is equivilant to writing map std::map<std::string,sf::Texture>::iterator
	//auto can be used in cases where the compiler can figure out the type of a variable for you

	//Did we find the texture(aka was it already loaded?)
	// (iterator will be at the end if we did NOT find it)
	if (keyValuePair != s_instance->m_textures.end())
	{
		//yes we found it
		return keyValuePair->second;
	}
	else
	{
		//no we didnt find it so we create it
		//create a new key pair using the filename
		//the subscript [] operator creates an entry in the map if there is not already one there

		sf::Texture& texture = s_instance->m_textures[_fileName];
		//blank texture has been created
		//now just load it from file using sfml
		texture.loadFromFile(_fileName);

		//return the texture to the calling code
		return texture;

	}

}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string _fileName)
{
	auto keyValuePair = s_instance->m_soundBuffers.find(_fileName);

	if (keyValuePair != s_instance->m_soundBuffers.end())
	{
		//we did find it
		return keyValuePair->second;
	}
	else
	{
		sf::SoundBuffer& soundBuffer = s_instance->m_soundBuffers[_fileName];
		soundBuffer.loadFromFile(_fileName);
		return soundBuffer;
	}
}