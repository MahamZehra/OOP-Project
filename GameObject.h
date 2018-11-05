#pragma once

#include <iostream>
#include <string>
#include<SDL.h>
#include<SDL_image.h>

using namespace std;

enum Motion {right, left, up, down};

class GameObject
{
private:

protected:
    SDL_Rect position;  //Position of the object
    SDL_Texture* image; //Sprite/Image of the object
    string name = "";   //Name of object

public:
    GameObject(SDL_Texture*, int, int);
    virtual ~GameObject();
    virtual void Render(SDL_Renderer*) = 0;
};
