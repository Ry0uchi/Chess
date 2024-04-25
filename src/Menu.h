#pragma once

#include "game.hpp"
#include "TextureManager.h"
#include "GameObject.h"

class Menu
{
    public:
    bool havePrevGame = false;
    GameObject* m_Menu = new GameObject("assets/chess-game.png");
    GameObject* NewGameButton = new GameObject("assets/button.png");
    GameObject* ExitButton = new GameObject("assets/button.png");
    GameObject* ContinueButton = new GameObject("assets/button.png");
    
    
    bool prevGame = false;
    Menu();
    ~Menu();
    
    std::vector<GameObject*> m_Buttons = {NewGameButton, ExitButton, ContinueButton};
    void DrawMenu();
    int NewGame();
    void Exit();
    void Continue();
    void SaveGame(int Chess[8][8]);
    bool HavePrevGame(int Chess[8][8]);
};
