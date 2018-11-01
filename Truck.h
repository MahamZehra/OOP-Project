#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
public:
    Truck();
    Truck(SDL_Texture* image, int x, int y);
    ~Truck();
    void Draw(SDL_Renderer* gRenderer);
};
