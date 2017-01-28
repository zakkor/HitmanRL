#ifndef RESOURCEIDENTIFIER_HPP_INCLUDED
#define RESOURCEIDENTIFIER_HPP_INCLUDED

// Forward declaration of SFML classes
namespace sf
{
	class Texture;
	class Font;
//	class Shader;
	class SoundBuffer;
}

enum class TextureId
{
  GRASS = 0,
    MUD,
    WALL,
    PLAYER,
    NPC,
    STONEFLOOR,
    EMPTY,
    DOOR,
    SHADOW,
    TERRAIN_ENUM_SIZE
};

namespace SoundEffect
{
    enum ID
    {
        Harpsi = 0
    };
}

namespace Music
{
    enum ID
    {
        SQUAD = 0,
        HELLA_LIT
    };
}

namespace TileSets
{
    enum ID
    {
        DEFAULT = 0
    };
}

namespace Fonts
{
    enum ID
    {
        ARIAL = 0
    };
}


// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHandler;

typedef ResourceHandler<sf::Texture, TextureId>			TextureHolder;
typedef ResourceHandler<sf::Font, Fonts::ID>					FontHolder;
//typedef ResourceHandler<sf::Shader, Shaders::ID>				ShaderHolder;
typedef ResourceHandler<sf::SoundBuffer, SoundEffect::ID>	SoundBufferHolder;

#endif // RESOURCEIDENTIFIER_HPP_INCLUDED
