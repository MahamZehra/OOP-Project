#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vehicle.h"

class Bus : public Vehicle
{
private:

protected:

public:
    Bus();
    Bus(LTexture* image, int x, int y); //Position and sprite of bus
    ~Bus();
    void Render(SDL_Renderer* gRenderer);   //display on screen
};
