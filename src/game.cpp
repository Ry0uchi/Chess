#include "TextureManager.h"
#include "game.hpp"
#include "GameObject.h"
#include "Map.h"
#include "EventManager.h"

const int CELL_SIZE = 60;

EventManager* m_Event;
GameObject* Board;
Map* m_Map;

SDL_Renderer* game::renderer = nullptr;

game::game()
{}

game::~game()
{}

void game::init ( const char * title, int xpos, int ypos, int width, int height, bool fullscreen )
{
    int flags = 0;
    if ( fullscreen )
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if ( SDL_Init ( SDL_INIT_EVERYTHING ) == 0)
    {
        std::cout << "Subsystem Initilized!\n";
        window = SDL_CreateWindow ( title, xpos, ypos, width, height, flags);
        if ( window )
        {
          std::cout << "Window Created\n";
        }
        renderer = SDL_CreateRenderer ( window, -1, 0 );
        if ( renderer )
        {
            SDL_SetRenderDrawColor ( renderer, 255, 255, 255, 255 );
          std::cout << "Renderer Created\n";
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }


    m_Event = new EventManager();
    Board = new GameObject("assets/Chess_Wood.png");
    m_Map = new Map();

}

void game::handleEvents()
{
    //std::cout<<"ok\n";
    m_Event->Listen();
}

void game::update()
{
    SDL_Point Mouse;
    SDL_Rect destRect;
    Vect2f pos = m_Event->GetMousePos();
    Vect2i Bpos = Vect2i((pos.X - xBoard) / CELL_SIZE, (pos.Y - yBoard) / CELL_SIZE);
    if (m_Event->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        isRunning = false;
    }
    else if(m_Event->MouseButtonDown(LEFT))
    {
        //std::cout<<"Run!\n";
        
        
        SDL_GetMouseState(&Mouse.x, &Mouse.y);
        //std::cout<<Mouse.x<<" "<<Mouse.y<<"\n";
        if (Bpos.X >= 0 && Bpos.X < 8 && Bpos.Y >= 0 && Bpos.Y < 8)
        {
            if (!m_Event->isSelected())
            {
                //std::cout<<"Selecting....\n";
                for (auto piece : m_Map->whitePieces)
                {
                destRect = piece->image->GetDestRect();
                if(piece->image->PointInRect(&Mouse))
                    {
                    piece->image->UpdateChessPiece(pos.X - 25, pos.Y -25);
                    std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                  //  piece->SetPosition(pos.X - 25, pos.Y - 25);
                   // std::cout<<"Selected!\n";
                    m_Event->SetSelected(true);
                    piece->isChoose = true;
                    break;
                    }
                }


                for (auto piece : m_Map->blackPieces)
                {
                    destRect = piece->image->GetDestRect();
                    if(piece->image->PointInRect(&Mouse))
                    {
                    piece->image->UpdateChessPiece(pos.X - 25, pos.Y -25);
                    piece->SetPosition(pos.X - 25, pos.Y - 25);
                    std::cout<<"Selected!\n";
                    m_Event->SetSelected(true);
                    piece->isChoose = true;
                    break;
                    }
                }
            }
            else
            {
                for (auto piece : m_Map->whitePieces)
                {
                    if(piece->isChoose)
                    {
                        piece->image->UpdateChessPiece(pos.X - 25, pos.Y -25);
                        //piece->SetPosition(pos.X - 25, pos.Y - 25);
                        std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                        //std::cout<<"Selected!\n";
                        break;
                    }
                }
                for (auto piece : m_Map->blackPieces)
                {
                    if(piece->isChoose)
                    {
                        piece->image->UpdateChessPiece(pos.X - 25, pos.Y -25);
                        piece->SetPosition(pos.X - 25, pos.Y - 25);
                        std::cout<<"Selected!\n";
                        break;
                    }
                }
            }
        }
    }
        else if(!m_Event->MouseButtonDown(LEFT))
        {
            //eating piece
            for (auto piece : m_Map->whitePieces)
            {   
                if (piece->isChoose)
                {   
                    if (piece->IsMovementPossible(Bpos) && m_Map->IsPlaceClear(Bpos, piece->isWhite) && (piece->name == PieceName::Knight || piece->name == PieceName::Pawn || m_Map->IsPathClear(piece->Bpos, Bpos)))
                    {
                        piece->Bpos = Bpos;
                        for (auto enemy : m_Map->blackPieces)
                        {
                            if (enemy->Bpos == piece->Bpos)
                            {
                                enemy->SetDead();
                            }
                        }
                        std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                        piece->SetPosition(piece->Bpos.X * CELL_SIZE + xBoard, piece->Bpos.Y * CELL_SIZE + yBoard);
                       
                        piece->image->UpdateChessPiece(piece->pos.X + 5, piece->pos.Y + 5);
                        piece->isChoose = false;
                    }
                    else
                    {
                        piece->SetPosition(piece->Bpos.X * CELL_SIZE + xBoard, piece->Bpos.Y * CELL_SIZE + yBoard);
                        piece->image->UpdateChessPiece(piece->pos.X + 5, piece->pos.Y + 5);
                        piece->isChoose = false;
                    }
                }
            }
            for (auto piece : m_Map->blackPieces)
            {
                if (piece->isChoose)
                {
                    piece->SetPosition(piece->Bpos.X * CELL_SIZE + xBoard, piece->Bpos.Y * CELL_SIZE + yBoard);
                    for (auto enemy : m_Map->whitePieces)
                    {
                        if (enemy->Bpos == piece->Bpos)
                        {
                            enemy->SetDead();
                        }
                    }
                    piece->image->UpdateChessPiece(piece->pos.X + 5, piece->pos.Y + 5);
                    piece->isChoose = false;
                }
            }
            m_Event->SetSelected(false);
            //std::cout<<"Up!\n";
        }
    
    Board->UpdateBoard(640-255, 360-255);
    m_Map->Update();
}
void game::render()
{
    SDL_RenderClear ( renderer );
    Board->Render();
    m_Map->DrawMap();
    //add stuff to render
    SDL_RenderPresent( renderer );
}
void game::clean()
{
    SDL_DestroyWindow ( window );
    SDL_DestroyRenderer ( renderer );
    m_Map->Delete();
    delete m_Event;
    SDL_Quit();
    std::cout << "Game Clean\n";
}

