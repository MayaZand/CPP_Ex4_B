#pragma once
#include "Ninja.hpp"

using namespace std;

namespace ariel
{

    class TrainedNinja : public Ninja
    {
    
    public:
        /* constructor: */

        TrainedNinja(string name, const Point& location);
    };
}