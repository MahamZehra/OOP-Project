#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <string>
#include "string.h"
#include "LTexture.h"
#include "Rikshaw.h"
#include <iostream>
#include "ObstacleVehicle.h"
#include "Queue.h"
#include "Gutter.h"
//#include "Character.h"
//#include "Word.h"
//#include "Button.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 650;
LTexture gRikshawTexture;
LTexture gBGTexture;
LTexture gObstacleTexture;
LTexture gGutterTexture;

//Button* buttons = NULL;
//std::string ButtonText[3]={"CONTINUE", "NEW GAME","  EXIT  "};
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

bool CheckCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    //std::cout<<"abc"<<std::endl;
    return true;
}
bool loadMedia()
{
	///Loading success flag
	bool success = true;
	/*if( !ButtonTexture.loadTexture( "1.jpg", gRenderer) )
	{
		printf( "Failed to load buttons!\n" );
		success = false;
	}

	if ( !CharacterTexture.loadTexture("Alphabets.jpg", gRenderer))
    {
        printf( "Failed to load alphabets!\n" );
		success = false;

    }*/
   // gRikshawTexture.loadTexture("cars.jpeg", gRenderer);
    if ( !gRikshawTexture.loadTexture("rikshaw.JPEG", gRenderer))
    {
        printf( "Failed to load alphabets!\n" );
		success = false;

    }

    if( !gBGTexture.loadTexture( "background.JPEG", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}

	if( !gObstacleTexture.loadTexture( "rikshaw.JPEG", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}


    if( !gGutterTexture.loadTexture( "gutter.JPEG", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}


    return success;
}



void close()
{
	///free loaded images
    //ButtonTexture.free();
    gRikshawTexture.free();
    gBGTexture.free();
    gObstacleTexture.free();
    gGutterTexture.free();
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

			bool quit = false;
            Rikshaw* rikshaw;
            Queue listt;
            rikshaw = new Rikshaw(&gRikshawTexture,300,600,NULL,NULL);
            ObstacleVehicle* obstacle;
            obstacle = new ObstacleVehicle(&gObstacleTexture, 400, 300, NULL,NULL);
            Gutter* gutter;

            //flags to check which screen is running
            long int frame = 0;
            int scrollingOffset = 0;

            bool mouseClicked = false; //flag indicating mouse click
            //Button* buttons = NULL;   //will hold button(s) on the screen
            int x,y;
			SDL_Event e;
			//While application is running
			while( !quit )
			{
			    SDL_RenderClear(gRenderer);

			    if(frame % 100 == 0)
                {
                    gutter = new Gutter(&gGutterTexture, 200,400,NULL,NULL);
                    listt.Enqueue(gutter);


                }
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

                    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
                    {
                         rikshaw->Move(RIGHT);
                         rikshaw -> update();
                        if(CheckCollision(rikshaw-> rectangle, obstacle -> rectangle))
                        {

                            rikshaw -> Set_x(rikshaw->Get_x()-20);
                        }
                    }

                    if(currentKeyStates[ SDL_SCANCODE_LEFT ])
                    {
                        rikshaw->Move(LEFT);
                             rikshaw -> update();
                        if(CheckCollision(rikshaw-> rectangle, obstacle -> rectangle))
                        {

                            rikshaw -> Set_x(rikshaw->Get_x()+20);
                        }
                    }

                    if(currentKeyStates[ SDL_SCANCODE_UP ])
                    {
                        rikshaw->Move(UP);
                         rikshaw -> update();
                        if(CheckCollision(rikshaw-> rectangle, obstacle -> rectangle))
                        {

                            rikshaw -> Set_y(rikshaw->Get_y()+20);
                        }
                    }

                    if(currentKeyStates[ SDL_SCANCODE_DOWN ])
                    {
                        rikshaw->Move(BACK);
                         rikshaw -> update();
                        if(CheckCollision(rikshaw-> rectangle, obstacle -> rectangle))
                        {

                            rikshaw -> Set_y(rikshaw->Get_y()-20);
                        }
                    }
					/*SDL_GetMouseState(&x,&y);

                    if (e.type==SDL_MOUSEBUTTONDOWN)
                    {
                        if(e.button.button==SDL_BUTTON_LEFT)
                            mouseClicked=true;
                            cout<<"Mouse Clicked"<<endl;
                    }*/

                --scrollingOffset;
				if( scrollingOffset <= -gBGTexture.GetHeight() )
				{
					scrollingOffset = 0;
				}

                gBGTexture.RenderTexture( 0, scrollingOffset, gRenderer );
				gBGTexture.RenderTexture( 0, scrollingOffset + gBGTexture.GetHeight(), gRenderer );
                rikshaw -> Render(gRenderer);
                //obstacle -> Render(gRenderer);
                listt.Render()
                gutter -> Render(gRenderer);

                //SDL_RenderClear(gRenderer);
                //SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                SDL_RenderPresent(gRenderer);
			}
			frame++;
		}
	}
	//free resources and close SDL
	close();

}
return 0;
}
