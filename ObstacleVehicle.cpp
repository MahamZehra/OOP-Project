#include "ObstacleVehicle.h"

ObstacleVehicle::ObstacleVehicle(LTexture* image, int x, int y, int w, int h)
{
   obstacle = image;
    xpos = x;
    ypos = y;


    srcRect.h = 50;
    srcRect.w =50;
    srcRect.x = 50;
    srcRect.y = 50;

    rectangle.x = xpos ;
    rectangle.y = ypos;
    rectangle.w = srcRect.w * 2;
    rectangle.h = srcRect.h * 3;
}



void ObstacleVehicle::Render(SDL_Renderer* gRenderer)
{
    obstacle -> RenderTexture(xpos, ypos,gRenderer);

}

ObstacleVehicle::~ObstacleVehicle()
{
    //dtor
}
