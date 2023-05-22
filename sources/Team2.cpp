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

    if (this->leader->isAlive() == false)
    {
        this->chooseNewLeader();
    }

    // choose victim from the enemies team
    Character* theVictim = chooseVictim(enemies);

    for(unsigned int i=0; i<this->warriors.size(); i++) 
    {
        
        
        if (Ninja* ninja = dynamic_cast<Ninja*>(enemies->getWarriorsTeam()[i]))
        {
            ninjaAttack(enemies, theVictim);
        }
        
        
        
        else if (Cowboy* cowboy = dynamic_cast<Cowboy*>(enemies->getWarriorsTeam()[i]))
        {
            cowboyAttack(enemies, theVictim);
        }
        
        if (theVictim->isAlive() == false) 
        {
            if (enemies->stillAlive() == 0) // if the victim is dead and also all enemies team members are dead
            {
                return;
            } 
            
            else // if the victim is dead but there is at least one member of the enemies team still alive, a new victim is chosen
            {
                theVictim = chooseVictim(enemies);
            }
        }
    }
}

void Team2::print() 
{
    
}