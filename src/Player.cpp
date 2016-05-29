#include "Player.hpp"

//Player::Player(ResourceHandler<sf::Texture, TileSets::ID> &tileSets) : inventoryMenu (400, 500), attackMenu (600, 600)
Player::Player(ResourceHandler<sf::Texture, TileSets::ID> &tileSets)
{
//    inventory = Container(Textures::ID::MUD, false, "backpack",
//                         ITEM_CATEGORY::CONTAINER, 20, 15);
    backpackSlotOccupied = false;
    textureNumber = Textures::PLAYER;
    assignTexture(tileSets);
//    isSolid = true;
    volume = 70000;


    lookRectangle.setFillColor(sf::Color(255, 255, 0, 255 / 2));
    lookRectangle.setSize(sf::Vector2f(64, 64));
    lookRectangle.setPosition(0, 0);

    currentlyLooking = false;
    lookingForDoorDirection = false;
    lookingForTarget = false;
    foundTarget = false;
    lookingForWeapon = false;
    foundWeapon = false;
    selectedWeaponIndex = -1;
    updatedLookRectangle = false;
    wantsToMove = false;
    //TODO: Add body parts usable as weapons



//    guiView.setSize(1280, 720);
//    guiView.setCenter(1280/2, 720/2);
}

void Player::populateWeaponList()
{
    weapons.clear();
    for (auto &container : clothes)
    {
        for (int i = 0; i < container.items_contained.size(); i++)
        {
            if (container.items_contained.at(i).isWeapon)
            {
                weapons.emplace(i+1, container.items_contained.at(i));
                cout << "Populated weapon list with " << container.items_contained.at(i).name << " from the container called "
                     << container.name << "\n";
            }
        }
    }
}

bool Player::canWalk(NpcHandler &npcHandler, ItemHandler &itemHandler, int x, int y)
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



