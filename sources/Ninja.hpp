#pragma once
#include "Character.hpp"

using namespace std;

namespace ariel
{

    class Ninja : public Character
    {

    protected:
        int speed;
    
    public:
        /* constructor: */

        Ninja(string name, Point& location, int hitPoints, int speed) : Character(name, location, hitPoints), speed(speed) {}

        /* METHODS: */

        /* override methods: */

        /*
        this method prints the name of the character, the number of its hit points, and the point where the character is.
        if the character is dead, the number of hit points will not be printed, and the character's name will appear in parentheses.
        Before the name will appear a letter indicating the type of character: N for ninja and C for cowboy.
        */
        string print() override;

        /* getters: */

        /*
        @return the Ninja's speed.
        */
        int getSpeed();

        /*
        this method gets a pointer to the enemy and moves towards the enemy. The ninja advances a distance equal to its speed.
        */
        void move(Character *enemy);

        /*
        this method gets a pointer to the enemy.
        if the ninja is alive and the enemy is less than 1 meter away, the ninja will cause 40 hit points damage to the enemy.
        otherwise, no damage will be done to the enemy.
        */
        void slash(Character *enemy);
    };
}