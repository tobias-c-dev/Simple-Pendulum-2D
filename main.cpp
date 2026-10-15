#include <raylib.h>
#include <raymath.h>
#include "Constants.hpp"
#include "Components.hpp"


int main() {

    // Initialisation
    InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "Game Window");
    InitAudioDevice();
    SetTargetFPS(60);


    // Create Objects
    Rod rod;
        rod.length = Constants::ROD_LENGTH;
        rod.radius = Constants::ROD_RADIUS;
        rod.mass = Constants::ROD_MASS;
        rod.colour = RAYWHITE;
    
    Bob bob;
        bob.radius = Constants::BOB_RADIUS;
        bob.mass = Constants::BOB_MASS;
        bob.colour = BLUE;

    Pendulum pen;
        pen.rod = rod;
        pen.bob = bob;
        pen.angle = Constants::INITAL_ANGLE;
        pen.angular_velocity = Constants::INITAL_ANGULAR_VELOCITY;


    
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        pen.update(dt);

        BeginDrawing();
            ClearBackground(BLACK);
            pen.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}


