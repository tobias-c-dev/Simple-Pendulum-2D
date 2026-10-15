#pragma once
#include <raylib.h>

struct Rod {
    
    Vector2 start;
    Vector2 end;
    float length;
    float radius;
    float mass;
    Color colour;

    Vector2 centreOfMass();
    float momentOfInertia();
    
    void draw();

};

struct Bob {

    Vector2 pos;
    float radius;
    float mass;
    Color colour;

    float momentOfInertia(float pivotDistance);

    void draw();

};

struct Pendulum {

    Rod rod;
    Bob bob;
    Vector2 anchor;
    float angle;
    float angular_velocity;
    float angular_acceleration;

    void update(float dt);
    
    void draw();

};