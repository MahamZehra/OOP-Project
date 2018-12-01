#include "Button.h"
#include<vector>
#include<sstream>

using namespace std;

Button::Button()
{
    width = 0;
    height = 0;
    ButtonWidth = 0;
    state = 0;
    word = NULL;
}

Button::Button(LTexture* image, LTexture*image2 ,string text, float x, float y)
{
    state = Normal;                                               ///initial state of button is always Normal

    ///position of the button on the screen


    position.x = x;
    position.y = y;

    spriteSheetTexture = image;

    this->text = text;                          //text to be placed on the button

    cout<<"TEXT RECEIVED : "<<this->text<<endl;
    ///button states
    ///normal state
    spriteClips[Normal].x = 0;
    spriteClips[Normal].y = 0;
    spriteClips[Normal].w = 229;        //width = 205
    spriteClips[Normal].h = 75;       //height = 69.5

    ///hover
    spriteClips[Hover].x = 0;
    spriteClips[Hover].y = 75;
    spriteClips[Hover].w = 229;
    spriteClips[Hover].h = 75;

    /*
    spriteClips[Clicked].x = 0;
    spriteClips[Clicked].y = 396;
    spriteClips[Clicked].w = 32;
    spriteClips[Clicked].h = 60;*/

    //setting buttons width and height

    this -> width = spriteClips[0].w;
    this -> height = spriteClips[0].h;


    int textLength= text.size();             ///size of the text



    int wordlen = 64;

      ButtonWidth = (wordlen * (textLength - 3)) + this->width;

      word = new Word(text, image2, position.x + 26 , position.y + 10);
      //cout<<"cal"<<((((this->width/64) -3) * 64)/2)<<endl;
}

void Button::Render(SDL_Renderer* gRenderer)
{
    int textLength = word->getLength();         //length of the word

    cout << word << endl;

    float posX = position.x; ///Position for the left part of the button on the screen

    cout<<"left part : "<<posX<<endl;

    spriteClips[state].x = 0;  ///selects the spriteClip according to Button State
    spriteSheetTexture->RenderTexture( posX, position.y, gRenderer, &spriteClips[state],SDL_FLIP_NONE);
    ///left button
    spriteSheetTexture->RenderTexture( posX, position.y, gRenderer, &spriteClips[state],SDL_FLIP_HORIZONTAL);

    spriteClips[state].x = 32;        ///Middle part of the Button
    cout<<spriteClips[state].w<<endl;
                    ///limit of the for loop (below) decided according to text size
    //loop for middle part


    ///rendering middle part of the button as a background for each character in the Word
    for(int i=0; i<textLength-3; i++)
    {
        posX += 70;

        spriteSheetTexture->RenderTexture( posX, position.y, gRenderer, &spriteClips[state]);
    }


    word->Render(gRenderer);
}

Point Button::getPosition()
{
    return position;
}

int Button::getWidth()
{
    return ButtonWidth;
}

int Button::getHeight()
{
    return height;
}

string Button::getText()
{
    return text;
}

void Button::changeState(State val)
{
    state=val;
}

bool Button::clicked()
{
    return (state == Clicked);
}
Button::~Button()
{
    cout <<"Button " << text << " is destroyed" << endl;
    if (word != NULL)
    {
        delete word;
        word = NULL;
    }
}

void Button::operator = (const Button& cpy)
{
    state=cpy.state;
    position.x=cpy.position.x;
    position.y=cpy.position.y;
    spriteSheetTexture=cpy.spriteSheetTexture;
    text=cpy.text;
    spriteClips[Normal]=cpy.spriteClips[Normal];
    spriteClips[Hover]=cpy.spriteClips[Hover];
    spriteClips[Clicked]=cpy.spriteClips[Clicked];
    width=cpy.width;
    height=cpy.height;
    ButtonWidth = cpy.ButtonWidth;
    this->word = new Word(text,spriteSheetTexture,position.x,position.y+8);
}


