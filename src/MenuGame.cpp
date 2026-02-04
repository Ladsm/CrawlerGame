#include <string>
#include "MainMenu.h"
#include "Inventory.h"
#include "ActionMenu.h"
#include "MenuExterns.h"
#if defined(_WIN32)
#include "resource1.h"
#endif
#include <cstdlib>

extern bool fight;
extern bool devMode;
extern Inventory LocalInventory;
extern ActionSet DefaltSet;
extern ActionSet FirstSet;
extern ActionSet FightSet;
extern ActionMenu actionMenu;

void Gamemenu_Inventory_Write();
void Gamemenu_Inventory_Menu();
void Gamemenu_Action_Menu();
void Menu_Loadgame();

int Story = 1;

void Gamemenu_Large_Write() {
#if defined(_WIN32)
    SetConsoleTextAttribute(h, 4);
#endif
    std::cout << "/--- GAME MENU ---/\n";
#if defined(_WIN32)
    SetConsoleTextAttribute(h, 7);
#endif
    if (!fight) { std::cout << "1. Action\n"; }
    else { std::cout << "1. Fight\n"; }
    std::cout << "2. Stats and inventory\n";
    std::cout << "3. Save Game\n";
    std::cout << "4. Load Game\n";
    std::cout << "5. Quit\n";
    std::cout << "Enter the number of your choice\n";
}

void Gamemenu_Large_Menu() {
#if defined(_WIN32)
    std::string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
#elif defined(__linux__)
    std::string saveFile = "savegame.CrGS";
#endif
    Gamemenu_Large_Write();
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
    case 1:
        clear();
        Gamemenu_Action_Menu();
        break;
    case 2:
        clear();
        Gamemenu_Inventory_Menu();
        break;
    case 3:
        clear();
        Crplayer.saveToFile(saveFile);
        std::cout << "Game saved!\n";
        break;
    case 4:
        clear();
        Menu_Loadgame();
        break;
    case 5:
        clear();
#if defined(_WIN32)
        PlaySound(MAKEINTRESOURCE(IDR_WAVE6), GetModuleHandle(NULL), SND_RESOURCE | SND_SYNC);
#endif
        std::_Exit(0);
        break;
    default:
        clear();
        Menu_Switch_Fail();
        break;
    }
}

void Gamemenu_Action_Menu() {
    if (!fight) {
        switch (Story) {
        case 0:
            actionMenu.ActionMenuMenu(DefaltSet);
            break;
        case 1:
            actionMenu.ActionMenuMenu(FirstSet);
            break;
        default:
            actionMenu.ActionMenuMenu(DefaltSet);
            break;
        }
    }
    else {
        actionMenu.FightActionMenu();
    }
}

void Gamemenu_Inventory_Write() {
    if (devMode == true) {
        std::cout << "Story = " << Story << '\n';
    }
    Crplayer.displayStats();
    LocalInventory.displayInventory();
    std::cout << "1. Use an item from inventory\n";
    std::cout << "2. Remove an item from inventory\n";
    std::cout << "3. Back\n";
}

void Gamemenu_Inventory_Menu() {
    Gamemenu_Inventory_Write();
    int choice;
    int placement =+1;
    std::cin >> choice;
    switch (choice) {
    case 1:
        std::cout << "Which item do you want to use?\n";
        std::cin >> placement;
        LocalInventory.Inv_UseItem(placement);
        clear();
        Gamemenu_Inventory_Menu();
        break;
    case 2:
        std::cout << "Which item do you want to remove?\n";
        std::cin >> placement;
        LocalInventory.Inv_RemoveItemFromInv_User(placement);
        clear();
        Gamemenu_Inventory_Menu();
        break;
    case 3:
        clear();
        Gamemenu_Large_Menu();
        break;
    default:
        clear();
        Menu_Switch_Fail();
        Gamemenu_Inventory_Menu();
    }
}

void PlayerDead() {
    int choice;
#if defined(_WIN32)
    std::string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
#elif defined(__linux__)
    std::string saveFile = "savegame.CrGS";
#endif
    textColor(1);
    std::cout << "/--- YOU DEAD ---/\n";
    textColor(2);
    std::cout << "1. Continue from last save\n";
    std::cout << "2. Quit\n";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        clear();
        if (Crplayer.loadFromFile(saveFile))
            std::cout << "Game loaded!\n";
        else
            std::cout << "Failed to load game.\n";
        break;
    case 2:
        clear();
        std::_Exit(0);
        break;
    default:
        clear();
        Menu_Switch_Fail();
        break;
    }
}

void Menu_Loadgame() {
    int choice;
#if defined(_WIN32)
    std::string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
#elif defined(__linux__)
    std::string saveFile = "savegame.CrGS";
#endif
    std::cout << "Are you sure?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";
    std::cin >> choice;
    switch (choice) {
    case 1:
        if (Crplayer.loadFromFile(saveFile)) {
            clear();
            std::cout << "Game loaded!\n";
        }
        else {
            std::cout << "Failed to load game.\n";
        }
        break;
    default:
        clear();
        break;
    }
}