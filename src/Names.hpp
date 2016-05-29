#ifndef NAMES_H
#define NAMES_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

/**
* Segfaults if it can't load names from file.
**/

class Names
{
    public:
        Names();

        std::vector<std::string> maleFirstNameStorage,
                       femaleFirstNameStorage,
                       lastNameStorage;

        std::vector<float> maleFirstNameFreqStorage,
                      femaleFirstNameFreqStorage,
                      lastNameFreqStorage;

        void loadFromFile(std::string file, std::string type);

        void loadAllNames();

};

#endif // NAMES_H
