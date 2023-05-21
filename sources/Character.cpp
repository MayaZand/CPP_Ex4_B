#include "Character.hpp"

using namespace ariel;

bool Character::isAlive()
{
    if (this->hitPoint <= 0)
    {
        return false;
    }
    
    return true;
}

double Character::distance(Character* other)
{
    double distanceBetween = this->getLocation().distance(other->getLocation());
    
    return distanceBetween;
}

void Character::hit(int num)
{
    this->hitPoint = this->hitPoint - num;
}

string Character::getName()
{
    return this->characterName;
}

Point& Character::getLocation()
{
    return this->location;
}

int Character::getHitPoints()
{
    return this->hitPoint;
}
