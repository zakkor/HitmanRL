//
// Created by Edward on 05-May-15.
//

#include "NpcHandler.h"

NpcHandler::NpcHandler()
{
}

void NpcHandler::addNpc(ResourceHandler<sf::Texture, TileSets::ID> &tileSets, Console &console)
{
    Npc newNpc = Npc(TextureId::NPC, tileSets, console);
    npcList.push_back(newNpc);
}
