#include "Team2.hpp"

using namespace ariel;

void Team2::attack(Team* enemies)
{
    if (enemies == nullptr) 
    {
        throw invalid_argument("enemies is a NULL pointer");
    }
    
    if (this->stillAlive() == 0) 
    {
        throw runtime_error("all team members are dead");
    }

    if (enemies->stillAlive() == 0) 
    {
        throw runtime_error("all of the enemies team members are dead");
    }

    if (this->getLeader()->isAlive() == false)
    {
        this->chooseNewLeader();
    }

    // choose victim from the enemies team
    Character* theVictim = chooseVictim(enemies);

    for (Character* warrior: this->getWarriorsTeam())
    {
        if (!theVictim->isAlive())
        {
            if (enemies->stillAlive() == 0)
            {
                return;
            }

            theVictim = chooseVictim(enemies);
        }

        Cowboy* cowboy = dynamic_cast<Cowboy*>(warrior);
        Ninja* ninja = dynamic_cast<Ninja*>(warrior);

        if (cowboy != nullptr && cowboy->isAlive())
        {
            if (cowboy->hasboolets())
            {
                cowboy->shoot(theVictim);
            }

            else
            {
                cowboy->reload();
            }
        }

        else if (ninja != nullptr && ninja->isAlive())
        {
            if (ninja->distance(theVictim) <= 1)
            {
                ninja->slash(theVictim);
            }

            else
            {
                ninja->move(theVictim);
            }
        }
    }
}

void Team2::print() const
{
    for (Character* warrior : this->getWarriorsTeam())
    {
        cout << warrior->print() << endl;
    }
}