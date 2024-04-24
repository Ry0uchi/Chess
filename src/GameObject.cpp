#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject( const char* texturesheet )
{
    objTexture = TextureManager::LoadTexture( texturesheet );
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(objTexture);
}

void GameObject::UpdateBoard(int xpos, int ypos)
{
    srcRect.h = 680;
    srcRect.w = 680;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 510;
    destRect.h = 510;
}

void GameObject::UpdateChessPiece(int xpos, int ypos)
{
    srcRect.h = 1125;
    srcRect.w = 1125;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 50;
    destRect.h = 50;
}

void GameObject::UpdateButton(int xsrc, int ysrc, int xdect, int ydest)
{
    srcRect.h = 229;
    srcRect.w = 104;
    srcRect.x = xsrc;
    srcRect.y = ysrc;

    destRect.x = xdect;
    destRect.y = ydest;
    destRect.w = 229 * (70/104);
    destRect.h = 70;
}

void GameObject::UpdateScreen()
{
    srcRect.h = 720;
    srcRect.w = 1280;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = 0;
    destRect.y = 0;
    destRect.w = 1280;
    destRect.h = 720;
}

SDL_bool GameObject::PointInRect(const SDL_Point* p)
{
    return SDL_PointInRect(p, &destRect);
}

void GameObject::Render()
{
    SDL_RenderCopy( game::renderer, objTexture, &srcRect, &destRect );
}
