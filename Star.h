/**
 * @file Star.h
 * @author Will Skaggs
 *
 * An instance of this class represents a single star in the star field
 */

#pragma once

#include <raylib.h>

/**
 * An instance of this class represents a single star in the star field
 */
class Star {
private:
    Vector3 mPos; ///< The position of the star in pixels relative to center screen
    float mPrevZ; ///< The previous z-coordinate of the star in pixels

    void SetRandomPos();
    Vector2 GetDrawPos(float posZ) const;

public:
    Star();

    void Update(double elapsed);
    void Draw() const;
};
