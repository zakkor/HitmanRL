#ifndef STATS_H
#define STATS_H

#include <string>
#include "Names.hpp"

using std::string;
using std::cout;

class Stats
{

public:
    static Names names;

    Stats();
    string gender;
    unsigned int age;
    unsigned int height;
    string firstName, lastName, middleName;
    unsigned int weight;
    string race;
    unsigned int movementSpeed;
    unsigned short intellect;
    string eyeColour;
    string skinColour;
    string hairColour;

    string socialStatus;

///rand functions
public:
    void generateGender();
    void generateAge();
    void generateHeight();
    void generateName();
    void generateWeight();
    void generateRace();
    void generateMovementSpeed(); // seconds it takes to move to the next tile (let's say 1 meter)
    void generateIntellect();
    void generateEyeColour();
    void generateSkinColour();
    void generateHairColour();
    void generateSocialStatus();

//getter functions
    void getHumanStats();
    string getFullName();
//    void getGlobalStats(vector<Stats> &population);

};

#endif // STATS_H
