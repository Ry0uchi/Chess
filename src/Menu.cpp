#include "Menu.h"

Menu::Menu()
{
    m_Menu->UpdateScreen();
    NewGameButton->UpdateButton(505, 160, 725, 470);
    ExitButton->UpdateButton(20, 160, 725 + 155 + 120, 470);
    ContinueButton->UpdateButton(505, 208, 725+353, 500);
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



