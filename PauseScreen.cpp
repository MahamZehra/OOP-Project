#include "PauseScreen.h"
#include <fstream>

PauseScreen :: PauseScreen(LTexture* background_) : Screen(background_)
{
    background = background_;
}

//void PauseScreen :: Render(SDL_Renderer* grenderer)
//{
//   background -> RenderTexture(0, 0, grenderer);
//}

void PauseScreen :: WriteData(int Score_, int Health_, int TimeLeft_, int Level_)
{
    ofstream write;
    write.open("Records.txt");

    write << Score_ << endl << Health_ << endl << TimeLeft_ << Level_ << endl;

    write.close();
}
//PauseScreen::~PauseScreen()
//{
//    //dtor
//}
