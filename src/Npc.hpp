#ifndef NPC_H
#define NPC_H
#include <string>
#include <stdlib.h>
#include <iostream>
#include <queue>

#include "Actor.hpp"
#include "Action.h"
#include "ResourceHandler.h"

using std::string;
using std::queue;

class Npc : public Actor
{
public:
    Npc(ResourceHandler<sf::Texture, TileSets::ID> &tileSets, Console &console);
    Npc(Textures::ID textureNumber, ResourceHandler<sf::Texture, TileSets::ID> &tileSets, Console &console);
    void addAction(Action action);
//    void addMoveAction(MoveAction moveAction);
//    void addPickupAction(PickupAction pickupAction);
    void followActor(Actor actor);

    queue<Action> actionQueue;
//    queue<MoveAction> moveActionQ;
//    queue<PickupAction> pickupActionQ;
};

#endif // NPC_H
