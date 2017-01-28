#include "Names.hpp"


using std::cout;

Names::Names()
{
    loadAllNames();
}

void Names::loadFromFile(std::string file, std::string type)
{
    std::ifstream fileStream(file.c_str());
    if (!fileStream.is_open()) {
            std::cout<<"error loading names!!!\n";
    }

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
    loadFromFile("res/names/fem_f_n", "female name");
    loadFromFile("res/names/male_f_n", "male name");
    loadFromFile("res/names/last_n", "last name");
    loadFromFile("res/names/fem_f_f", "female freq");
    loadFromFile("res/names/male_f_f", "male freq");
    loadFromFile("res/names/last_f", "last freq");
    std::cout << "done.\n";
}

