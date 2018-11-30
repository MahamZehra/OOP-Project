#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "GameObject.h"

class Obstacle : public GameObject
{
private:

protected:

public:
    Obstacle();
     Obstacle(LTexture*, int, int, int, int);
    virtual ~Obstacle();
};
