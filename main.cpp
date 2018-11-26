#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <string>
#include "string.h"
#include "LTexture.h"
#include <iostream>
#include "Character.h"
#include "Word.h"
#include "Button.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 650;
LTexture ButtonTexture;
LTexture CharacterTexture;

Button* buttons = NULL;
std::string ButtonText[3]={"CONTINUE", "NEW GAME","  EXIT  "};
//Starts up SDL and creates window
bool init();

//Loads media


void close();

//Loads individual image as texture

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

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
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
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
	return success;
}

bool loadMedia()
{
	///Loading success flag
	bool success = true;
	if( !ButtonTexture.loadTexture( "1.jpg", gRenderer) )
	{
		printf( "Failed to load buttons!\n" );
		success = false;
	}

	if ( !CharacterTexture.loadTexture("Alphabets.jpg", gRenderer))
    {
        printf( "Failed to load alphabets!\n" );
		success = false;

    }
	else
    { 
        ///Set standard alpha blending
        ButtonTexture.setBlendMode( SDL_BLENDMODE_BLEND );
    }
    return success;
}



void close()
{
	///free loaded images
    ButtonTexture.free();

	///Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	///Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argv, char** args)
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
		    /*LTexture* newT = new LTexture;
		    Button btn(&ButtonTexture,"CUTIE", 150,200);
		    //buttons = new Button[3];
    /*for(int i=0; i<3; i++)
    {
        buttons[i] = Button(&ButtonTexture,ButtonText[i],100, 16 + 50);
        //posY+=100;
    }*/
//		    Button but(newT,"CUTIE", 250,200);
		    //ButtonTexture.RenderTexture(50, 100, gRenderer);
		    //Character obj(&CharacterTexture, 150, 150, 121);

		    //obj.Render(gRenderer);
		    //Word hi;
		    //Word hi("crazy", &CharacterTexture, 300, 200);
		    //hi.Render(gRenderer);
		    Button bro(&ButtonTexture,&CharacterTexture,"faizan", 300, 200);
		    bro.Render(gRenderer);


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
                            cout<<"Mouse Clicked"<<endl;
                    }

                    SDL_SetRenderDrawColor(gRenderer, 50, 230, 230, 2);
                    //SDL_RenderClear(gRenderer);
                    SDL_RenderPresent(gRenderer);
			}
		}
	}
	//free resources and close SDL
	close();
    return 0;
}
}


