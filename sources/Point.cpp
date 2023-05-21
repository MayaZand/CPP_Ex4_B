#include "Point.hpp"

using namespace ariel;

double Point::distance (Point other)
{

    double distance_x = this->x_coordinate - other.getX();
    double distance_y = this->y_coordinate - other.getY();
        
    return std::sqrt(distance_x * distance_x + distance_y * distance_y);
}

double Point::getX()
{
    return this->x_coordinate;
}

double Point::getY()
{
    return this->y_coordinate;
}

void Point::print()
{
    cout << '(' << this->getX() << ',' << this->getY() << ')' << endl;
}

Point Point:: moveTowards (Point& srcPoint, Point& destPoint, double distance)
{
    // calculate the distance between the two points
    double distanceBetween = srcPoint.distance(destPoint);

    // find the closest Point to srcPoint
    if (distanceBetween <= distance)
    {
        return destPoint;
    }
    else
    {
        double ratio = distance / distanceBetween;
        double newX = srcPoint.getX() + (destPoint.getX() - srcPoint.getX())*ratio;
        double newY = srcPoint.getY() + (destPoint.getY() - srcPoint.getY())*ratio;

        Point closestPoint (newX, newY);
        return closestPoint;
    }
}
