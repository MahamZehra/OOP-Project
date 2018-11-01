#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Vehicle
{
private:
    SDL_Rect mover;
    SDL_Texture* image;
public:
    Vehicle();
    virtual ~Vehicle();
    virtual void Draw(SDL_Renderer* gRenderer) = 0;
};
