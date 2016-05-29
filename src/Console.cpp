#include "Console.hpp"

Console::Console(sf::Font &font)
{
    cdv.resize(0);

    activeFont = &font;

    consoleBg.setFillColor(sf::Color(30, 30, 30, 128));
    consoleBg.setPosition(0, 0);
    consoleBg.setSize(sf::Vector2f(1280, 180));

    consoleView.setCenter(sf::Vector2f(1280 / 2, 180 / 2));
    consoleView.setSize(sf::Vector2f(1280, 180));
    consoleView.setViewport(sf::FloatRect(0, 0.75f, 1, 0.25));

    visible = true;
}

Console::~Console()
{
    activeFont = nullptr;
}


void Console::log(std::string str, sf::Color color)
{
    for (int i = 0; i < cdv.size(); i++)
    {
        cdv.at(i).move(0, 30);
        cdv.at(i).setColor(sf::Color(cdv.at(i).getColor().r, cdv.at(i).getColor().g, cdv.at(i).getColor().b,
                                     cdv.at(i).getColor().a - 30));
    }

    cdv.resize(6);

    sf::Text t;
    t.setFont(*activeFont);
    t.setCharacterSize(24);
    t.setColor(sf::Color::White);
    t.setString(str);
    t.setColor(color);
    t.setPosition(20, 10);
    cdv.push_front(t);
}

void Console::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.setView(consoleView);
    target.draw(consoleBg, states);
    for (int i = 0; i < cdv.size(); i++)
    {
        target.draw(cdv.at(i));
    }
    target.setView(target.getDefaultView());
}

void Console::clear()
{
    cdv.clear();
}
