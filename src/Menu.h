//
// Created by Edward on 23-May-15.
//

#ifndef HITMANRL_MENU_H
#define HITMANRL_MENU_H


#include <SFML/Graphics.hpp>
#include <vector>
//
namespace MENU_TYPES
{
    //each of these is guaranteed to be unique
    enum MENU_TYPES
    {
        INVENTORY,
        ATTACK
    };
}
//
//namespace ENTRY_TYPES
//{
//    enum ENTRY_TYPES
//    {
//        TITLE,
//        REGULAR
//    };
//}
//
//class Entry
//{
//public:
//    Entry(sf::Text text, ENTRY_TYPES::ENTRY_TYPES type)
//    {
//        this->text = text;
//        this->type = type;
//    }
//    sf::Text text;
//    ENTRY_TYPES::ENTRY_TYPES type;
//};

class Menu
{
public:
    Menu(size_t xSize, size_t ySize);
    void draw(sf::RenderWindow &window);
//    void addText(const char *text, ENTRY_TYPES::ENTRY_TYPES type);
//    void moveCursorUp();
//    void moveCursorDown();

////    int xOffset;
//    int yOffset;
//
//    size_t charSize;
//
//    sf::Font font;

    sf::RectangleShape bg;
//
//    std::vector<Entry> entries;
//    std::vector<sf::RectangleShape> shapes;
//
//    short activeEntryNmbr;

    bool visible;
};


#endif //HITMANRL_MENU_H
