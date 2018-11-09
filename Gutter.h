#pragma once

#include "Obstacle.h"

class Gutter : public Obstacle
{
private:
    LTexture* image;

protected:

public:
    Gutter(LTexture*, int, int, int, int);
    ~Gutter();
    void Render(SDL_Renderer* gRenderer);
};

