#include "Team.hpp"

using namespace ariel;

int Team::getTeamSize()
{
    return warriors.size();
}

vector<Character*>& Team::getWarriorsTeam()
{
    return this->warriors;
}

void Team::add(Character* newCharacter)
{
    warriors.push_back(newCharacter);
}

void Team::attack(Team* enemies)
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

    cowboyAttack(enemies, theVictim);
    ninjaAttack(enemies, theVictim);

}

void Team::chooseNewLeader()
{
    Character* newLeader = NULL;
    double minDistance = DBL_MAX;

    // go through all the members of the group to choose the closest one to be the leader
    for(unsigned int i = 0; i<this->warriors.size(); i++)
    {
        if (this->warriors[i]->isAlive())  // warrior must be alive to be the team's leader
        { 
            double distance = this->warriors[i]->getLocation().distance(this->leader->getLocation());
            
            if (distance < minDistance)
            {
                minDistance = distance;
                newLeader = warriors[i];
            }
        }
    }

    this->leader = newLeader;
}

Character* Team::chooseVictim(Team* enemyTeam)
{
    Character* enemyVictim = NULL;
    double minDistance = DBL_MAX;
    
    // go through all the members of the enemies group to choose the closest one to be the victim
    for(unsigned int i = 0; i<enemyTeam->getWarriorsTeam().size(); i++)
    {
        if (enemyTeam->warriors[i]->isAlive() == true) // the victim must be alive before the team attacks them
        {
            double distance = enemyTeam->warriors[i]->getLocation().distance(this->leader->getLocation());
        
            if (distance < minDistance)
            {
                minDistance = distance;
                enemyVictim = enemyTeam->warriors[i];
            }
        }
    }

    return enemyVictim;
}

void Team::cowboyAttack(Team* enemies, Character* victim)
{
    if (victim == NULL)
    {
        return;
    }
    
    // go through all the members of the attacking group and check if they are cowboys.
    for(unsigned int i=0; i<this->warriors.size(); i++)
    {
        if (enemies->warriors[i]->isAlive() == true)
        {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(enemies->getWarriorsTeam()[i]);

            if (cowboy != NULL) // Checking if the casting was successed
            {
                // checking that the cowboy has bullets
                if (cowboy->hasBullets() == true)
                {
                    cowboy->shoot(victim);
                    
                    // if the victim dies, a new victim is chosen
                    if (victim->isAlive() == false)
                    {
                        victim = chooseVictim(enemies); 
                    }
                }
                
                // if the cowboy is out of bullets, reload his gun
                else
                {
                    cowboy->reload();
                }
            }
        }
    }
}
        
void Team::ninjaAttack(Team* enemies, Character* victim)
{
    if (victim == NULL)
    {
        return;
    }

    // go through all the members of the attacking group and check if they are ninjas.
    for(unsigned int i=0; i<this->warriors.size(); i++)
    {
        if (enemies->warriors[i]->isAlive() == true)
        {
            Ninja* ninja = dynamic_cast<Ninja*>(enemies->getWarriorsTeam()[i]);

            if (ninja != NULL) // Checking if the casting was successed
            {
                // checking if the ninja is close enough to the enemy (less than 1 meter)
                if (enemies->warriors[i]->distance(ninja) < 1)
                {
                    ninja->slash(victim);
                    
                    // if the victim dies, a new victim is chosen
                    if (victim->isAlive() == false)
                    {
                        victim = chooseVictim(enemies); 
                    }
                }
                
                // if the ninja is too far to attack the victim (more than 1 meter)
                else
                {
                    ninja->move(victim);
                }
            }
        }
    }
}        

int Team::stillAlive()
{
    int counter = 0;
    
    for (unsigned int i=0; i<(this->getTeamSize()); i++)
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