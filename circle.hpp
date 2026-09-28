#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "globals.hpp"
#include <cmath>

class Circle
{
    public:
        float radius;
        float mass;
        Coordinates centerPosition;
        Coordinates velocity;

        Circle(int mouseX, int mouseY, float mass, float radius);
        Collisions detectCollision();
        void moveCircle();
        void resolveCollision(Collisions typeOfCollision);
};


#endif