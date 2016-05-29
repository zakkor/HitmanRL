#include "Body.hpp"

Body::Body()
{
}

void Body::initializeBody(int hp)
{
    head.maxHp = hp;
    leftArm.maxHp = hp;
    rightArm.maxHp = hp;
    torso.maxHp = hp;
    leftLeg.maxHp = hp;
    rightLeg.maxHp = hp;

    totalHealth.maxHp =     head.maxHp +
                            leftArm.maxHp + rightArm.maxHp +
                            torso.maxHp +
                            leftLeg.maxHp + rightLeg.maxHp;
    head.Hp = hp;
    leftArm.Hp = hp;
    rightArm.Hp = hp;
    torso.Hp = hp;
    leftLeg.Hp = hp;
    rightLeg.Hp = hp;

    updateTotalHealth();

    head.Percentage = head.Hp * 100 / head.maxHp;
    leftArm.Percentage = leftArm.Hp * 100 / leftArm.maxHp;
    rightArm.Percentage = rightArm.Hp * 100 / rightArm.maxHp;
    torso.Percentage = torso.Hp * 100 / torso.maxHp;
    leftLeg.Percentage = leftLeg.Hp * 100 / leftLeg.maxHp;
    rightLeg.Percentage = rightLeg.Hp * 100 / rightLeg.maxHp;
}

bool Body::damagePart(Part &partToDamage)
{
    if (partToDamage.Hp > 0)
    {
        partToDamage.Hp -= 1;
        partToDamage.Percentage = partToDamage.Hp * 100 / partToDamage.maxHp;
        updateTotalHealth();
        return true;
    }
    return false;
//    std::cout << "Hp: "<< partToDamage.Hp << "\nPercentage: " << partToDamage.Percentage << "\n";
}

void Body::updateTotalHealth()
{
    totalHealth.Hp =    head.Hp +
                        leftArm.Hp + rightArm.Hp +
                        torso.Hp +
                        leftLeg.Hp + rightLeg.Hp;

    totalHealth.Percentage = totalHealth.Hp * 100 / totalHealth.maxHp;

}
