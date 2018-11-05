#pragma once

#include "Screen.h"
#include <SDL.h>

class GameScreen : public Screen
{
private:

protected:

public:
    GameScreen(LTexture*);
    ~GameScreen();
    void Render(SDL_Renderer*);

    // if p pressed, PauseScreen opens
};
