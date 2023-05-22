#include "Ninja.hpp"

using namespace ariel;

int Ninja::getSpeed()
{
    return this->speed;
}

string Ninja::print()
{   
    string ninjaOutput = "Character Type: N";
    ninjaOutput += Character::print();
    
    return ninjaOutput;
}

void Ninja::move(Character* enemy)
{
   this->location = Point::moveTowards(this->location, enemy->getLocation(), this->speed);
}

void Ninja::slash(Character* enemy)
{
    double distance = this->getLocation().distance(enemy->getLocation());
    
    if (distance >= 1 || this->isAlive() == false)
    {
        return;
    }
    enemy->hit(40);
}


