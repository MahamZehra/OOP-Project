#include <iostream>
#include "LTexture.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

using namespace std;

bool init();
bool loadMedia();
void close();
void setAlpha();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gFontTexture;
const int SCREEN_WIDTH =  500;
const int SCREEN_HEIGHT = 200;
Uint8 a = 255; //one component is set to full opaque
Uint8 b = 0; //other is full transparent
Uint8 button = 170; //for controlling alpha value of other textures
Uint8 button_screen = 200; //for controlling alpha value of other textures
int main(int argv, char** args )
{
    //Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;
            //flags to check which screen is running
            long int frame = 0;

            bool mouseClicked = false; //flag indicating mouse click
            //Button* buttons = NULL;   //will hold button(s) on the screen
            int x,y;
			SDL_Event e;
			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					SDL_GetMouseState(&x,&y);

                    if (e.type==SDL_MOUSEBUTTONDOWN)
                    {
                        if(e.button.button==SDL_BUTTON_LEFT)
                            mouseClicked=true;
                            cout<<"hi"<<endl;
                    }
                    /*
                    if (e.type == SDL_MOUSEMOTION) //to handle all mouse motion events for all screens
                    {
                        GameScreen.mouseMotionEvents(x,y);
                        mainMenu.mouseMotionEvents(x,y);
                        PauseScreen.mouseMotionEvents(x,y);
                        QuitScreen.mouseMotionEvents(x,y);
                        gameOver.mouseMotionEvents(x,y);
                    }
                    if(e.type == SDL_MOUSEBUTTONUP && mouseClicked) //tp handle all mouse click events for all screens
                    {

                        GameScreen.mouseClickEvents(x,y,buttonClick);
                        mainMenu.mouseClickEvents(x,y,buttonClick);
                        PauseScreen.mouseClickEvents(x,y,buttonClick);
                        QuitScreen.mouseClickEvents(x,y,buttonClick);
                        gameOver.mouseClickEvents(x,y,buttonClick);
                        mouseClicked = false;
                    }*/

                //Clear screen
				SDL_SetRenderDrawColor( gRenderer,  0, 0, 0, 0 );
				SDL_RenderClear( gRenderer );



				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}
	//Free resources and close SDL
	close();
    return 0;
}
}
bool init()
{
	///Initialization flag
	bool success = true;

	///Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		///Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		///Create window
		gWindow = SDL_CreateWindow( "CRAZY RICKSHAW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}

		else
		{
			///Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				///Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}
	/*if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        success = false;
    }*/
	return success;
}

bool loadMedia()
{
	///Loading success flag
	bool success = true;
	if( !gFontTexture.LoadFromFile( "button.png", gRenderer) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	else
    {
        ///Set standard alpha blending
        gFontTexture.setBlendMode( SDL_BLENDMODE_BLEND );
    }
    return success;
}
void close()
{
	///Free loaded images
    gFontTexture.Free();

	///Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	///Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
void setAlpha()
{
    ///Cap if below 0
    if( a - 3 < 0 )
    {
        a = 0;
    }
    ///Decrement otherwise
    else
    {
        a -= 3;
    }
    ///Cap if above 255
    if( b+ 3 > 255 )
    {
        b=255;
    }
    ///Increment otherwise
    else
    {
        b += 3;
    }
}

