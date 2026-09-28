#ifndef GLOBALS_HPP
#define GLOBALS_HPP

typedef struct 
{
    float x;
    float y;
}Coordinates;

enum Collisions
{
    LEFT_WALL,
    RIGHT_WALL,
    FLOOR,
    OBJECT,
    NO_COLLISION
};

inline const int SCREEN_WIDTH = 800;
inline const int SCREEN_HEIGHT = 600;

inline const float gravitationalAttraction = 0.2f;

#endif
