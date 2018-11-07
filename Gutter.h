#pragma once

#include "GameObject.h"

class Gutter : public GameObject
{
private:
    SDL_Rect mover;     //to know the position/ width and height
    LTexture* image;

protected:

public:
    Gutter(LTexture*);
    ~Gutter();
    void Render(SDL_Renderer* gRenderer);
};

