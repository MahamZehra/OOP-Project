#pragma onc

#include "LTexture.h"

class PauseScreen : public Screen
{
private:
    SDL_Rect screen;    //for position, width and height of pause screen on the entire screen
    LTexture* button;
    LTexture* font;

protected:

public:
    PauseScreen(LTexture*, LTexture*, LTexture*);
    ~PauseScreen();
    void Render(SDL_Renderer*);

};
