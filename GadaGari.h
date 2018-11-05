#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vehicle.h"

class GadaGari : public Vehicle
{
private:

protected:

public:
    GadaGari();
    GadaGari(SDL_Texture* image, int x, int y);
    ~GadaGari();
    void Render(SDL_Renderer* gRenderer);
};
