#ifndef MUSICPLAYER_HPP_INCLUDED
#define MUSICPLAYER_HPP_INCLUDED

#include "ResourceHandler.h"
#include "ResourceIdentifier.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>

class MusicPlayer : private sf::NonCopyable
{
	public:
									MusicPlayer();

		void						play(Music::ID theme);
		void						stop();

		void						setPaused(bool paused);
		void						setVolume(float volume);


	private:
		sf::Music							mMusic;
		std::map<Music::ID, std::string>	mFilenames;
		float								mVolume;
};

#endif // MUSICPLAYER_HPP_INCLUDED
