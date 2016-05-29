//
// Created by Edward on 05-May-15.
//

#ifndef HITMANRL_ACTION_H
#define HITMANRL_ACTION_H

#include "Actor.hpp"

enum ACTION_TYPE
{
    MOVE,
    PICKUP
};

class Action
{
public:
    Action();

    ACTION_TYPE type;
    unsigned int duration;
    //this would ONLY be needed for the movement actions
    DIRECTION::DIRECTION dir;
    //and this would ONLY be needed for the pickup actions
//    Item& itemToPickup;
};


#endif //HITMANRL_ACTION_H
