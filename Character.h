#ifndef CHARACTER_H
#define CHARACTER_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"

class Character
{
private:
    Point m_position; //Position of the Character
    int m_character_value = 0; //ascii value of the Character
    int m_width; //width of character
    int m_height; //height of character
    SDL_Rect m_spriteClips; //clip specific to the Character
    LTexture* m_spriteSheetTexture; //font image
public:
    Character();
    Character(LTexture* image, float x, float y, int ascii);
    ~Character();
    void Render(SDL_Renderer* gRenderer);
    void operator = (const Character& cpy); //operator overloading for assignment operatot
};



#endif // CHARACTER_H
