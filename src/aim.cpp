#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "aim.h"

using namespace std;

Aim::Aim() : ImageSprite()
{
    generatePosition(400,300,87,90);
    generateClips();
    SDL_ShowCursor(0);
    m_clipNumber = 0;
}

Aim::~Aim()
{
    release();
}

void 
Aim::init()
{
    loadFromFile("res/images/s_hud.png");
}

void 
Aim::draw()
{
    SDL_Rect clip = m_clips.at(m_clipNumber);
    imageLoad->update(m_texture, &clip, &m_position);
}

void 
Aim::update()
{
    m_clipNumber = 0;
}

void
Aim::overPlayer(SDL_Rect rect)
{   
    if (m_position.x < rect.x && m_position.x > rect.x-45 && m_position.y < rect.y+55 && m_position.y > rect.y-45)
        m_clipNumber = 2;
}

void 
Aim::release()
{
	SDL_DestroyTexture(m_texture);
}

void
Aim::generateClips()
{
    addClip(100,0,87,90);
    addClip(200,0,87,90);
    addClip(300,0,87,90);
}

bool 
Aim::handle(SDL_Event& event)
{
	bool processed = false;
    switch (event.type)
    {
        case SDL_MOUSEMOTION:
            m_position.x = event.motion.x;
            m_position.y = event.motion.y;
            processed = true;
        break;

        case SDL_MOUSEBUTTONDOWN:
            processed = true;
        break;

        case SDL_MOUSEBUTTONUP:
            processed = true;
        break;

        default:
        break;
    }
    return processed;
}
