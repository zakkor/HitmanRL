#ifndef BODY_H
#define BODY_H

#include <string>
using std::string;

enum BodyParts {Head, Torso, LeftArm, RightArm, LeftLeg, RightLeg};

struct Part
{
    int maxHp, Hp, Percentage;
};

class Body
{
public:
    Body();
    /**TODO:
     *  Part.hpp:
    *      PartNames name;
    *
    *      add them all into a vector of parts
     */
    void initializeBody(int hp);
    bool damagePart(Part &partToDamage);
    void updateTotalHealth();

    unsigned short bodyPartNumber = 6;

    Part    totalHealth;

    Part         head,
            leftArm, rightArm,
                 torso,
            leftLeg, rightLeg;


private:
};
#endif // BODY_H
