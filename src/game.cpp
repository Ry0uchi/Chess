#include "TextureManager.h"
#include "game.hpp"
#include "GameObject.h"
#include "Map.h"
#include "EventManager.h"
#include "Menu.h"

const int CELL_SIZE = 60;

Menu* m_Menu;
EventManager* m_Event;
GameObject* Board;
Map* m_Map;
SDL_Renderer* game::renderer = nullptr;
int prevGame[8][8] = {};
GameState state = MENU;
Mix_Chunk* Capture = NULL;
Mix_Chunk* Move = NULL;
Mix_Chunk* ButtonClick = NULL;


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
        if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) 
        {
            std::cout << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
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
    m_Menu = new Menu();
    Capture = Mix_LoadWAV("assets/capture.mp3");
    if(!Capture) std::cout<<"Capture sound not loaded\n";
    Move = Mix_LoadWAV("assets/move-self.mp3");
    ButtonClick = Mix_LoadWAV("assets/click-button.mp3");

}

void game::handleEvents()
{
    //std::cout<<"ok\n";
    m_Event->Listen();
    SDL_Point Mouse;
    Vect2f pos = m_Event->GetMousePos();
    SDL_GetMouseState(&Mouse.x, &Mouse.y);
    Vect2i Bpos = Vect2i((pos.X - xBoard) / CELL_SIZE, (pos.Y - yBoard) / CELL_SIZE);

    if (m_Event->isKeyDown(SDL_SCANCODE_ESCAPE) || m_Event->isRunning() == false)
    {
        isRunning = false;
    }
    else if(m_Event->MouseButtonDown(LEFT) && state == MENU)
    {
        for (auto button : m_Menu->m_Buttons)
        {
            if (button->PointInRect(&Mouse))
            {
                Mix_PlayChannel(-1, ButtonClick, 0);
                if (button == m_Menu->NewGameButton)
                {
                    m_Map->NewGame();
                    state = GAME;
                    break;
                }
                else if (button == m_Menu->ExitButton)
                {
                    isRunning = false;
                    break;
                }
                else if (button == m_Menu->ContinueButton)
                {
                    if(m_Menu->HavePrevGame(prevGame))
                    {
                        m_Map->LoadBoard(prevGame);
                        state = GAME;
                    }
                    else
                    {
                        std::cout<<"No previous game\n";
                        state = GAME;
                        m_Map->LoadMap();
                    }
                    break;
                }
            }
        }
    }
    else if(m_Event->MouseButtonDown(LEFT) && state == GAME)
    {
        if (m_Map->BackButton->PointInRect(&Mouse))
            {
                Mix_PlayChannel(-1, ButtonClick, 0);
                state = MENU;
            }
        //std::cout<<Mouse.x<<" "<<Mouse.y<<"\n";
        if (Bpos.X >= 0 && Bpos.X < 8 && Bpos.Y >= 0 && Bpos.Y < 8)
        {
            if (!m_Event->isSelected())
            {
                //std::cout<<"Selecting....\n";
                for (auto piece : m_Map->whitePieces)
                {
                if(piece->image->PointInRect(&Mouse))
                    {
                    piece->image->UpdateChessPiece(pos.X - 25, pos.Y -25);
                    std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                    m_Event->SetSelected(true);
                    piece->isChoose = true;
                    break;
                    }
                }

                if(!m_Event->isSelected())
                {
                    for (auto piece : m_Map->blackPieces)
                    {
                        if(piece->image->PointInRect(&Mouse))
                        {
                            piece->image->UpdateChessPiece(pos.X - 25, pos.Y -25);
                            std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                            m_Event->SetSelected(true);
                            piece->isChoose = true;
                            break;
                        }
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
                        std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                        break;
                    }
                }
                for (auto piece : m_Map->blackPieces)
                {
                    if(piece->isChoose)
                    {
                        piece->image->UpdateChessPiece(pos.X - 25, pos.Y -25);
                        std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                        break;
                    }
                }
            }
        }
    }
    else if(!m_Event->MouseButtonDown(LEFT) && state == GAME)
        {
            bool* isMove = new bool(true);
            //eating piece
            for (auto piece : m_Map->whitePieces)
            {
                if (piece->isChoose)
                {
                    if (piece->IsMovementPossible(Bpos) && m_Map->IsPlaceClear(Bpos, piece->isWhite) && (piece->GetName() == PieceName::Knight || (piece->GetName() == PieceName::Pawn && m_Map->IsPawnCrossed(piece->Bpos, piece->isWhite)) || m_Map->IsPathClear(piece->Bpos, Bpos)))
                    {
                        bool* isCapture = new bool(false);
                        std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                        piece->SetPosition(Bpos);
                        piece->image->UpdateChessPiece(piece->Bpos.X*60 + xBoard + 5, piece->Bpos.Y*60 + yBoard + 5);
                        piece->isChoose = false;
                        *isMove = false;
                        for (auto enemy : m_Map->blackPieces)
                        {
                            if (enemy->Bpos == Bpos)
                            {
                                enemy->SetDead();
                                Mix_PlayChannel(-1, Capture, 0);
                                *isCapture = true;
                                break;
                            }
                        }
                        if(!*isCapture)
                            {
                                Mix_PlayChannel(-1, Move, 0);
                                delete isCapture;
                            }
                        break;
                    }
                    else
                    {
                        piece->image->UpdateChessPiece(piece->Bpos.X*60 + xBoard + 5, piece->Bpos.Y*60 + yBoard + 5);
                        piece->isChoose = false;
                        *isMove = false;
                        break;
                    }
                }
            }
            if (*isMove)
            {
                for (auto piece : m_Map->blackPieces)
                {
                    if (piece->isChoose)
                    {
                        if (piece->IsMovementPossible(Bpos) && m_Map->IsPlaceClear(Bpos, piece->isWhite) && (piece->GetName() == PieceName::Knight || (piece->GetName() == PieceName::Pawn && m_Map->IsPawnCrossed(piece->Bpos, piece->isWhite)) || m_Map->IsPathClear(piece->Bpos, Bpos)))
                        {
                            bool* isCapture = new bool(false);
                            std::cout<<piece->Bpos.X<<" "<<piece->Bpos.Y<<"\n";
                            piece->SetPosition(Bpos);
                            piece->image->UpdateChessPiece(piece->Bpos.X*60 + xBoard + 5, piece->Bpos.Y*60 + yBoard + 5);
                            piece->isChoose = false;
                            for (auto enemy : m_Map->whitePieces)
                            {
                                if (enemy->Bpos == Bpos)
                                {
                                    enemy->SetDead();
                                    Mix_PlayChannel(-1, Capture, 0);
                                    *isCapture = true;
                                    break;
                                }
                            }
                            if(!*isCapture)
                            {
                                Mix_PlayChannel(-1, Move, 0);
                                delete isCapture;
                            }
                            break;
                        }
                        else
                        {
                            piece->image->UpdateChessPiece(piece->Bpos.X*60 + xBoard + 5, piece->Bpos.Y*60 + yBoard + 5);
                            piece->isChoose = false;
                            break;
                        }
                    }
                }
            }
            delete isMove;
            m_Event->SetSelected(false);
            if (state == GAME) prevGame[8][8] = m_Map->SaveGame(prevGame);
        }
}

void game::update()
{
    Board->UpdateBoard(640-255, 360-255);
    if(state == GAME)
        m_Map->Update();
}
void game::render()
{
    SDL_RenderClear ( renderer );
    Board->Render();
    if(state == GameState::MENU) m_Menu->DrawMenu();
    else if(state == GameState::GAME){
        m_Map->DrawMap();
    }
    //add stuff to render
    SDL_RenderPresent( renderer );
}
void game::clean()
{
    SDL_DestroyWindow ( window );
    SDL_DestroyRenderer ( renderer );
    Mix_FreeChunk(Capture);
    Mix_FreeChunk(Move);
    Mix_FreeChunk(ButtonClick);
    m_Map->Delete();
    delete m_Event;
    delete m_Menu;
    delete Board;
    delete m_Map;
    Mix_CloseAudio();
    SDL_Quit();
    std::cout << "Game Clean\n";
}

