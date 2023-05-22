#include "Cowboy.hpp"

using namespace ariel;

int Cowboy::getNumOfBullets()
{
    return this->numOfBullets;
}

string Cowboy::print() 
{
    string cowboyOutput = "Character Type: C";
    cowboyOutput += Character::print();
    
    return cowboyOutput;
}

bool Cowboy::hasBullets() const
{
    if (this->numOfBullets <=0)
    {
        return false;
    }
    
    return true;
}

void Cowboy::shoot(Character* other)
{
    if (this->numOfBullets <= 0 || this->isAlive() == false)
    {
        return;
    }

    other->hit(10);
    this->numOfBullets = this->numOfBullets - 1;
}

void Cowboy::reload()
{
    this->numOfBullets = this->numOfBullets + 6;
}