//
// Created by Edward on 02-Apr-15.
//

#ifndef _HITMANRL_LIGHTMAP_H_
#define _HITMANRL_LIGHTMAP_H_




#include "VertexMap.hpp"


namespace LightStatus
{
    enum LIGHTSTATUS : unsigned char
    {
        DARK = 0,
        LITTLE,
        WELL,
        LIGHTSTATUS_ENUM_SIZE
    };
}
class LightMap : public VertexMap
{
public:
    LightMap(ResourceHandler<sf::Texture, TileSets::ID> &tileSets);
    bool reload();
    void updateIntensity();
    bool intensityGrowing;

    void addLight(int x, int y);

    short atmosphericIntensity; // ! 0-255 !
    std::vector< std::vector<LightStatus::LIGHTSTATUS> > lights;


};


#endif //_HITMANRL_LIGHTMAP_H_
