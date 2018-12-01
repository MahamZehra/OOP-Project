#include "Screen.h"

Screen::Screen(LTexture* background_)
{
    screenWidth = (*background_).GetWidth();
    screenHeight = (*background_).GetHeight();
}

int Screen :: GetScore()
{
    return Score;
}

int Screen :: GetHealth()
{
    return Health;
}

int Screen :: GetLevel()
{
    return Level;
}

int Screen :: GetTimeLeft()
{
    return TimeLeft;
}

void Screen :: RenderText(SDL_Renderer* gRenderer, string textureText, TTF_Font* gFont, SDL_Color textColor, Point coordinates, Point dimensions)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        SDL_Texture* mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            SDL_Rect Message_rect;
            Message_rect.x = coordinates.x;
            Message_rect.y = coordinates.y;
            Message_rect.w = dimensions.x;
            Message_rect.h = dimensions.y;

            SDL_RenderCopy(gRenderer, mTexture, NULL, &Message_rect);
        }

        SDL_FreeSurface( textSurface );
    }
}

void Screen :: Render(SDL_Renderer* grenderer)
{
    background -> RenderTexture(0, 0, grenderer);
}
