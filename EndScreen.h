#pragma once

#include "Screen.h"
#include "LTexture.h"

class EndScreen : public Screen
{
private:
    //Since the game has option to play again, button is required
    LTexture* button;
    LTexture* font;

protected:

public:
    EndScreen(LTexture*, LTexture*, LTexture*);
    ~EndScreen();
    void Render(SDL_Renderer*);
    void updateRecords(int level);  //saves progress/ score

};
