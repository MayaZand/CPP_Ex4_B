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
   if (enemy == this)
   {
        throw invalid_argument ("the enemy cant be itself!");
   }

   this->location = Point::moveTowards(this->location, enemy->getLocation(), this->speed);
}

void Ninja::slash(Character* enemy)
{
    if (enemy == this)
    {
        throw runtime_error ("the enemy cant be itself!");
    }

    if (enemy->isAlive() == false)
    {
        throw runtime_error("cant attack dead character");
    }

    if (this->isAlive() == false)
    {
        throw runtime_error("cant attack dead character");
    }
    
    double distance = this->getLocation().distance(enemy->getLocation());
    
    if (distance < 1 && this->isAlive() == true)
    {
        enemy->hit(40);
    }
    
}


