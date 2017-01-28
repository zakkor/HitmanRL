//
// Created by Edward on 20-May-15.
//

#include "World.h"

World::World()
    : tileSets(TileSets::DEFAULT, "res/textures/tileset.png"),
      fonts(Fonts::ARIAL, "res/fonts/arial.ttf"),
      tileMap(tileSets),
      player(tileSets),
      console(fonts.get(Fonts::ARIAL))
{
    tileSize.x = 64;
    tileSize.y = 64;

    gameView.setCenter(sf::Vector2f(player.sprite.getPosition().x, player.sprite.getPosition().y));
    gameView.setSize(sf::Vector2f(1280, 720));
    gameView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));


    npcHandler.addNpc(tileSets, console);

    // Item contty(Textures::SHADOW, tileSets);
    // contty.isContainer = true;
    // contty.isInsideContainer = false;
    // contty.name = "Beige Mountain Backpack";
    // contty.volume = 0;
    // contty.type = CONTAINER_TYPE::BACKPACK;
    // contty.usedCapacity = 0;
    // contty.maxCapacity = 250;
    // contty.sprite.setPosition(64 * 7, 64 * 3);
    // itemHandler.addExistingItem_toItemList(contty);

    // Item leBat(Textures::STONEFLOOR, tileSets);
    // leBat.isInsideContainer = false;
    // leBat.isWeapon = true;
    // leBat.weaponSpeed = 3;
    // leBat.name = "Steel bat";
    // leBat.volume = 0;
    // leBat.maxCapacity = 0;
    // leBat.sprite.setPosition(64 * 9, 64 * 3);
    // leBat.isContainer = false;
    // itemHandler.addExistingItem_toItemList(leBat);

    // Item wall1(Textures::WALL, tileSets);
    // wall1.isInsideContainer = false;
    // wall1.isWeapon = false;
    // wall1.weaponSpeed = -1;
    // wall1.name = "Brick wall";
    // wall1.volume = 200000;
    // wall1.maxCapacity = 0;
    // wall1.isContainer = false;
    // wall1.isDoor = false;
    // wall1.isSolid = true;
    // wall1.sprite.setPosition(64 * 12, 64 * 3);
    // itemHandler.addExistingItem_toItemList(wall1);

    // Item door1(Textures::SHADOW, tileSets);
    // door1.isDoor = true;
    // door1.doorIsOpen = false;
    // door1.volume = 200000;
    // door1.isSolid = true;
    // door1.sprite.setPosition(64 * 12, 64 * 6);
    // door1.name = "Wooden door";
    // itemHandler.addExistingItem_toItemList(door1);

    tileMap.reload();

    npcHandler.npcList.at(0).stats.movementSpeed = 6;

    Menu inventoryMenu(400, 500);
    menus.push_back(inventoryMenu);
    Menu attackMenu(600, 500);
    menus.push_back(attackMenu);
}

bool World::isWalkable(int x, int y)
{
    for (auto &item : itemHandler.itemList)
    {
        if (!item.isInsideContainer)
            if (item.sprite.getPosition().x == x &&
                item.sprite.getPosition().y == y)
                    if (item.isSolid)
                        return false;
    }
    return true;
}

void World::draw(sf::RenderWindow &window)
{
    window.setView(gameView);
    window.draw(tileMap);

    for (auto &item : itemHandler.itemList)
    {
        if (!item.isInsideContainer)
            window.draw(item);
    }
    for (auto &npc : npcHandler.npcList)
    {
        window.draw(npc);
    }

    window.draw(player);

    if (player.currentlyLooking)
    {
        window.draw(player.lookRectangle);
    }

    if (console.visible)
    {
        window.draw(console);
    }
    if (menus.at(MENU_TYPES::INVENTORY).visible)
    {
        menus.at(MENU_TYPES::INVENTORY).draw(window);
    }
    if (menus.at(MENU_TYPES::ATTACK).visible)
    {
        menus.at(MENU_TYPES::ATTACK).draw(window);
    }
}

int World::update(sf::Keyboard::Key key)
{
    switch (key)
    {
        case sf::Keyboard::C:
            console.visible = !console.visible;
            break;
        case sf::Keyboard::I:
            menus.at(MENU_TYPES::INVENTORY).visible = !menus.at(MENU_TYPES::INVENTORY).visible;
            break;
        case sf::Keyboard::A:
            menus.at(MENU_TYPES::ATTACK).visible = !menus.at(MENU_TYPES::ATTACK).visible;
//            menus.at(1).visible = !menus.at(1).visible;
            break;
        default:
            break;
    }

    return player.update(key, npcHandler, itemHandler, gameView, menus, console);
}


//void World::updateNpcs(Player &player, unsigned int &actionTime)
//{
//    for (auto &npc : npcHandler.npcList)
//    {
//        npc.followActor(player);
//        cout << "[begin update]\n";
//        while (actionTime > 0 && !npc.actionQueue.empty())
//        {
//            if (actionTime < npc.actionQueue.front().duration)
//            {
//                npc.actionQueue.front().duration -= actionTime;
//                break;
//            }
//            else
//            {
//                if (npc.actionQueue.front().type == ACTION_TYPE::MOVE)
//                {
//                    switch (npc.actionQueue.front().dir)
//                    {
//                        case DIRECTION::UP:
//                            if (isWalkable(npc.sprite.getPosition().x , (npc.sprite.getPosition().y - 64)))
//                            {
//                                npc.move(npc.actionQueue.front().dir);
//                            }
//                            break;
//                        case DIRECTION::DOWN:
//                            if (isWalkable(npc.sprite.getPosition().x, (npc.sprite.getPosition().y + 64)))
//                            {
//                                npc.move(npc.actionQueue.front().dir);
//                            }
//                            break;
//                        case DIRECTION::LEFT:
//                            if (isWalkable((npc.sprite.getPosition().x - 64), npc.sprite.getPosition().y))
//                            {
//                                npc.move(npc.actionQueue.front().dir);
//                            }
//                            break;
//                        case DIRECTION::RIGHT:
//                            if (isWalkable((npc.sprite.getPosition().x + 64), npc.sprite.getPosition().y))
//                            {
//                                npc.move(npc.actionQueue.front().dir);
//                            }
//                            break;
//                        default:
//                            break;
//                    }
//                }
//                if (npc.actionQueue.front().type == ACTION_TYPE::PICKUP)
//                {
//
//                }
//
//                actionTime -= npc.actionQueue.front().duration;
//                npc.actionQueue.pop();
//            }
//        }
//        cout << "[end update]\n";
//    }
//}
