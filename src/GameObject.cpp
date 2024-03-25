#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject( const char* texturesheet, int x, int y )
{
    objTexture = TextureManager::LoadTexture( texturesheet );

    xpos = x;
    ypos = y;
}

void GameObject::UpdateBoard()
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

void GameObject::Render()
{
    SDL_RenderCopy( game::renderer, objTexture, &srcRect, &destRect );
}
