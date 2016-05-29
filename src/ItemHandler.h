//
// Created by Edward on 07-May-15.
//

#ifndef HITMANRL_ITEMHANDLER_H
#define HITMANRL_ITEMHANDLER_H
#include "Item.h"


class ItemHandler
{
public:
    ItemHandler();
    void addExistingItem_toItemList(Item item);

    std::vector<Item> itemList;
};


#endif //HITMANRL_ITEMHANDLER_H
