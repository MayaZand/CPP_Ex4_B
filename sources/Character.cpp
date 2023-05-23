#include "Character.hpp"

using namespace ariel;

bool Character::isInTeam()
{
    return this->inTeam;
}

void Character::setStatus(bool status)
{
    this->inTeam = status;
}


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

string Character::print()
{
    string output;

    output += "\nName: ";
    if (this->getHitPoints() <= 0) // if the character is dead
    {
        output += "(" + this->getName() + ")";
    } 
    else 
    {
        output += this->getName();
    }
    
    output += "\n";
    if (this->getHitPoints() > 0) {
        output += "Hit Points: " + to_string(this->getHitPoints()) + "\n";
    }

    output += "Location: (" + to_string(this->location.getX()) + "," + to_string(this->location.getY()) + ")";
    //output += "Location: " + this->location.print() + "\n";

    return output;
}