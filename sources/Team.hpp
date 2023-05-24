#pragma once
#include <iostream>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>
#include <cfloat>

using namespace std;

namespace ariel
{

    class Team
    {

    private:
        Character *leader;
        vector<Character *> warriors;

    public:

        /* constructor & destructor: */
        Team(Character *leader);
        virtual ~Team();

        Team(const Team &other);
        Team &operator=(const Team &other);

        Team(Team &&other) noexcept;
        Team &operator=(Team &&other) noexcept;

        /* METHODS: */

        /* getters & setters: */

        /*
        @return the size of the team (vector)
        */
        int getTeamSize() const;

        /*
        @return the pointer to the warriors team
        */
        const vector<Character *>& getWarriorsTeam() const;
        
        /*
        @return the pointer to the team's leader.
        */
        const Character* getLeader() const;

        /*
        this method updates the team's leader.
        */
        void setLeader(Character *leader);

        /*
        this method will select a new leader from the team, if the existing leader dies.
        The new leader is the closest living character to the dead leader.
        */
        void chooseNewLeader();

        /*
        this method will select a victim from the team of enemies.
        The victim is a member of the enemy team which is alive and is the closest team member to the leader of the attacking team.
        @param enemyTeam is the pointer to the team of enemies.
        @return pointer to the victim.
        */
        Character* chooseVictim (Team *enemyTeam); 

        /*
        This method adds a cowboy or ninja to the group.
        @param newCharacter is the pointer to the character that is added to the group.
        */
        void add(Character *newCharacter);

        /*
        this method performs the attack between 2 groups.
        @param enemys is the pointer to the enemys Team.
        */
        virtual void attack(Team *enemys);

        /*
        @return the number of warriors in the group that are still alive.
        */
        int stillAlive() const;

        /*
        this method prints all details of the group members.
        */
        virtual void print() const;
    };

}



