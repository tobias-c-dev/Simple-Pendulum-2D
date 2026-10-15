#include "Components.hpp"
#include "Constants.hpp"
#include <raylib.h>
#include <cmath>

// Rod functions
Vector2 Rod::centreOfMass() {
    return {(start.x + end.x) / 2, (start.y + end.y) / 2};
}

float Rod::momentOfInertia() {
    float L = length / Constants::PPM;
    return (1.0f / 3.0f) * mass * L * L;
}

void Rod::draw() {
    DrawLineEx(start, end, radius * 2, colour);
}


// Bob functions
float Bob::momentOfInertia(float pivotDistance) {
    return mass * pivotDistance * pivotDistance;
}

void Bob::draw() {
    DrawCircleV(pos, radius, colour);
}


// Pendulum functions
void Pendulum::update(float dt) {
    float L = rod.length / Constants::PPM;
    float bob_distance = (rod.length + bob.radius) / Constants::PPM;
    float g = Constants::GRAVITY.y;

    float torque = -(rod.mass * g * (L / 2.0f) * sinf(angle))
                   -(bob.mass * g * bob_distance * sinf(angle));

    float damping_torque = -Constants::DAMPING_CONSTANT * angular_velocity;
    float total_torque = damping_torque + torque;

    float I_total = rod.momentOfInertia() + bob.momentOfInertia(L);
    
    angular_acceleration = total_torque / I_total ;
    angular_velocity += angular_acceleration * dt;
    angle += angular_velocity * dt;

    float effectiveLength = rod.length + bob.radius;
    bob.pos.x = Constants::ANCHOR.x + effectiveLength * sinf(angle);
    bob.pos.y = Constants::ANCHOR.y + effectiveLength * cosf(angle);
    rod.start = Constants::ANCHOR;
    rod.end = bob.pos;
}

void Pendulum::draw() {
    rod.draw();
    bob.draw();
}

/*
T = I x alpha
T = F x r
F = m x g x sin(theta)

alpha = (F x r) / I 
alpha = (m x g x sin(theta) x CoM) / I 

CoM = ((ball.mass x (ball.radius + rod.length)) + (rod.mass x rod.length x0.5)) / (ball.mass + rod.mass)
*/