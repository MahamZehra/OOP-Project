#pragma once

#include "Screen.h"
#include "LTexture.h"

class EndScreen : public Screen
{
private:

protected:

public:
    EndScreen(LTexture*);   //what about the buttons?
    ~EndScreen();
    void Render(SDL_Renderer*);
    void updateRecords(int level);  //saves progress/ score

};
