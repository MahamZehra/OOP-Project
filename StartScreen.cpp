#include "StartScreen.h"
#include <fstream>

StartScreen :: StartScreen(LTexture* background_) : Screen(background_)
{
    background = background_;
}

//void StartScreen :: Render(SDL_Renderer* grenderer)
//{
//   background -> RenderTexture(0, 0, grenderer);
//}

void StartScreen :: LoadData()
{
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Records.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening the record");
    }

    fgets(buff, 32, (FILE*)filePointer); //Reading the name of the driver directly
    Score = atoi(buff);

    fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
    Health = atoi(buff);                   //Converting the string to integer

    fgets(buff, 32, (FILE*)filePointer);
    TimeLeft = atoi(buff);

    fgets(buff, 32, (FILE*)filePointer);
    Level = atoi(buff);

    fclose(filePointer);                        //Closing file
}
void StartScreen :: RenderMovingObject(LTexture* Sheet_, SDL_Renderer* gRenderer)
{
    SDL_Rect clipped;
    clipped.x = 340;
    clipped.y = 379;
    clipped.w = 700 - 340;
    clipped.h = 700 - 379;

    Sheet_ -> RenderTexture(340, 400, gRenderer, &clipped, 225, 255);
}
