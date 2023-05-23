#pragma once
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel
{
    class Point
    {
    
    private:

        double x_coordinate;
        double y_coordinate;

    public:
        /* constructor: */
        Point(double x_coordinate, double y_coordinate) : x_coordinate(x_coordinate), y_coordinate(y_coordinate) {}

        /* METHODS: */

        /* getters: */

        /*
        @return the x coordinate of the point
        */
        double getX() const;

        /*
        @return the y coordinate of the point
        */
        double getY() const;

        /*
        @return the distance between this point and other point.
        @param other is the other point.
        */
        double distance(const Point& other) const;

        /*
        this method prints the X ant Y coordinate of the point in this formate: (x,y)
        */
        string print() const;

        /*
        this method accepts source point, destination point and a distance.
        @return the closest point to the destination point, which is at most the given distance from the source point.
        @param srcPoint is the source point
        @param destPoint is the destination point
        @param distance is the max distance that can be moved from the source point to the destination point.
        */
        static Point moveTowards(const Point& srcPoint, const Point& destPoint, double distance);
    };
}