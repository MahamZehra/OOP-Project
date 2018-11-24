#include"Character.h"
#include "LTexture.h"
#include<iostream>
Character::Character()
{

}

Character::Character(LTexture* image, float x, float y, int ascii)
{
    m_spriteSheetTexture = image;

    //width and height of each alphabet

    m_spriteClips.w = 60;
    m_spriteClips.h = 55;

    int diff=0;

    ///selects the Character image according to its ascii value

    if(ascii==33)
    {
        m_spriteClips.x = 337.2;
        m_spriteClips.y = 271.75;
        m_spriteClips.w = 60;
        m_spriteClips.h = 55;

    }

    /*else if(ascii>=48 && ascii<=57)
    {
        m_character_value = 48;

        //clipping from the sprite sheet

        m_spriteClips.x = 295;
        m_spriteClips.y = 205;

        diff = ascii-m_character_value;

        if (diff>4)
        {
            m_spriteClips.x = 0;
            m_spriteClips.y += m_height + 12;
            m_character_value += 5;
            diff = ascii - m_character_value;
        }

        m_spriteClips.x += 41*diff;
    }*/
//if question mark
    else if(ascii==63)
    {
        m_spriteClips.x=270;
        m_spriteClips.y=271.75;
    }
//if alphabets
    else if((ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122))
    {
        if((ascii>=97) && (ascii<=122))
        ascii-=32;
        m_character_value = 65;
        m_spriteClips.x = 0;
        m_spriteClips.y = 0;
        diff=ascii-m_character_value;
        m_spriteClips.y +=32*(diff/8);
        m_character_value+=8*(diff/8);
        diff=ascii-m_character_value;
        m_spriteClips.x+=42*diff;
    }

    m_character_value=ascii;

    m_position.x = x;
    m_position.y = y;

    this->m_width = m_spriteClips.w;
    this->m_height = m_spriteClips.h;
}

Character::~Character()
{

}

void Character::Render( SDL_Renderer* gRenderer)
{
    m_spriteSheetTexture -> RenderTexture( m_position.x - m_width/2, m_position.y - m_height/2, gRenderer, &m_spriteClips);

        /*SDL_Rect rect = { m_position.x - m_width/2, m_position.y - m_height/2, m_width, m_height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
*/
}

void Character::operator = (const Character& cpy)
{
    this->m_position=cpy.m_position;
    this->m_spriteClips=cpy.m_spriteClips;

    this->m_spriteSheetTexture=cpy.m_spriteSheetTexture;
    this->m_character_value=cpy.m_character_value;
    this->m_width=cpy.m_width;
    this->m_height=cpy.m_height;
}
