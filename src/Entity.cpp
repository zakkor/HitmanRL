#include "Entity.hpp"

Entity::Entity()
{

}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void Entity::assignTexture(ResourceHandler<sf::Texture, TileSets::ID> &tileSets)
{
    sprite.setTexture(tileSets.get(TileSets::DEFAULT));

    int textureXpos = 0;
    int textureYpos = 0;

    for (int i = textureNumber - 1; i >= 0; i--)
    {
        textureXpos += 64;
        if (textureXpos >= 1024)
        {
            textureXpos = 0;
            textureYpos += 64;
        }
    }
    sprite.setTextureRect(sf::IntRect(textureXpos, textureYpos, 64, 64));
}
