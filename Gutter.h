#pragma once

#include "GameObject.h"

class Gutter : public GameObject
{
private:
    SDL_Rect mover;
    SDL_Texture* image;

protected:

public:
    Gutter();
    ~Gutter();
    void Render(SDL_Renderer* gRenderer);
};

