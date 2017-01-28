#ifndef ENTITY_H
#define ENTITY_H

#include "ResourceHandler.h"
#include "ResourceIdentifier.hpp"
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
    public:
    Entity ();

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    void assignTexture (ResourceHandler<sf::Texture, TileSets::ID>& tileSets);

    // private:
    bool isSolid;
    sf::Sprite sprite;
    TextureId textureNumber;
    int volume; // in cm^3
};

#endif // ENTITY_H
