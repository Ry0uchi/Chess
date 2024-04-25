#include "Menu.h"

Menu::Menu()
{
    m_Menu->UpdateScreen();
    NewGameButton->UpdateButton(505, 160, 700, 525);
    ExitButton->UpdateButton(20, 400, 700 + 165*2, 525);
    ContinueButton->UpdateButton(505, 280, 700 + 165, 525);
}

Menu::~Menu()
{
    delete m_Menu;
    delete NewGameButton;
    delete ExitButton;
    delete ContinueButton;
}

void Menu::DrawMenu()
{
    m_Menu->Render();

    NewGameButton->Render();
    ExitButton->Render();
    ContinueButton->Render();
}

bool Menu::HavePrevGame(int Chess[8][8])
{
    int WhiteChess[8][8] = {
        {5, 4, 3, 2, 1, 3, 4, 5},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {-6, -6, -6, -6, -6, -6, -6, -6},
        {-5, -4, -3, -2, -1, -3, -4, -5}
    };

    int BlackChess[8][8] = {
        {-5, -4, -3, -2, -1, -3, -4, -5},
        {-6, -6, -6, -6, -6, -6, -6, -6},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {5, 4, 3, 2, 1, 3, 4, 5}
    };

    if (Chess == NULL || Chess == WhiteChess || Chess == BlackChess)
        return false;
    return true;
}

int Menu::NewGame()
{
    int Chess[8][8] = {
        {5, 4, 3, 2, 1, 3, 4, 5},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {-6, -6, -6, -6, -6, -6, -6, -6},
        {-5, -4, -3, -2, -1, -3, -4, -5}
    };
    return Chess[8][8];
}
