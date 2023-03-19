/**
 * @file Star.cpp
 * @author Will Skaggs
 */

#include "Star.h"
#include <raymath.h>

const float StarSpeed = -700; ///< The speed of the star in the z-axis in pixels per second
const float StarRadius = 3; ///< The radius of the star in pixels
const Color StarColor = GOLD; ///< The color of the star and its trail

/**
 * Convenience function to set a random position for the star.
 */
void Star::SetRandomPos() {
    int screenWid = GetScreenWidth(), screenHit = GetScreenHeight();
    float randX, randY, randZ;

    randX = GetRandomValue(-screenWid / 2, screenWid / 2);
    randY = GetRandomValue(-screenHit / 2, screenHit / 2);
    randZ = GetRandomValue(0, screenWid);
    mPos = {randX, randY, randZ};
    mPrevZ = mPos.z;
}

/**
 * Convenience function to get the draw position of the star based on a z-position
 *
 * @param posZ the z-position of the star
 */
Vector2 Star::GetDrawPos(float posZ) const {
    int centerScreenX = GetScreenWidth() / 2;
    int centerScreenY = GetRenderHeight() / 2;

    float drawX = centerScreenX + Remap(mPos.x / posZ, -1, 1, -GetScreenWidth() / 2, GetScreenWidth() / 2);
    float drawY = centerScreenY + Remap(mPos.y / posZ, -1, 1, -GetScreenHeight() / 2, GetScreenHeight() / 2);
    return {drawX, drawY};
}


/**
 * Constructor
 */
Star::Star() {
    SetRandomPos();
}

/**
 * Update this star
 *
 * @param elapsed time since the last update in seconds
 */
void Star::Update(double elapsed) {
    mPrevZ = mPos.z;

    float speed = Remap(GetMouseX(), 0, GetScreenWidth(), 0, StarSpeed);
    mPos.z += elapsed * speed;

    if (mPos.z < 0) {
        SetRandomPos();
    }
}

/**
 * Draw this star to the screen
 */
void Star::Draw() const {
    Vector2 drawPos = GetDrawPos(mPos.z);
    Vector2 prevDrawPos = GetDrawPos(mPrevZ);
    float radius = Remap(mPos.z, 0, GetScreenWidth(), StarRadius, 0);

    DrawCircleV(drawPos, radius, StarColor);
    DrawLineV(drawPos, prevDrawPos, StarColor);
}