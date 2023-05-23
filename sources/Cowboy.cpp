#include "Cowboy.hpp"

using namespace ariel;

Cowboy::Cowboy(string name, const Point &point) : Character(name, point, 110), numOfBullets(6) {}

int Cowboy::getNumOfBullets()
{
    return this->numOfBullets;
}

string Cowboy::print() const
{
    string cowboyOutput = "Character Type: C";
    cowboyOutput += Character::print();
    
    return cowboyOutput;
}

bool Cowboy::hasboolets() const
{
    if (this->numOfBullets == 0)
    {
        return false;
    }
    
    return true;
}

void Cowboy::shoot(Character* other)
{
    if (other == nullptr)
    {
        throw invalid_argument("other is a NULL pointer");
    }

    if (other->isAlive() == false)
    {
        throw runtime_error("Cowboy can't shoot a dead character");
    }

    if (this->isAlive() == false)
    {
        throw runtime_error("Cowboy is dead");
    }

    if (this == other)
    {
        throw runtime_error("this and other are the same");
    }

    if (this->numOfBullets == 0)
    {
        return;
    }

    other->hit(10);
    this->numOfBullets--;
}

void Cowboy::reload()
{
    if (this->isAlive() == false)
    {
        throw runtime_error("Cowboy is dead and can't reload");
    }

    this->numOfBullets = 6;
}