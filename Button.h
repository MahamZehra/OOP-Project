#pragma once
#include "LTexture.h"
#include "Point.h"
#include "word.h"

//-------------------------MOUSE STATES---------------------------------//
enum mouse_state
{
	BUTTON_SPRITE_MOUSE_NORMAL = 0,
	BUTTON_SPRITE_MOUSE_HOVER = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
};

//---------------------------class button---------------------------------//

class Button
{
    public:
        Button();
        Button(LTexture*, std:string, float, float);
        void Render(SDL_Renderer*);
        ~Button();
        Point getPosition();
        int getWidth();
        int getHeight();
        std:string getText();
        void shift_state(State);                //changing the current state of the Button
        void operator = (const Button& cpy);
        bool clicked();                         //checks if button is pressed

    protected:

    private:
        int width;                  //width of the Button
        int height;                 //height of the Button
        std::string text;           //text to be put on the Button
        word* Word;                 //object of the text to be put on the button
        SDL_Rect spriteClips[4];    //sprites for 4 states of the buttons
        LTexture* texture_button;   //texture of button
        Point position;             //position of buttons
        int button_state;           //state of the button_state
};

#endif // BUTTON_H
