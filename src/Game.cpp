#include "Game.hpp"

Game::Game()
{
    fpsVar = 0;
    window.create(sf::VideoMode(1280, 720), "HitmanRL", sf::Style::Default);

    mMusicPlayer.play(Music::SQUAD);
}

void Game::run()
{
    while (window.isOpen())
    {
        showFps();
        process();
        render();
    }
}

void Game::showFps()
{
    int elapsedTime = fpsCounter.getElapsedTime().asMilliseconds();

    if (elapsedTime >= 1000)
    {
        //std::cout << fpsVar << "\n";
        fpsCounter.restart();
        fpsVar = 0;
    }
    else
        fpsVar++;
}

void Game::processInput(sf::Keyboard::Key key)
{
    actionTime = world.update(key);
    update();
}

void Game::process()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
            processInput(event.key.code);
        if (event.type == sf::Event::MouseMoved)
        {
            if (event.mouseMove.x > 64)
            {
//                window.close();
            }
        }
    }
}

void Game::update()
{
    time.updateTime(actionTime);

    for (auto &npc : world.npcHandler.npcList)
    {
        npc.followActor(world.player);
//        cout << "[begin update]\n";
        while (actionTime > 0 && !npc.actionQueue.empty())
        {
            if (actionTime < npc.actionQueue.front().duration)
            {
                npc.actionQueue.front().duration -= actionTime;
                break;
            }
            else
            {
                if (npc.actionQueue.front().type == ACTION_TYPE::MOVE)
                {
                    switch (npc.actionQueue.front().dir)
                    {
                        case DIRECTION::UP:
                            if (world.isWalkable(npc.sprite.getPosition().x , (npc.sprite.getPosition().y - 64)))
                            {
                                npc.move(npc.actionQueue.front().dir);
                            }
                            break;
                        case DIRECTION::DOWN:
                            if (world.isWalkable(npc.sprite.getPosition().x, (npc.sprite.getPosition().y + 64)))
                            {
                                npc.move(npc.actionQueue.front().dir);
                            }
                            break;
                        case DIRECTION::LEFT:
                            if (world.isWalkable((npc.sprite.getPosition().x - 64), npc.sprite.getPosition().y))
                            {
                                npc.move(npc.actionQueue.front().dir);
                            }
                            break;
                        case DIRECTION::RIGHT:
                            if (world.isWalkable((npc.sprite.getPosition().x + 64), npc.sprite.getPosition().y))
                            {
                                npc.move(npc.actionQueue.front().dir);
                            }
                            break;
                        default:
                            break;
                    }
                }
                if (npc.actionQueue.front().type == ACTION_TYPE::PICKUP)
                {

                }

                actionTime -= npc.actionQueue.front().duration;
                npc.actionQueue.pop();
            }
        }
//        cout << "[end update]\n";
    }

    std::cout << time.seconds << ":" << time.minutes << ":" << time.hours << '\n';
}

void Game::render()
{
    window.clear();

    world.draw(window);
//    window.draw(player);

    window.display();
}
