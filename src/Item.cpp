//
// Created by Edward on 07-May-15.
//

#include "Item.h"


Item::Item(TextureId textureNumber, ResourceHandler<sf::Texture, TileSets::ID> &tileSets)
{
    // TODO: refactor
    this->isSolid = false;
    this->maxCapacity = 0;
    this->usedCapacity = 0;
    this->isContainer = false;
    this->isDoor = false;
    this->doorIsOpen = false;
    this->isInsideContainer = false;
    this->isWeapon = false;
    this->name = "NO_NAME_ERROR";
    this->type = CONTAINER_TYPE::NOT_CONTAINER;
    this->volume = 0;
    this->weaponSpeed = 0;
    this->textureNumber = textureNumber;
    assignTexture(tileSets);
}

//Item::Item()
//{
//
//}

//Item::Item(Textures::ID textureNumber, bool isSolid, std::string name, int volume)
//{
//    isInsideContainer = false;
//    this->textureNumber = textureNumber;
//    this->isSolid = isSolid;
//    this->name = name;
//    this->volume = volume;
//}

bool Item::hasEnoughRoomFor(Item item)
{
    return usedCapacity + item.volume <= maxCapacity;
}

void Item::addItem(Item item)
{
    if (hasEnoughRoomFor(item))
    {
        usedCapacity += item.volume;
        item.isInsideContainer = true;
        item.sprite.setColor(sf::Color::Transparent);
        items_contained.push_back(item);

    }

}

void Item::doortoggleOpenClose()
{
    doorIsOpen = !doorIsOpen;
    isSolid = !isSolid;
    if (doorIsOpen)
    {
        sprite.setColor(sf::Color(255, 255, 255, 255 / 2));
    }
    else
    {
        sprite.setColor(sf::Color(255, 255, 255, 255));
    }
}
