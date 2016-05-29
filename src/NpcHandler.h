//
// Created by Edward on 05-May-15.
//

#ifndef HITMANRL_NPCHANDLER_H
#define HITMANRL_NPCHANDLER_H
#include "Npc.hpp"
#include <vector>

//class Npc;

using std::vector;

class NpcHandler
{
public:
    NpcHandler();

    void addNpc(ResourceHandler<sf::Texture, TileSets::ID> &tileSets, Console &console);

    vector<Npc> npcList;
};


#endif //HITMANRL_NPCHANDLER_H
