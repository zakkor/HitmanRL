#include "Names.hpp"


using std::cout;

Names::Names()
{
    loadAllNames();
}

void Names::loadFromFile(std::string file, std::string type)
{
    std::ifstream fileStream(file.c_str());

    std::string auxStr;

    while (std::getline(fileStream, auxStr))
    {
        if (type == "male name")
        {
            maleFirstNameStorage.push_back(auxStr);
        }
        else if (type == "female name")
        {
            femaleFirstNameStorage.push_back(auxStr);
        }
        else if (type == "last name")
        {
            lastNameStorage.push_back(auxStr);
        }
        else if (type == "male freq")
        {
            maleFirstNameFreqStorage.push_back(atoi(auxStr.c_str()));
        }
        else if (type == "female freq")
        {
            femaleFirstNameFreqStorage.push_back(atoi(auxStr.c_str()));
        }
        else if (type == "last freq")
        {
            lastNameFreqStorage.push_back(atoi(auxStr.c_str()));
        }
    }
}

void Names::loadAllNames()
{
    std::cout << "Started loading names...";
    loadFromFile("res/names/FEMALE FIRST.name", "female name");
    loadFromFile("res/names/MALE FIRST.name", "male name");
    loadFromFile("res/names/LAST NAME.name", "last name");
    loadFromFile("res/names/FEMALE FIRST.freq", "female freq");
    loadFromFile("res/names/MALE FIRST.freq", "male freq");
    loadFromFile("res/names/LAST NAME.freq", "last freq");
    std::cout << "done.\n";
}

