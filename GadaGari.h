#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vehicle.h"

class GadaGari : public Vehicle
{
private:
public:
    GadaGari();
    GadaGari(SDL_Texture* image, int x, int y);
    ~GadaGari();
    void Draw(SDL_Renderer* gRenderer);
};
