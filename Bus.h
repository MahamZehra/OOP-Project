#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vehicle.h"

class Bus : public Vehicle
{
private:
public:
    Bus();
    Bus(SDL_Texture* image, int x, int y);
    ~Bus();
    void Draw(SDL_Renderer* gRenderer);
};
