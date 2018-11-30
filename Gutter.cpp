#include "Gutter.h"

Gutter::Gutter(LTexture* image, int x, int y, int w, int h)
{
    gutter = image;
    position.x = x;
    position.y = y;
    position.w = w;
    position.h = h;
}

Gutter::~Gutter()
{
    //dtor
}

void Gutter::Render(SDL_Renderer* gRenderer)
{
    gutter -> RenderTexture(xpos, ypos,gRenderer);
}
