#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "Body.hpp"
#include "Entity.hpp"
#include "Stats.hpp"
#include "Console.hpp"
#include "ItemHandler.h"

namespace DIRECTION { enum DIRECTION {UP, DOWN, LEFT, RIGHT}; }

class Actor : public Entity
{
public:
    Actor();

//    void pickUpFirstItemAtFeet(ItemHandler &itemHandler, Console &console, unsigned int &actionTime);
    void move(DIRECTION::DIRECTION dir);

    Body body;
    Stats stats;
    std::vector<Item> clothes; //these are all the items that the player can wear (backpack, shirt with pockets)
    bool backpackSlotOccupied;
};

#endif // ACTOR_HPP
