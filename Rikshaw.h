#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Vehicle.h"

enum DIRECTION{UP,LEFT,RIGHT};

class Rikshaw : public Vehicle
{
private:
    bool alive;
    int health;

protected:

public:
    Rikshaw();
    Rikshaw(SDL_Texture* image, int x, int y);
    ~Rikshaw();
    void Render(SDL_Renderer* gRenderer);
    void Move(int direction);   //Moves rikshaw to avid obstacles
    void fellIntoGutter();  //When it falls into the gutter
    void accident();    //when it crashes into one of the other vehicles
};
