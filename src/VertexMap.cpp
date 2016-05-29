#include "VertexMap.hpp"

VertexMap::VertexMap(ResourceHandler<sf::Texture, TileSets::ID> &tileSets)
{
    tileSet_copy = tileSets.get(TileSets::DEFAULT);
    tiles.resize(100, std::vector<Textures::ID> (100, Textures::ID::GRASS));



//    for (int i = 64; i < 100 * 64; i+= 64)
//    {
//        for (int j = 64; j < 100 * 64; j += 64)
//        {
//            if (i / 64 % 16 == 0 && j / 64 % 16 == 0)
//            {
//                for (int c = j + 64 * 2; c < j + 64 * 2 + (2 * 64); c += 64)
//                {
//                    tiles[i + 64*4][c] = Textures::STONEFLOOR;
//                }
//                for (int c = j + 64 * 1; c < j + 64 * 1 + (2 * 64); c += 64)
//                {
//                    tiles[i + 64*4][c] = Textures::STONEFLOOR;
//                }
//            }
//        }
//    }
}

bool VertexMap::reload()
{
    sf::Vector2u tileSize(TILE_SIZE_X, TILE_SIZE_Y);

    vertexArray.setPrimitiveType(sf::Quads);
    vertexArray.resize(MAP_SIZE_X * MAP_SIZE_Y * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < MAP_SIZE_X; ++i)
        for (unsigned int j = 0; j < MAP_SIZE_Y; ++j)
        {
            // get the current tile number
            int tileNumber = tiles.at(i).at(j);

            if (tiles.at(i).at(j) == Textures::ID::EMPTY)
                continue;

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
        }

    return true;

}

void VertexMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileSet_copy;

    // draw the vertex array
    target.draw(vertexArray, states);

}
