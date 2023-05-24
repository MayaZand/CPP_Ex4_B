#include "Team.hpp"

using namespace ariel;

Team::Team(Character *leader) : leader(leader), warriors()
{
    if (leader->isInTeam() == true)
    {
        throw runtime_error("leader is already in team");
    }

    this->warriors.push_back(leader);
    leader->setStatus(true);
}

Team::~Team()
{
    for (Character *warrior : this->warriors)
    {
        delete warrior;
    }

    this->warriors.clear();
}

Team::Team(const Team &other)
{
    for (Character *warrior : other.warriors)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(warrior);
        Ninja *ninja = dynamic_cast<Ninja *>(warrior);

        if (cowboy != nullptr)
        {
            this->warriors.push_back(new Cowboy(*cowboy));
        }

        else if (ninja != nullptr)
        {
            this->warriors.push_back(new Ninja(*ninja));
        }
    }

    this->leader = this->warriors.front();
}

Team &Team::operator=(const Team &other)
{
    if (this == &other)
    {
        return *this;
    }

    for (Character *warrior : this->warriors)
    {
        delete warrior;
    }

    this->warriors.clear();

    for (Character *warrior : other.warriors)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(warrior);
        Ninja *ninja = dynamic_cast<Ninja *>(warrior);

        if (cowboy != nullptr)
        {
            this->warriors.push_back(new Cowboy(*cowboy));
        }

        else if (ninja != nullptr)
        {
            this->warriors.push_back(new Ninja(*ninja));
        }
    }

    this->leader = this->warriors.front();

    return *this;
}

Team::Team(Team &&other) noexcept
{
    for (Character *warrior : other.warriors)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(warrior);
        Ninja *ninja = dynamic_cast<Ninja *>(warrior);

        if (cowboy != nullptr)
        {
            this->warriors.push_back(cowboy);
        }

        else if (ninja != nullptr)
        {
            this->warriors.push_back(ninja);
        }
    }

    this->leader = this->warriors.front();
    
    other.warriors.clear();
    other.leader = nullptr;
}

Team &Team::operator=(Team &&other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    for (Character *warrior : this->warriors)
    {
        delete warrior;
    }

    this->warriors.clear();

    for (Character *warrior : other.warriors)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(warrior);
        Ninja *ninja = dynamic_cast<Ninja *>(warrior);

        if (cowboy != nullptr)
        {
            this->warriors.push_back(cowboy);
        }

        else if (ninja != nullptr)
        {
            this->warriors.push_back(ninja);
        }
    }

    this->leader = this->warriors.front();

    other.warriors.clear();
    other.leader = nullptr;

    return *this;
}

int Team::getTeamSize() const
{
    return (int)warriors.size();
}

const vector<Character *>& Team::getWarriorsTeam() const
{
    return warriors;
}

const Character* Team::getLeader() const
{
    return leader;
}

void Team::setLeader(Character *leader)
{
    this->leader = leader;
}

void Team::add(Character *newCharacter)
{
    if (newCharacter->isInTeam() == true)
    {
        throw runtime_error("newCharacter is already in team");
    }

    else if (getTeamSize() == 10)
        throw runtime_error("team is full");

    this->warriors.push_back(newCharacter);
    newCharacter->setStatus(true);
}

void Team::attack(Team *enemies)
{
    if (enemies == nullptr)
    {
        throw invalid_argument("enemies is a NULL pointer");
    }

    if (enemies == this)
    {
        throw runtime_error("enemies and this are the same");
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
    Character *theVictim = chooseVictim(enemies);

    for (Character *warrior : this->warriors)
    {
        if (!theVictim->isAlive())
        {
            if (enemies->stillAlive() == 0)
            {
                return;
            }

            theVictim = chooseVictim(enemies);
        }

        Cowboy *cowboy = dynamic_cast<Cowboy *>(warrior);

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
    }

    for (Character *warrior : this->warriors)
    {
        if (!theVictim->isAlive())
        {
            if (enemies->stillAlive() == 0)
            {
                return;
            }

            theVictim = chooseVictim(enemies);
        }

        Ninja *ninja = dynamic_cast<Ninja *>(warrior);

        if (ninja != nullptr && ninja->isAlive())
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

void Team::chooseNewLeader()
{
    Character *newLeader = nullptr;
    double minDistance = DBL_MAX;

    // go through all the members of the group to choose the closest one to be the leader

    for (Character *warrior : this->warriors)
    {
        if (warrior->isAlive() == false)
        {
            continue;
        }

        double distance = warrior->distance(this->leader);

        if (distance < minDistance)
        {
            minDistance = distance;
            newLeader = warrior;
        }
    }

    this->leader = newLeader;
}

Character *Team::chooseVictim(Team *enemyTeam)
{
    Character *enemyVictim = nullptr;
    double minDistance = DBL_MAX;

    for (Character *warrior : enemyTeam->warriors)
    {
        if (warrior->isAlive() == true) // the victim must be alive before the team attacks them
        {
            double distance = warrior->distance(this->leader);

            if (distance < minDistance)
            {
                minDistance = distance;
                enemyVictim = warrior;
            }
        }
    }

    return enemyVictim;
}

int Team::stillAlive() const
{
    int counter = 0;

    for (Character *warrior : this->warriors)
    {
        if (warrior->isAlive() == true)
        {
            counter++;
        }
    }

    return counter;
}

void Team::print() const
{
    for (Character *warrior : this->warriors)
    {
        Cowboy *cowboy = dynamic_cast<Cowboy *>(warrior);

        if (cowboy != nullptr)
        {
            cout << cowboy->print() << endl;
        }
    }

    for (Character *warrior : this->warriors)
    {
        Ninja *ninja = dynamic_cast<Ninja *>(warrior);

        if (ninja != nullptr)
        {
            cout << ninja->print() << endl;
        }
    }
}
