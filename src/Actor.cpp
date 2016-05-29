#include "Actor.hpp"

Actor::Actor()
{
    sprite.setPosition(0, 0);
}

void Actor::move(DIRECTION::DIRECTION dir)
{
    int dx = 0, dy = 0;
    int validDirection = true;
    switch (dir)
    {
        case DIRECTION::UP:
            dy = -64;
            break;
        case DIRECTION::DOWN:
            dy = +64;
            break;
        case DIRECTION::LEFT:
            dx = -64;
            break;
        case DIRECTION::RIGHT:
            dx = +64;
            break;
        default:
            validDirection = false;
            break;
    }

    if (validDirection)
    {
        sprite.setPosition(sprite.getPosition().x + dx, sprite.getPosition().y + dy);
    }
}

//void Actor::pickUpFirstItemAtFeet(ItemHandler &itemHandler, Console &console, unsigned int &actionTime)
//{
//    for (int i = 0; i < itemHandler.weaponList.size(); i++)
//    {
//        if (itemHandler.weaponList.at(i).sprite.getPosition().x == sprite.getPosition().x &&
//                itemHandler.weaponList.at(i).sprite.getPosition().y == sprite.getPosition().y)
//        {
//            //make a copy of this item and add it to the player's inventory
//            if (inventory.empty())
//            {
//                actionTime = 0;
//                console.log("You have no container to put that item in", sf::Color::Red);
//            }
//
//            for (auto &container : inventory)
//            {
//                if (container.hasEnoughRoomFor(itemHandler.weaponList.at(i)))
//                {
//                    actionTime = 5;
//                    container.addWeapon(itemHandler.weaponList.at(i));
//                    console.log(
//                            string("Added a ").append(itemHandler.weaponList.at(i).name)
//                                    .append(" to ").append(container.name), sf::Color::White);
//                    //delete it from the itemHandler
//                    itemHandler.weaponList.erase(itemHandler.weaponList.begin() + i);
//                }
//                else
//                {
//                    actionTime = 0;
//                    //do nothing
//                    console.log("You don't have enough room to pick up this item", sf::Color::Red);
//                }
//            }
//            //TODO: select which container to add the item to
//
//
//            //TODO: picking up multiple items on the same position
//            break;
//        }
//    }
//    for (int i = 0; i < itemHandler.containerList.size(); i++)
//    {
//        if (itemHandler.containerList.at(i).sprite.getPosition().x == sprite.getPosition().x &&
//                itemHandler.containerList.at(i).sprite.getPosition().y == sprite.getPosition().y)
//        {
//            if (itemHandler.containerList.at(i).type == BACKPACK)
//            {
//                if (!backpackSlotOccupied)
//                {
//                    inventory.push_back(itemHandler.containerList.at(i));
//                    console.log(
//                            string("Picked up a [").append(itemHandler.containerList.at(i).name)
//                                    .append("]"), sf::Color::White);
//                    itemHandler.containerList.erase(itemHandler.containerList.begin() + i);
//                }
//            }
//        }
//    }
//}

