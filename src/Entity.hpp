#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "ResourceIdentifier.hpp"
#include "ResourceHandler.h"

class Entity : public sf::Drawable
{
public:
    Entity();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void assignTexture(ResourceHandler<sf::Texture, TileSets::ID> &tileSets);

//private:
    bool isSolid;
    sf::Sprite sprite;
    Textures::ID textureNumber;
    int volume; // in cm^3
};

#endif // ENTITY_H
