#include "Rikshaw.h"

Rikshaw::Rikshaw(LTexture* image, int x, int y, int w, int h)
{
    rikshaw = image;
    xpos = x;
    ypos = y;

    rectangle.x = xpos;
    rectangle.y = ypos;
    rectangle.w = w;
    rectangle.h = h;


    alive = true;

}

Rikshaw::~Rikshaw()
{
    rikshaw = NULL;
}

void Rikshaw::Render(SDL_Renderer* gRenderer)
{
    rikshaw -> RenderTexture(xpos, ypos,gRenderer);
}

void Rikshaw::update()
{

    srcRect.h = 50;
    srcRect.w =50;
    srcRect.x = 50;
    srcRect.y = 50;

    rectangle.x = xpos ;
    rectangle.y = ypos;
    rectangle.w = srcRect.w*1.70;
    rectangle.h = srcRect.h*1.75;

}
void Rikshaw::Move(int direction)
{
    if(direction==LEFT)
    {
        xpos = xpos - 5;
    }

    if(direction==RIGHT)
    {
        //cout<<xpos<<endl;
        xpos = xpos + 5;
    }

    if(direction==UP)
    {
        ypos = ypos - 5;
    }

    if(direction==BACK)
    {
        ypos = ypos + 5;
    }

}

void Rikshaw::Set_x(int x)
{
    xpos = x;
}

void Rikshaw::Set_y(int y)
{
    ypos = y;
}

int Rikshaw::Get_x()
{
    return xpos;
}

int Rikshaw:: Get_y()
{
    return ypos;
}
SDL_Rect Rikshaw:: Get_Rect()
{
    return rectangle;
}
void Rikshaw::fellIntoGutter()
{

}

void Rikshaw::accident()
{

}
