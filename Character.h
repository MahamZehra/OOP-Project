#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"

//---------------------------------CHARACTER CLASS-----------------------------//
class Character
{
    public:
        Character();
        Character(LTexture* image, float x, float y, int ascii_value);
        ~Character();
        void Render(SDL_Renderer* gRenderer, bool debug);
        void operator = (const Character& cpy);

    protected:

    private:
        Point position;
        int ascii_value;
        int width;
        int height;
        SDL_Rect sprite_clip;
        LTexture* sprite;
};

#endif // CHARACTER_H
