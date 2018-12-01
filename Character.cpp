#include"Character.h"
#include "LTexture.h"
#include <cmath>
#include<iostream>
Character::Character()
{

}

Character::Character(LTexture* image, float x, float y, int ascii)
{
    m_spriteSheetTexture = image;

    //width and height of each alphabet

    m_spriteClips.w = 60;                   //original 60
    m_spriteClips.h = 56;                   //original 56

    int diff=0;

    ///selects the Character image according to its ascii value

    if(ascii==33)
    {
        m_spriteClips.x = 337.2;
        m_spriteClips.y = 271.75;
        m_spriteClips.w = 60;
        m_spriteClips.h = 56;
    }

//if question mark
    else if(ascii==63)
    {
        m_spriteClips.x=270;
        m_spriteClips.y=271.75;
    }
//if alphabets
    else if(( ascii >= 65 && ascii <=90) || (ascii >= 97 && ascii <= 122) )
    {
        if(( ascii>=97) && (ascii<=122) )
        {
            m_character_value = 97;
            m_spriteClips.x = 3;            //starting point of x
            m_spriteClips.y = 5;            //starting point of y
            diff = ascii - m_character_value;

            if ((diff>=0) && (diff<=5))
            {

                m_spriteClips.x = m_spriteClips.x + (m_spriteClips.x*2 + 0.8 + m_spriteClips.w)*diff;
                m_spriteClips.y = 5;
            }


            else if ((diff > 5) && (diff <= 11))
            {

                diff = ascii - 6 - m_character_value;
                m_spriteClips.x = m_spriteClips.x + (m_spriteClips.x*2 + 0.8 + m_spriteClips.w)*diff;
                m_spriteClips.y = m_spriteClips.y + (m_spriteClips.y*2 + 0.8 + m_spriteClips.h)*1;

            }
            else if ((diff > 11) && (diff <= 17))
            {
                diff = ascii - 12 - m_character_value;

                m_spriteClips.x = m_spriteClips.x + (m_spriteClips.x*2 + 0.8 + m_spriteClips.w)*diff;
                m_spriteClips.y = m_spriteClips.y + (m_spriteClips.y*2 + 0.8 + m_spriteClips.h)*2;

            }

            else if ((diff > 17) && (diff <= 23))
            {
                diff = ascii - 18 - m_character_value;

                m_spriteClips.x = m_spriteClips.x + (m_spriteClips.x*2 + 0.8 + m_spriteClips.w)*diff;
                m_spriteClips.y = m_spriteClips.y + (m_spriteClips.y*2 + 0.8 + m_spriteClips.h)*3;

            }

            else if ((diff > 23) && (diff <= 25))
            {
                diff = ascii - 24 - m_character_value;

                m_spriteClips.x = m_spriteClips.x + (m_spriteClips.x*2 + 0.8 + m_spriteClips.w)*diff;
                m_spriteClips.y = m_spriteClips.y + (m_spriteClips.y*2 + 0.8 + m_spriteClips.h)*4;

            }

        }
    }

    m_character_value=ascii;

    m_position.x = x;
    m_position.y = y;
    this->mc_width = m_spriteClips.w;
    this->mc_height = m_spriteClips.h;


}


Character::~Character()
{

}

void Character::Render( SDL_Renderer* gRenderer)
{
    m_spriteSheetTexture -> RenderTexture( m_position.x, m_position.y , gRenderer, &m_spriteClips);
}

void Character::operator = (const Character& cpy)
{
    this->m_position=cpy.m_position;
    this->m_spriteClips=cpy.m_spriteClips;

    this->m_spriteSheetTexture=cpy.m_spriteSheetTexture;
    this->m_character_value=cpy.m_character_value;
    this->mc_width=cpy.mc_width;
    this->mc_height=cpy.mc_height;
}
