#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <deque>
#include <sstream>
#include "SFML/Graphics.hpp"

class Console : public sf::Drawable
{
public:
    Console(sf::Font &font);
    ~Console();
    void clear();
    void log(std::string str, sf::Color color);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool visible;
private:
    sf::Font *activeFont;
    std::deque<sf::Text> cdv; ///console draw vector
    sf::RectangleShape consoleBg;
    sf::View consoleView;
};

//namespace Console
//{
//    void init(sf::Font &font);
//    void clear();
//    void log(std::string str, sf::Color color);
//    void draw(sf::RenderWindow &window);
//
//    extern sf::Font activeFont;
//    extern std::deque<sf::Text> cdv; ///console draw vector
//    extern sf::RectangleShape consoleBg;
//    extern sf::View consoleView;
//    extern bool visible;
//
//}

#endif // CONSOLE_H
