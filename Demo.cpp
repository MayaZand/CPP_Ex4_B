/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

   cout << "hello1" << endl;

    sushi->move(tom);
   
   //cout << "hello2" << endl;
    sushi->slash(tom);
   //cout << "hello3" << endl;

    Team team_A(tom); 
   //cout << "hello4" << endl;
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

   //cout << "hello5" << endl;

    // Team b(tom); should throw tom is already in team a

    // cout<< sushi->print() << endl;
     Team team_B(sushi);

     cout << "hello6" << endl;
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));

     //cout << "hello7" << endl;

    //  cout<< "team_B: " << endl;
    //  team_B.print();
    // cout<< "team_A: " << endl;
    //  team_A.print();
   //Character* victim = team_A.chooseVictim(&team_B);
    //cout << victim->print() << endl;



     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
     {
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }
   //   cout << "hello8" << endl;

   //   if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
   //   else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
