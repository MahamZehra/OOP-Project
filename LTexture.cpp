#include"LTexture.h"


LTexture::LTexture()
{
    texture = NULL;
    m_width = 0;
    m_height = 0;
}

LTexture::~LTexture()
{
    free();
}

bool LTexture::loadTexture(string path, SDL_Renderer* gRenderer, bool flagColorKey, Uint8 redColorKey, Uint8 greenColorKey, Uint8 blueColorKey)
{
    SDL_Surface* surface_texture = NULL;    //surface over which texture is to be loaded
    SDL_Texture* newTexture = NULL;         //the actual texture

    surface_texture = IMG_Load(path.c_str());       //load image on the texture

    //if no image on the surface
    if(surface_texture == NULL)
    {
        cout << "Unable to load image from " << path << ". SDL_image error"<< IMG_GetError() << endl;
    }

    //if image placed on the surface
    else
    {
        SDL_SetColorKey(surface_texture, flagColorKey, SDL_MapRGB(surface_texture->format, 0, 255, 255));

        //place texture on the renderer
        newTexture = SDL_CreateTextureFromSurface(gRenderer, surface_texture);

        //if surface placed
        if( newTexture != NULL)
        {
            //setting dimensions
            m_width = surface_texture->w;
            m_height = surface_texture->h;
        }
        else
        {
            cout<< "Unable to create texture from surface from "<<path<< ". SDL_image error"<< IMG_GetError()<<endl;
        }

        //free space
        SDL_FreeSurface(surface_texture);
    }
    //setting texture
    texture = newTexture;

    return texture != NULL;
}


void LTexture::RenderTexture(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip, SDL_RendererFlip flip, double angle, SDL_Point* center,float scale)
{
    SDL_Rect rectCoordinates = {x, y, m_width, m_height};


    //width and height according to the clipped part
    if(clip != NULL)
    {
        rectCoordinates.w = clip->w;
        rectCoordinates.h = clip->h;
    }

    rectCoordinates.w *= scale;
    rectCoordinates.h *= scale;

    SDL_RenderCopyEx(gRenderer, texture, clip, &rectCoordinates, angle, center, flip);
    //SDL_RenderPresent(gRenderer);
}

//free memory
void LTexture::free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        m_width = 0;
        m_height = 0;
    }
}


int LTexture::GetWidth()
{
    return m_width;
}

int LTexture::GetHeight()
{
    return m_height;
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
    SDL_SetTextureBlendMode( texture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( texture, alpha );
}
