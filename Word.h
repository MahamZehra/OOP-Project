#pragma once

#include "LTexture.h"
#include "Character.h"
//-----------------------------------WORD CLASS-----------------//
class Word
{
    public:
        Point position;                 //position of the word
        std::string text;               //text that the object word contains
        //to assist in the size of the button
        int wordLen;                    //length of the word
        int width;                      //width of the word
        int height;                     //height of the word
        LTexture* spriteSheetTexture;
        Character* char_word;           //dynamic array of characters


    protected:

    private:
        Word();
        Word(std::string, LTexture*, float, float );
        ~Word();
        void Render(SDL_Renderer*);                 //to draw the word on screen
        int getLength();
        int getWidth();
        void form_Word(std::string);               //forms the Word by changing the text of the word
        void operator = (const Word&);              //operating overloading for assignment operator.
        std::string getText();                      //text in the word object
};

#endif // WORD_H
