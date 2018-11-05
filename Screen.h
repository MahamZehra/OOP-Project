#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "LTexture.h"
#include "Button.h" //will be added to project later

class Screen
{
private:

protected:
    int screenWidth;
    int screenHeight;
    LTexture* background;    //background image of the screen
    int numOfBtns;  //number of buttons on the screen
    Button* buttons = nullptr;  //array of pointers of Button type

public:
    Screen(LTexture);
    virtual ~Screen();
    virtual void Render(SDL_Renderer*) = 0; //generation of screen
    void mouseMotionEvents(int x, int y);   //handles mouse motion events on a screen
    void mouseClickEvents(int x, int y,Mix_Chunk* buttonClick); //handles mouse click events on a screen
};
