#include "Ninja.hpp"

using namespace ariel;

Ninja::Ninja(string name, const Point &location, int hitPoints, int speed) : Character(name, location, hitPoints), speed(speed) {}

int Ninja::getSpeed()
{
    return this->speed;
}

string Ninja::print() const
{
    string ninjaOutput = "Character Type: N";
    ninjaOutput += Character::print();

    return ninjaOutput;
}
    
void Ninja::move(Character* enemy)
{
    if (enemy == this)
    {
        throw invalid_argument("the enemy cant be itself!");
    }

    Point enemyLocation = enemy->getLocation();
    Point newLocation = Point::moveTowards(getLocation(), enemyLocation, this->speed);

    setLocation(newLocation);
}

void Ninja::slash(Character *enemy)
{
    if (enemy == this)
    {
        throw runtime_error("the enemy cant be itself!");
    }

    if (enemy->isAlive() == false)
    {
        throw runtime_error("Ninja cant attack dead character");
    }

    if (this->isAlive() == false)
    {
        throw runtime_error("Ninja is dead");
    }

    double distance = this->getLocation().distance(enemy->getLocation());

    if (distance <= 1)
    {
        enemy->hit(40);
    }
}
