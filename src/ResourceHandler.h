//
// Created by Edward on 15-Jul-15.
//

#ifndef HITMANRL_RESOURCEHANDLER_H
#define HITMANRL_RESOURCEHANDLER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>



template <typename Resource, typename Identifier>
class ResourceHandler
{
public:
    ResourceHandler();
    ResourceHandler(Identifier id, const std::string& filename);

    void load(Identifier id, const std::string& filename);

    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondParam);

    Resource& get(Identifier id);
    const Resource&	get(Identifier id) const;

private:
    void insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
    std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;
};

#include "ResourceHandler.inl"

#endif //HITMANRL_RESOURCEHANDLER_H
