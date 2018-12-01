#include "ExcerptScreen.h"
#include <iostream>

using namespace std;

ExcerptScreen :: ExcerptScreen(LTexture* background_) : Screen(background_)
{
    background = background_;
}

//void ExcerptScreen :: Render(SDL_Renderer* grenderer)
//{
//    background -> RenderTexture(0, 0, grenderer);
//}

void ExcerptScreen :: RenderName(LTexture* Sheet_, SDL_Renderer* gRenderer)
{
    SDL_Rect clipped;
    clipped.x = 0;
    clipped.y = 105;
    clipped.w = 593;
    clipped.h = 216 - 105;

    for(float i = -40; i <= 45; i+=1)
    {
        background -> RenderTexture(0, 0, gRenderer);
        Sheet_ -> RenderTexture(i, 155, gRenderer, &clipped, 265 - (i * 2), 950 - (6.5 * i));
        SDL_RenderPresent( gRenderer );
    }
}

//ExcerptScreen :: ~ExcerptScreen()
//{
//    cout << "The ExcerptScreen has been destroyed." << endl;
//}
