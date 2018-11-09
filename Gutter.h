#pragma once

#include "GameObject.h"

class Gutter : public GameObject
{
private:
    LTexture* image;

protected:

public:
    Gutter(LTexture*, int, int, int, int);
    ~Gutter();
    void Render(SDL_Renderer* gRenderer);
};

