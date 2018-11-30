#include "SDL.h"
#include "SDL_image.h"
#include "Obstacle.h"

class ObstacleVehicle : public Obstacle
{
private:
    int xpos;
    int ypos;
    int Speed;
    LTexture* obstacle;
    bool alive;

protected:

public:
    SDL_Rect rectangle, srcRect;
    bool GetAlive();
    ObstacleVehicle();
    ObstacleVehicle(LTexture* image, int, int, int, int); //Position, dimensions and sprite of bus, truck or gadagari
    ~ObstacleVehicle();
    void Render(SDL_Renderer* gRenderer);   //display on screen

};
