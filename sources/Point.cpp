#include "Point.hpp"

using namespace ariel;

double Point::distance (const Point& other) const
{

    double distance_x = this->x_coordinate - other.getX();
    double distance_y = this->y_coordinate - other.getY();
        
    return std::sqrt(distance_x * distance_x + distance_y * distance_y);
}

double Point::getX() const
{
    return this->x_coordinate;
}

double Point::getY() const
{
    return this->y_coordinate;
}

string Point::print() const
{
    return "(" + to_string(this->getX()) + "," + to_string(this->getY()) + ")";
}

Point Point:: moveTowards (const Point& srcPoint, const Point& destPoint, double distance)
{
    if (distance < 0)
        throw invalid_argument("distance cannot be negative");
    
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
