#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Time.h"
#include "World.h"
#include "Utils.h"
#include "MusicPlayer.hpp"
#include "SoundPlayer.hpp"

class Game
{
public:
    Game();

    void run();

private:
    sf::Clock fpsCounter; int fpsVar;
    void showFps();

    void processInput(sf::Keyboard::Key key);

    void process();

    void update();

    void render();

    sf::RenderWindow window;

    World world;

    MusicPlayer mMusicPlayer;
    SoundPlayer mSoundPlayer;

    Time time;
    unsigned int actionTime;

    //TODO: items incoming;
};
