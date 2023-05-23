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
        Character *chooseVictim(Team *enemyTeam); 
        /* constructor & destructor: */
        Team(Character *leader);
        virtual ~Team();

        Team(const Team &other);
        Team &operator=(const Team &other);

        Team(Team &&other) noexcept;
        Team &operator=(Team &&other) noexcept;

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

        /* METHODS: */

        /* getters: */

        /*
        @return the size of the team (vector)
        */
        int getTeamSize() const
        {
            return (int)warriors.size();
        }

        /*
        @return the pointer to the warriors team
        */
        const vector<Character *> &getWarriorsTeam() const
        {
            return warriors;
        }

        const Character *getLeader() const
        {
            return leader;
        }

        void setLeader(Character *leader)
        {
            this->leader = leader;
        }

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