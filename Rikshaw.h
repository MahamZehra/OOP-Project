#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
#include "LTexture.h"

enum DIRECTION{UP,LEFT,RIGHT,BACK};

class Rikshaw : public GameObject
{
private:
    bool alive;
    int health;
    int xpos;
    int ypos;
    LTexture* rikshaw;

   // static Rikshaw instance = new Rikshaw(LTexture*, 0, 0, int, int);

protected:

public:
     Rikshaw(LTexture* image, int, int, int, int);
    ~Rikshaw();
    SDL_Rect rectangle, srcRect;
    void Render(SDL_Renderer* gRenderer);
    void Move(int direction);   //Moves rikshaw to avid obstacles
    void fellIntoGutter();  //When it falls into the gutter
    void accident();
    void update();
    void Set_x(int);
    void Set_y(int);
    int Get_x();
    int Get_y();
    SDL_Rect Get_Rect();    //when it crashes into one of the other vehicles
    //static Rikshaw getObject(); //Singeloton object
};
