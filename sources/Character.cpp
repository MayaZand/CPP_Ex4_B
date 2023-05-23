/* during the preperations of this task i used chat GPT and got help from roy simanovich! */
#include "Character.hpp"

using namespace ariel;

Character::Character(string characterName, const Point &location, int hitPoint) : characterName(characterName), location(location), hitPoint(hitPoint) {}

string Character::getName() const 
{
    return characterName;
}

const Point& Character::getLocation() const 
{
    return location;
}

int Character::getHitPoints() const 
{
    return hitPoint;
}

void Character::setStatus(bool status) 
{
    inTeam = status;
}

void Character::setLocation(const Point &location) 
{
    this->location = location;
}

bool Character::isInTeam() const 
{
    return inTeam;
}

bool Character::isAlive() const 
{
    return hitPoint > 0;
}

double Character::distance(Character* other) const
{
    double distanceBetween = this->getLocation().distance(other->getLocation());
    
    return distanceBetween;
}

void Character::hit(int num)
{
    if (num < 0)
    {
        throw invalid_argument("num is negative");
    }
    
    this->hitPoint = this->hitPoint - num;
}

string Character::print() const
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

    output += "Location: " + this->location.print() + "\n";

    return output;
}