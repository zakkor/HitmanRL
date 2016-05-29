//
// Created by Edward on 07-May-15.
//

#include "ItemHandler.h"

//namespace ItemHandler
//{
//    std::vector<Item> itemList;
//
//}


ItemHandler::ItemHandler()
{
}

void ItemHandler::addExistingItem_toItemList(Item item)
{
    itemList.push_back(item);
}