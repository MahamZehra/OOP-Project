#pragma once

#include "Screen.h"

class ExcerptScreen : public Screen
{
public:
    ExcerptScreen(LTexture*);
    ~ExcerptScreen();
    void Render(SDL_Renderer*);
};
