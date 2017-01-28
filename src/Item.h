//
// Created by Edward on 07-May-15.
//

#ifndef HITMANRL_ITEM_H
#define HITMANRL_ITEM_H

#include "Entity.hpp"


enum CONTAINER_TYPE
{
    NOT_CONTAINER,
    BACKPACK
};

class Item : public Entity
{
public:
    Item(TextureId textureNumber, ResourceHandler<sf::Texture, TileSets::ID> &tileSets);

    /* Weapon related stuff */
    bool isWeapon;
    int weaponSpeed;
    /*~~~~~~~~~~~~~~~~~~~~~~*/

    /* Container related stuff */
    bool hasEnoughRoomFor(Item item);
    void addItem(Item item);
    bool isContainer;
    CONTAINER_TYPE type;
    unsigned int maxCapacity;
    unsigned int usedCapacity;
    std::vector<Item> items_contained;
    /*~~~~~~~~~~~~~~~~~~~~~~~~~*/

    /* Door related stuff */
    bool isDoor;
    bool doorIsOpen;
    void doortoggleOpenClose();
    /*~~~~~~~~~~~~~~~~~~~~*/

    bool isInsideContainer;
    std::string name;
};


#endif //HITMANRL_ITEM_H
