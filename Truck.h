#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vehicle.h"

class Truck : public Vehicle
{
private:

protected:

public:
    Truck();
    Truck(LTexture* image, int x, int y);
    ~Truck();
    void Render(SDL_Renderer* gRenderer);
};
