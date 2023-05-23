#pragma once
#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {

    private:
        string characterName;
        Point location;
        int hitPoint;
        bool inTeam = false;

    public:
        /* counstructor & destructor: */

        Character(string characterName, const Point &location, int hitPoint);
        virtual ~Character() = default;

        Character(Character &&other) noexcept = default;
        Character(const Character &other) = default;

        Character &operator=(const Character &other) = default;
        Character &operator=(Character &&other) noexcept = default;


        /* METHODS: */

        /* getters & setters: */
        
        /*
        @return the character's name.
        */
        string getName() const;
        
        /*
        @return the character's location
        */
        const Point& getLocation() const;
        
        /*
        @return the number of the character's hitpoints
        */
        int getHitPoints() const;

        /*
        this method updates the status of the character - if it is already in the team or not.
        */
        void setStatus(bool status);

        /*
        this method updates the character's location.
        */
        void setLocation(const Point &location);

        /*
        @return true if the character is already in the team
        */
        bool isInTeam() const;

        /*
        @return true if the character is alive, and false otherwise.
        */
        bool isAlive() const;

        /*
        @return the distance between the two characters.
        @param other is the other character.
        */
        double distance(Character *other) const;

        /*
        this method subtracts the amount of hit points from the character.
        @param num is the number of points to substract.
        */
        void hit(int num);

        /*
        this method prints the name of the character, the number of its hit points, and the point where the character is.
        if the character is dead, the number of hit points will not be printed, and the character's name will appear in parentheses.
        Before the name will appear a letter indicating the type of character: N for ninja and C for cowboy.
        */
        virtual string print() const;
    };
}