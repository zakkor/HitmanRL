//
// Created by Edward on 23-May-15.
//

#include "Menu.h"


Menu::Menu(size_t xSize, size_t ySize)
{
//    charSize = 12;
//    font.loadFromFile("arial.ttf");
    bg.setFillColor(sf::Color(70, 70, 70));
    bg.setSize(sf::Vector2f(xSize, ySize));
    bg.setPosition(1280/2 - bg.getSize().x / 2, 720/2 - bg.getSize().y /2);
    visible = false;
//    activeEntryNmbr = -1;
//    yOffset = bg.getSize().x / 10;
//    yOffset = bg.getSize().y / 10;
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(bg);
//    for (auto &shape : shapes)
//    {
//        window.draw(shape);
//    }
//    for (auto &entry : entries)
//    {
//        window.draw(entry.text);
//    }
}

//void Menu::addText(const char *text, ENTRY_TYPES::ENTRY_TYPES type)
//{
//    sf::Text newText(text, font, charSize);
//    newText.setColor(sf::Color::White);
//    if (type == ENTRY_TYPES::TITLE)
//    {
//        //make sure we dont accidentally overlap titles
//        for (auto &item : entries)
//        {
//            if (item.type == ENTRY_TYPES::TITLE)
//            {
//                return;
//            }
//        }
//        newText.setPosition(bg.getPosition().x + bg.getPosition().x / 20, bg.getPosition().y + bg.getPosition().y / 15);
//    }
//    else
//    {
//        if (entries.back().type == ENTRY_TYPES::TITLE)
//        {
//            newText.setPosition(entries.back().text.getPosition().x,
//                                entries.back().text.getPosition().y + yOffset);
//        }
//        else
//        {
//            newText.setPosition(entries.back().text.getPosition().x,
//                                entries.back().text.getPosition().y + yOffset);
//        }
//    }
//    entries.push_back(Entry(newText, type));
//
//    if (type == ENTRY_TYPES::REGULAR)
//    {
//        sf::RectangleShape newShape(sf::Vector2f(bg.getSize().x, bg.getSize().y / 10));
//        newShape.setFillColor(sf::Color(124, 124, 124, 255));
//        newShape.setOutlineThickness(2);
//        newShape.setOutlineColor(sf::Color(172, 172, 172));
//
//        if (shapes.empty())
//        {
//            newShape.setPosition(sf::Vector2f(bg.getPosition().x, bg.getPosition().y + bg.getSize().y / 10));
//        }
//        else
//        {
//            newShape.setPosition(shapes.back().getPosition().x, shapes.back().getPosition().y + bg.getSize().y / 10);
//        }
//
//        shapes.push_back(newShape);
//
//        if (activeEntryNmbr == -1)
//        {
//            activeEntryNmbr++;
//            shapes.at(activeEntryNmbr).setFillColor(sf::Color(172, 172, 172));
//        }
//    }
//
//
//
//}
//
//void Menu::moveCursorUp()
//{
//    if (activeEntryNmbr > 0)
//    {
//        shapes.at(activeEntryNmbr).setFillColor(sf::Color(124, 124, 124));
//        activeEntryNmbr--;
//        shapes.at(activeEntryNmbr).setFillColor(sf::Color(172, 172, 172));
//    }
//}
//
//void Menu::moveCursorDown()
//{
//    if (activeEntryNmbr < shapes.size() - 1)
//    {
//        shapes.at(activeEntryNmbr).setFillColor(sf::Color(124, 124, 124));
//        activeEntryNmbr++;
//        shapes.at(activeEntryNmbr).setFillColor(sf::Color(172, 172, 172));
//    }
//}
