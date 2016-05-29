//
// Created by Edward on 02-Apr-15.
//

#include "LightMap.h"

LightMap::LightMap(ResourceHandler<sf::Texture, TileSets::ID> &tileSets) : VertexMap(tileSets)
{
    lights.resize(100, std::vector<LightStatus::LIGHTSTATUS > (100));
    atmosphericIntensity = 255;
    intensityGrowing = true;
}

bool LightMap::reload()
{
    sf::Vector2u tileSize(TILE_SIZE_X, TILE_SIZE_Y);

    vertexArray.setPrimitiveType(sf::Quads);
    vertexArray.resize(MAP_SIZE_X * MAP_SIZE_Y * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < MAP_SIZE_X; ++i)
        for (unsigned int j = 0; j < MAP_SIZE_Y; ++j)
        {
            // tile number will be Textures::SHADOW
            int tileNumber = Textures::ID::SHADOW;

            // find its position in the tileset texture
            int tu = tileNumber % (tileSet_copy.getSize().x / tileSize.x);
            int tv = tileNumber / (tileSet_copy.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertexArray[(i + j * MAP_SIZE_X) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);


            switch (lights.at(i).at(j))
            {
                case LightStatus::DARK:
                    quad[0].color = sf::Color(0, 0, 0, atmosphericIntensity);
                    quad[1].color = sf::Color(0, 0, 0, atmosphericIntensity);
                    quad[2].color = sf::Color(0, 0, 0, atmosphericIntensity);
                    quad[3].color = sf::Color(0, 0, 0, atmosphericIntensity);
                    break;
                case LightStatus::LITTLE:
                    quad[0].color = sf::Color(0, 0, 0, atmosphericIntensity - atmosphericIntensity * 4/10);
                    quad[1].color = sf::Color(0, 0, 0, atmosphericIntensity - atmosphericIntensity * 4/10);
                    quad[2].color = sf::Color(0, 0, 0, atmosphericIntensity - atmosphericIntensity * 4/10);
                    quad[3].color = sf::Color(0, 0, 0, atmosphericIntensity - atmosphericIntensity * 4/10);
                    break;
                case LightStatus::WELL:
                    quad[0].color = sf::Color(0, 0, 0, atmosphericIntensity - atmosphericIntensity * 7/10);
                    quad[1].color = sf::Color(0, 0, 0, atmosphericIntensity - atmosphericIntensity * 7/10);
                    quad[2].color = sf::Color(0, 0, 0, atmosphericIntensity - atmosphericIntensity * 7/10);
                    quad[3].color = sf::Color(0, 0, 0, atmosphericIntensity - atmosphericIntensity * 7/10);
                    break;
                default:
                    break;
            }

        }

    return true;
}

void LightMap::addLight(int x, int y)
{
    lights.at(x).at(y) = LightStatus::WELL;
    lights.at(x+1).at(y) = LightStatus::WELL;
    lights.at(x-1).at(y) = LightStatus::WELL;
    lights.at(x).at(y+1) = LightStatus::WELL;
    lights.at(x).at(y-1) = LightStatus::WELL;
    lights.at(x-1).at(y-1) = LightStatus::LITTLE;
    lights.at(x+1).at(y-1) = LightStatus::LITTLE;
    lights.at(x-1).at(y+1) = LightStatus::LITTLE;
    lights.at(x+1).at(y+1) = LightStatus::LITTLE;
    lights.at(x).at(y-2) = LightStatus::LITTLE;
    lights.at(x).at(y+2) = LightStatus::LITTLE;
    lights.at(x-2).at(y) = LightStatus::LITTLE;
    lights.at(x+2).at(y) = LightStatus::LITTLE;

    reload();
}

void LightMap::updateIntensity()
{
    if (intensityGrowing)
    {
        atmosphericIntensity--;
        if (atmosphericIntensity == 0)
        {
            intensityGrowing = false;
        }
    }
    else
    {
        atmosphericIntensity++;
        if (atmosphericIntensity == 180)
        {
            intensityGrowing = true;
        }
    }
}
