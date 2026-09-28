#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include <cmath>
#include <vector>
#include "globals.hpp"
#include "circle.hpp"

int main()
{
    float massInput, radiusInput;
    printf("Enter mass and radius (e.g., 5.0 25.0): ");
    scanf("%f %f", &massInput, &radiusInput);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Gravity-Simulator");
    SetTargetFPS(60);

    std::vector<Circle> objects;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            int xCoord = GetMouseX();
            int yCoord = GetMouseY();

            Circle newObject(xCoord, yCoord, massInput, radiusInput);

            newObject.centerPosition.x = xCoord;
            newObject.centerPosition.y = yCoord;

            newObject.velocity.x = 0;
            newObject.velocity.y = newObject.mass * gravitationalAttraction;

            objects.push_back(newObject);
        }
        for(int i = 0; i < objects.size(); ++i)
        {
            objects[i].moveCircle();
            
            Collisions typeOfCollision = objects[i].detectCollision();
            if(typeOfCollision != NO_COLLISION)
                objects[i].resolveCollision(typeOfCollision);
            
            DrawCircle(objects[i].centerPosition.x, objects[i].centerPosition.y, objects[i].radius, RED);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
