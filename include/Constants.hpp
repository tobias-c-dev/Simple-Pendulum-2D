#pragma once

namespace Constants {

    // Window
    inline constexpr float SCREEN_WIDTH = 1800.0f;
    inline constexpr float SCREEN_HEIGHT = 900.0f;
    inline constexpr float PPM = 200.0f;

    // Environment
    constexpr Vector2 GRAVITY = {0, 9.81f};
    constexpr float DAMPING_CONSTANT = 20.0f;
    
    // Pendulum
    constexpr Vector2 ANCHOR = {SCREEN_WIDTH / 2.0f, 200.0f};
    constexpr float INITAL_ANGLE = 1.3f;
    constexpr float INITAL_ANGULAR_VELOCITY = 0.0f;
    constexpr float ROD_LENGTH = 400.0f;
    constexpr float ROD_RADIUS = 1.0f;
    constexpr float ROD_MASS = 3.0f;
    constexpr float BOB_RADIUS = 18.0f;
    constexpr float BOB_MASS = 6.0f;

}