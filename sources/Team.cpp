#include "Team.hpp"

using namespace ariel;

int Team::getTeamSize()
{
    return warriors.size();
}

void Team::add(Character* newCharacter)
{
    warriors.push_back(newCharacter);
}

void Team::attack(Team* enemys)
{
    if (enemys->leader->isAlive() == false)
    {
        return;
    }
}

int Team::stillAlive()
{
    int counter = 0;
    
    for (int i=0; i<(this->getTeamSize()); i++)
    {
        if (this->warriors[i]->isAlive() == true)
        {
            counter++;
        }
    }

    return counter;
}

void Team::print()
{
    //TODO
}