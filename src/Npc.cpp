#include "Npc.hpp"

Npc::Npc(ResourceHandler<sf::Texture, TileSets::ID> &tileSets, Console &console)
{
    textureNumber = TextureId::NPC;
    assignTexture(tileSets);
}

Npc::Npc(TextureId textureNumber, ResourceHandler<sf::Texture, TileSets::ID> &tileSets, Console &console)
{
    this->textureNumber = textureNumber;
    assignTexture(tileSets);
    console.log("made an npc!", sf::Color::Red);
}

void Npc::addAction(Action action)
{
    action.duration = this->stats.movementSpeed;
    actionQueue.push(action);
}


void Npc::followActor(Actor actor)
{
    if (actionQueue.empty())
    {
        Action action;
        action.type = ACTION_TYPE::MOVE;
        if (sprite.getPosition().x < actor.sprite.getPosition().x)
        {
            action.dir = DIRECTION::RIGHT;
        }
        else if (sprite.getPosition().x > actor.sprite.getPosition().x)
        {
            action.dir = DIRECTION::LEFT;
        }
        else if (sprite.getPosition().y < actor.sprite.getPosition().y)
        {
            action.dir = DIRECTION::DOWN;
        }
        else if (sprite.getPosition().y > actor.sprite.getPosition().y)
        {
            action.dir = DIRECTION::UP;
        }
        addAction(action);

    }
}
