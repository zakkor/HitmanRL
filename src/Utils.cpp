//
// Created by Edward on 20-May-15.
//

#include "Utils.h"

namespace Utils
{
    std::string intToString(int toConvert)
    {
        std::stringstream converter;
        converter << toConvert;
        return converter.str();
    }
}


