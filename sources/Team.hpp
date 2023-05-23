#pragma once
#include <iostream>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "vector"
#include <cfloat>

using namespace std;

namespace ariel
{

    class Team
    {

    protected:
        Character* leader;
        vector<Character*> warriors;
    
    /* protected methods: */
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


    /*
    this method performs an attack using group members who are cowboys.
    @param enemies is the pointer to the enemies team.
    @param victim is the pointer to the chosen victim from the enemies team.
    */
    void cowboyAttack(Team* enemies, Character* victim);
    
    /*
    this method performs an attack using group members who are ninjas.
    @param enemies is the pointer to the enemies team.
    @param victim is the pointer to the chosen victim from the enemies team.
    */
    void ninjaAttack(Team* enemies, Character* victim);

    public:
        Character* chooseVictim(Team* enemyTeam); //+++++++++++++++++++++++++++++++++++++++++++++++++++++++
        /* constructor & destructor: */
        Team(Character* leader);
        ~Team() = default;

        /* METHODS: */

        /* getters: */

        /*
        @return the size of the team (vector)
        */
        int getTeamSize();

        /*
        @return the pointer to the warriors team
        */
        vector<Character*>& getWarriorsTeam();

        /*
        This method adds a cowboy or ninja to the group.
        @param newCharacter is the pointer to the character that is added to the group.
        */
        void add(Character* newCharacter);

        /*
        this method performs the attack between 2 groups.
        @param enemys is the pointer to the enemys Team.
        */
        virtual void attack(Team* enemys);

        /*
        @return the number of warriors in the group that are still alive.
        */
        int stillAlive();

        /*
        this method prints all details of the group members.
        */
        virtual void print();
    };

}