unsigned int Player::update(sf::Keyboard::Key key, NpcHandler &npcHandler, ItemHandler &itemHandler, sf::View &gameView, std::vector<Menu> &menus, Console &console)
{
    unsigned int actionTime = 0;
    int dx = 0, dy = 0;
    DIRECTION::DIRECTION dir;
    std::string directionStr;

    bool validKeypress = true;
    switch (key)
    {
    case sf::Keyboard::Up:
//            if (inventoryMenu.visible)
//            {
//                inventoryMenu.moveCursorUp();
//                break;
//            }
        if (lookingForWeapon)
            break;
        if (lookingForTarget || currentlyLooking || lookingForDoorDirection ||
                canWalk(npcHandler, itemHandler, sprite.getPosition().x, (sprite.getPosition().y - 64)))
        {
            dx = 0;
            dy = -64;
            dir = DIRECTION::UP;
            directionStr = "north";
            if (!lookingForTarget && !currentlyLooking && !lookingForDoorDirection)
                wantsToMove = true;
            break;
        }
        break;
    case sf::Keyboard::Down:
//            if (inventoryMenu.visible)
//            {
//                inventoryMenu.moveCursorDown();
//                break;
//            }
        if (lookingForWeapon)
            break;
        if (lookingForTarget || currentlyLooking || lookingForDoorDirection ||
                canWalk(npcHandler, itemHandler, sprite.getPosition().x, (sprite.getPosition().y + 64)))
        {
            dx = 0;
            dy = +64;
            dir = DIRECTION::DOWN;
            directionStr = "south";
            if (!lookingForTarget && !currentlyLooking && !lookingForDoorDirection)
                wantsToMove = true;
            break;
        }
        break;
    case sf::Keyboard::Left:
        if (lookingForWeapon)
            break;
        if (lookingForTarget || currentlyLooking || lookingForDoorDirection ||
                canWalk(npcHandler, itemHandler, (sprite.getPosition().x - 64), sprite.getPosition().y))
        {
            dx = -64;
            dy = 0;
            dir = DIRECTION::LEFT;
            directionStr = "west";
            if (!lookingForTarget && !currentlyLooking && !lookingForDoorDirection)
                wantsToMove = true;
            break;
        }
        break;
    case sf::Keyboard::Right:
        if (lookingForWeapon)
            break;
        if (lookingForTarget || currentlyLooking || lookingForDoorDirection ||
                canWalk(npcHandler, itemHandler, (sprite.getPosition().x + 64), sprite.getPosition().y))
        {
            dx = +64;
            dy = 0;
            dir = DIRECTION::RIGHT;
            directionStr = "east";
            if (!lookingForTarget && !currentlyLooking && !lookingForDoorDirection)
                wantsToMove = true;
            break;
        }
        break;
    case sf::Keyboard::Period:
    {
        if (lookingForTarget || lookingForWeapon || lookingForDoorDirection || currentlyLooking)
            break;

        actionTime = 10; //wait 10 seconds
        console.log(string("Waited for ").append(Utils::intToString(actionTime).append(" seconds")), sf::Color::White);
        break;
    }
    case sf::Keyboard::L:
        actionTime = 0;
        if (!lookingForDoorDirection && !lookingForTarget && !lookingForWeapon)
        {
            currentlyLooking = !currentlyLooking;
            lookRectangle.setPosition(sprite.getPosition());

            console.clear();

            if (!currentlyLooking)
            {
                gameView.setCenter(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y));
            }
            else
            {
                updatedLookRectangle = true;
            }
        }
        break;
    case sf::Keyboard::O:
        //TODO: make a stat that calculates how fast someone opens doors
        actionTime = 0;
        if (!currentlyLooking && !lookingForTarget && !lookingForWeapon)
        {
            lookingForDoorDirection = !lookingForDoorDirection;
            if (lookingForDoorDirection)
            {
                console.log("Which door would you like to open?", sf::Color::White);
            }
            else
            {
                console.clear();
            }
        }
        break;
    case sf::Keyboard::A:
        actionTime = 0;
        if (lookingForWeapon)
        {
            console.clear();
            lookingForWeapon = false;
            break;
        }

        if (!currentlyLooking && !lookingForDoorDirection)
        {
            lookingForTarget = !lookingForTarget;
            if (lookingForTarget)
            {
                console.clear();
                console.log("Who do you want to attack?", sf::Color::White);
            }
            else
            {
                console.clear();
            }
        }
        break;
    case sf::Keyboard::P:
        pickUpFirstItemAtFeet(npcHandler, itemHandler, actionTime, menus, console);
        break;
//        case sf::Keyboard::I:
//            if (inventoryMenu.visible)
//            {
//                inventoryMenu.visible = false;
//                console.visible = true;
//            }
//            else
//            {
//                inventoryMenu.visible = true;
//                console.visible = false;
//            }
        break;
    case sf::Keyboard::Num1:
        if (lookingForWeapon)
        {
            //TODO: replace this shit with weapon code
            foundWeapon = true;
            selectedWeaponIndex = 1;
            //TODO: detailed descriptions brah
            //TODO: some heavy duty shit needed here fam
        }
        break;

    case sf::Keyboard::Num2:
        if (lookingForWeapon)
        {
            //TODO: replace this shit with weapon code
            foundWeapon = true;
            selectedWeaponIndex = 2;
            //TODO: detailed descriptions brah
            //TODO: some heavy duty shit needed here fam
        }
        break;


    default:
        actionTime = 0;
        validKeypress = false;
        break;
    }

    if (validKeypress)
    {
        if (lookingForWeapon && foundWeapon)
        {
            //TODO: make this according to weapon speed / character stats
            lookingForWeapon = false;
            foundWeapon = false;
            actionTime = weapons.at(selectedWeaponIndex).weaponSpeed;

            console.clear();
            console.log(
                string("You hit ").append(targetNpc->stats.getFullName()).append(" in the [head] with your [").
                append(weapons.at(selectedWeaponIndex).name).append("]"), sf::Color::White);
            selectedWeaponIndex = -1;
        }
        if (lookingForTarget)
        {
            for (auto &npc : npcHandler.npcList)
            {
                if (npc.sprite.getPosition().x == sprite.getPosition().x + dx &&
                        npc.sprite.getPosition().y == sprite.getPosition().y + dy)
                {
                    foundTarget = true;
                    lookingForTarget = false;
                    targetNpc = &npc;
                    lookingForWeapon = true;

                    populateWeaponList();

                    if (!weapons.empty())
                    {
                        console.log("Select weapon:\n", sf::Color::White);
                        for (int i = 1; i < weapons.size() + 1; i++)
                        {
                            console.log(string("").append(Utils::intToString(i))
                                        .append(" - ").append(weapons.at(i).name), sf::Color::White);
                        }
                    }
                    else
                    {
                        console.clear();
                        console.log("You don't have any weapons", sf::Color::Red);
                        lookingForWeapon = false;
                    }



                    //TODO: do some inventory magic here
                }
            }
        }
        if (currentlyLooking)
        {
            lookRectangle.move(dx, dy);
            updatedLookRectangle = true;
        }
        if (lookingForDoorDirection)
        {
            for (auto &item : itemHandler.itemList)
            {
                if (!item.isDoor)
                    continue;
                if (item.sprite.getPosition().x == sprite.getPosition().x + dx &&
                        item.sprite.getPosition().y == sprite.getPosition().y + dy)
                {
                    if (dx != 0 || dy != 0)
                    {
                        actionTime = 5;
                        item.doortoggleOpenClose();
                        console.clear();
                        if (item.doorIsOpen)
                        {
                            console.log(std::string("You open a door to the ").append(directionStr), sf::Color::White);
                        }
                        else
                        {
                            console.log(std::string("You close a door to the ").append(directionStr), sf::Color::White);
                        }
                    }
                }
            }
        }
        if (wantsToMove)
        {
            if (canWalk(npcHandler, itemHandler, (sprite.getPosition().x + dx), (sprite.getPosition().y + dy)) &&
                    !lookingForDoorDirection && !lookingForTarget && !currentlyLooking && !lookingForWeapon)
            {
                move(dir);
//                console.log(std::string("Moved to the ").append(directionStr));
                gameView.setCenter(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y));
                actionTime = stats.movementSpeed;
                wantsToMove = false;
            }
        }

        if (updatedLookRectangle)
        {
            bool foundSomething = false;
            if (sprite.getPosition().x == lookRectangle.getPosition().x && sprite.getPosition().y ==
                    lookRectangle.getPosition().y)
            {
                string stringToDisplay = "Yourself (";
                stringToDisplay.append(stats.getFullName());
                stringToDisplay.append(")");
                console.log(stringToDisplay, sf::Color::White);
                foundSomething = true;
            }
            for (auto &npc : npcHandler.npcList)
            {
                if (npc.sprite.getPosition().x == lookRectangle.getPosition().x && npc.sprite.getPosition().y ==
                        lookRectangle.getPosition().y)
                {
                    console.log(npc.stats.getFullName(), sf::Color::White);
                    foundSomething = true;
                    break;
                }
            }
//            for (auto &wall : wallHandler.wallList)
//            {
//                if (wall.sprite.getPosition().x == lookRectangle.getPosition().x && wall.sprite.getPosition().y ==
//                                                                                    lookRectangle.getPosition().y)
//                {
//                    console.log("A brick wall", sf::Color::White);
//                    foundSomething = true;
//                    break;
//                }
//            }
//            for (auto &door : doorHandler.doorList)
//            {
//                if (door.sprite.getPosition().x == lookRectangle.getPosition().x && door.sprite.getPosition().y ==
//                                                                                    lookRectangle.getPosition().y)
//                {
//                    if (door.isOpen)
//                    {
//                        console.log("An open door", sf::Color::White);
//                    }
//                    else
//                    {
//                        console.log("A closed door", sf::Color::White);
//                    }
//                    foundSomething = true;
//                    break;
//                }
//            }
            for (auto &item : itemHandler.itemList)
            {
                if (item.sprite.getPosition().x == lookRectangle.getPosition().x && item.sprite.getPosition().y ==
                        lookRectangle.getPosition().y)
                {
                    if (item.isDoor)
                    {
                        if (item.doorIsOpen)
                        {
                            console.log(std::string("An opened ").append(item.name), sf::Color::White);
                        }
                        else
                        {
                            console.log(std::string("A closed ").append(item.name), sf::Color::White);
                        }
                    }
                    else
                    {
                        console.log(item.name, sf::Color::White);
                    }

                    foundSomething = true;
                    break;
                }
            }

            if (!foundSomething)
            {
                //                switch (tileMap.tiles[lookRectangle.getPosition().x / 64][lookRectangle.getPosition().y / 64])
                //                {
                //                    case Textures::GRASS:
                //                        console.log("Grass");
                //                        break;
                //                    default:
                //                        console.log("Look at:");
                //                        break;
                //                }
                console.clear();
            }

            gameView.setCenter(sf::Vector2f(lookRectangle.getPosition().x, lookRectangle.getPosition().y));
            updatedLookRectangle = false;
        }
    }
    return actionTime;
}

