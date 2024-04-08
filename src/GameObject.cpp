#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject( const char* texturesheet )
{
    objTexture = TextureManager::LoadTexture( texturesheet );
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

void GameObject::Render()
{
    SDL_RenderCopy( game::renderer, objTexture, &srcRect, &destRect );
}
