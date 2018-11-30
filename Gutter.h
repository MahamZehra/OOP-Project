#pragma once

#include "Obstacle.h"

class Gutter : public Obstacle
{
private:
    LTexture* gutter;
    int xpos;
    int ypos;
protected:

public:
    Gutter();
    Gutter(LTexture*, int, int, int, int);
    ~Gutter();

    void Render(SDL_Renderer* gRenderer);
};