//void Player::draw(sf::RenderWindow &window)
//{
//    if (currentlyLooking)
//    {
//        window.draw(lookRectangle);
//    }
//    window.draw(sprite);
//
//
////    if (inventoryMenu.visible)
////    {
////        window.setView(guiView);
////        inventoryMenu.draw(window);
////        window.setView(window.getDefaultView());
////    }
////    if (attackMenu.visible)
////    {
////        window.setView(guiView);
////        attackMenu.draw(window);
////        window.setView(window.getDefaultView());
////    }
//}

void Player::pickUpFirstItemAtFeet(NpcHandler &npcHandler, ItemHandler &itemHandler, unsigned int &actionTime, std::vector<Menu> &menus, Console &console)
{
    for (int i = 0; i < itemHandler.itemList.size(); i++)
    {
        if (itemHandler.itemList.at(i).sprite.getPosition().x == sprite.getPosition().x &&
                itemHandler.itemList.at(i).sprite.getPosition().y == sprite.getPosition().y)
        {
            cout << "this is the crash";
            //make a copy of this item and add it to the player's inventory

            if (itemHandler.itemList.at(i).isContainer &&
                    itemHandler.itemList.at(i).type == CONTAINER_TYPE::BACKPACK)
            {
                if (!backpackSlotOccupied)
                {
                    actionTime = 5;
                    clothes.push_back(itemHandler.itemList.at(i));

//                    menus.at(MENU_TYPES::INVENTORY).addText(itemHandler.itemList.at(i).name.c_str(), ENTRY_TYPES::REGULAR);
                    console.log(
                        string("Picked up a [").append(itemHandler.itemList.at(i).name)
                        .append("]"), sf::Color::White);
                    itemHandler.itemList.erase(itemHandler.itemList.begin() + i);
                }
            }
            else
            {
                if (clothes.empty())
                {
                    actionTime = 0;
                    console.log("You have no container to put that item in", sf::Color::Red);
                    break;
                }
                for (auto &container : clothes)
                {
                    if (container.hasEnoughRoomFor(itemHandler.itemList.at(i)))
                    {
                        actionTime = 5;
                        container.addItem(itemHandler.itemList.at(i));

//                        menus.at(MENU_TYPES::INVENTORY).addText(itemHandler.itemList.at(i).name.c_str(), ENTRY_TYPES::REGULAR);

                        console.log(
                            string("Added a ").append(itemHandler.itemList.at(i).name)
                            .append(" to ").append(container.name), sf::Color::White);
                        //delete it from the itemHandler
                        itemHandler.itemList.erase(itemHandler.itemList.begin() + i);
                    }
                    else
                    {
                        actionTime = 0;
                        //do nothing
                        console.log("You don't have enough room to pick up this item", sf::Color::Red);
                    }
                }
            }


            //TODO: select which container to add the item to


            //TODO: picking up multiple items on the same position
            break;
        }
    }
}
