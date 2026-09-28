#include "circle.hpp"

Circle::Circle(int mouseX, int mouseY, float mass, float radius)
{
    this->centerPosition.x = mouseX;
    this->centerPosition.y = mouseY;

    this->mass = mass;
    this->radius = radius;

    this->velocity.x = 0;
    this->velocity.y = this->mass * gravitationalAttraction;
}

Collisions Circle::detectCollision()
{
    if(this->centerPosition.x - this->radius < 0)
        return LEFT_WALL;
    if(this->centerPosition.x + this->radius > SCREEN_WIDTH)
        return RIGHT_WALL;
    if(this->centerPosition.y + this->radius > SCREEN_HEIGHT)
        return FLOOR;
    
    return NO_COLLISION;
    
}

void Circle::moveCircle()
{
    this->velocity.y += (this->mass * gravitationalAttraction);

    this->centerPosition.x += this->velocity.x;
    this->centerPosition.y += this->velocity.y;
}

void Circle::resolveCollision(Collisions typeOfCollision)
{
    switch(typeOfCollision)
    {
        case LEFT_WALL:
            this->centerPosition.x += (this->radius - this->centerPosition.x);
            break;
        case RIGHT_WALL:
            this->centerPosition.x -= (this->radius + this->centerPosition.x - SCREEN_WIDTH);
            break;
        case FLOOR:
            this->velocity.y *= -0.5f;
            this->centerPosition.y -= (this->radius + this->centerPosition.y - SCREEN_HEIGHT);
            break; 
    }
}