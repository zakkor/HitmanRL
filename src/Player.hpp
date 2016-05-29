#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include "Actor.hpp"
#include "Npc.hpp"
#include "Console.hpp"
#include "Utils.h"
#include "NpcHandler.h"
#include "ItemHandler.h"
#include "Menu.h"

class Player : public Actor
{
public:
    Player(ResourceHandler<sf::Texture, TileSets::ID> &tileSets);
    void populateWeaponList();

    bool canWalk(NpcHandler &npcHandler, ItemHandler &itemHandler, int x, int y);

    unsigned int update(sf::Keyboard::Key key, NpcHandler &npcHandler, ItemHandler &itemHandler, sf::View &gameView, std::vector<Menu> &menus, Console &console);

    //TODO: add picking up and holding items in hands, and transferring items from containers to hands and other containers
    //TODO: add multiple containers: backpacks, pockets in clothing

    std::map<int, Item &> weapons;
    bool wantsToMove;
    bool currentlyLooking;
    bool lookingForDoorDirection;
    bool lookingForTarget;
    bool foundTarget;
    Npc *targetNpc;
    int selectedWeaponIndex;
    bool lookingForWeapon;
    bool foundWeapon;
    sf::RectangleShape lookRectangle;
    bool updatedLookRectangle;

private:
    void pickUpFirstItemAtFeet(NpcHandler &npcHandler, ItemHandler &itemHandler, unsigned int &actionTime, std::vector<Menu> &menus, Console &console);

//    sf::View guiView;
//    Menu inventoryMenu;
//    Menu attackMenu;
};

#endif // PLAYER_H
