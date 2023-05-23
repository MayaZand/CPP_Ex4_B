#pragma once
#include "Ninja.hpp"

using namespace std;

namespace ariel
{

    class OldNinja : public Ninja
    {

    public:
        /* constructor: */

        OldNinja(string name, const Point& location);
    };
}