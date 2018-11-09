#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "GameObject.h"

enum DIRECTION{UP,LEFT,RIGHT,BACK};

class Rikshaw : public GameObject
{
private:
    bool alive;
    int health;
    Rikshaw(SDL_Texture* image, int, int, int, int);
    static Rikshaw instance = new Rikshaw(SDL_Texture*, 0, 0);

protected:

public:
    ~Rikshaw();
    void Render(SDL_Renderer* gRenderer);
    void Move(int direction);   //Moves rikshaw to avid obstacles
    void fellIntoGutter();  //When it falls into the gutter
    void accident();    //when it crashes into one of the other vehicles
    static Rikshaw getObject(); //Singeloton object
};
