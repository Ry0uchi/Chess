#pragma once

#include "game.hpp"
#include "TextureManager.h"
#include "GameObject.h"



class Menu
{
    GameObject* m_Menu = new GameObject("assets/chess-game.png");
    GameObject* NewGameButton = new GameObject("assets/Button.png");
    GameObject* ExitButton = new GameObject("assets/Button.png");
    GameObject* ContinueButton = new GameObject("assets/Button.png");
    bool prevGame = false;

    public:
    Menu();
    ~Menu();
    void DrawMenu();
    bool NewGame();
    void Exit();
    void Continue();
    bool HavePrevGame(int Chess[8][8]);

};
