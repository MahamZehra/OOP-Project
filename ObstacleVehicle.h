#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vehicle.h"

class ObstacleVehicle : public Vehicle
{
private:
    int Speed;

protected:

public:
    ObstacleVehicle();
    ObstacleVehicle(LTexture* image, int, int, int, int); //Position, dimensions and sprite of bus, truck or gadagari
    ~ObstacleVehicle();
    void Render(SDL_Renderer* gRenderer);   //display on screen
    
};
