#include <stdlib.h>
#include "Stats.hpp"

Names Stats::names;

Stats::Stats()
{
    generateGender();
    generateName();
    generateMovementSpeed();
}

void Stats::generateGender()
{
    int genderProbability = rand() % 2;
    switch (genderProbability)
    {
        case 0:
            gender = "male";
            break;
        case 1:
            gender = "female";
            break;
    }
}

void Stats::generateAge()
{
    // 2/3 chance to generate human up to 70 years old and 1/3 70 to 95
    int probability = rand() % 3;
    if (probability == 0 || probability == 1)
    {
        age = rand() % 70;
    }
    else
    {
        age = rand() % 95;
    }

}

void Stats::generateHeight()
{
    if (age < 10)
    {
        height = rand() % 20 + 110;
    }
    else
        height = rand() % 60 + 150;
}

void Stats::generateName()
{
    unsigned int getsMiddleName = rand() % 10;
    //First name
    if (gender == "female")
    {
        firstName = Stats::names.femaleFirstNameStorage[rand() % Stats::names.femaleFirstNameStorage.size()];
        if (getsMiddleName == 5)
            middleName = Stats::names.femaleFirstNameStorage[rand() % Stats::names.femaleFirstNameStorage.size()];
    }
    else
    {
        firstName = Stats::names.maleFirstNameStorage[rand() % Stats::names.maleFirstNameStorage.size()];
        if (getsMiddleName == 5)
            middleName = Stats::names.maleFirstNameStorage[rand() % Stats::names.maleFirstNameStorage.size()];
    }
    lastName = Stats::names.lastNameStorage[rand() % Stats::names.lastNameStorage.size()];

}

void Stats::generateWeight()
{
    if (age < 10)
    {
        weight = rand() % 10 + 20;
    }
    else
        weight = rand() % 30 + 50;

}

void Stats::generateRace()
{
    int raceProbability = rand() % 3;
    switch (raceProbability)
    {
        case 0:
            race = "Caucasian";
            break;
        case 1:
            race = "Asian";
            break;
        case 2:
            race = "Negroid";
            break;
        default:
            race = "INVALID!!!";
            break;
    }

}

void Stats::generateMovementSpeed()
{
    movementSpeed = 3;
}

void Stats::generateIntellect()
{

}

void Stats::generateEyeColour()
{
    int eyeColourProbability = rand() % 9;
    switch (eyeColourProbability)
    {
        case 0:
            eyeColour = "Amber";
            break;
        case 1:
            eyeColour = "Blue";
            break;
        case 2:
            eyeColour = "Brown";
            break;
        case 3:
            eyeColour = "Gray";
            break;
        case 4:
            eyeColour = "Green";
            break;
        case 5:
            eyeColour = "Hazel";
            break;
        case 6:
            eyeColour = "Hazel";
            break;
        case 7:
            eyeColour = "Red";
            break;
        case 8:
            eyeColour = "Violet";
            break;
    }
}

void Stats::generateSkinColour()
{
    if (race == "Caucasian")
    {
        skinColour = "White";
    }
    else if (race == "Asian")
    {
        skinColour = "Yellow";
    }
    else if (race == "Negroid")
    {
        skinColour = "Black";
    }
}

void Stats::generateHairColour()
{

}

void Stats::generateSocialStatus()
{
    if (age <= 18)
        socialStatus = "Child";
    else if (age >= 18 && age <= 65)
        socialStatus = "Adult";
    else if (age >= 65)
        socialStatus = "Elder";
}

string Stats::getFullName()
{
    string fullName = "";
    fullName += firstName;
    if(!middleName.empty())
    {
        fullName = fullName + " " + middleName[0];
    }
    fullName = fullName + " " + lastName;
    return fullName;
}

void Stats::getHumanStats()
{
    cout << age << " year old " << race << " " << gender << " named "; getFullName();
    cout << " weighing in at " << weight << "kgs, and " << height << " cm tall." << " Eye colour is " << eyeColour;
    cout << ", skin colour is " << skinColour << " and social status is " << socialStatus << "\n";
}

