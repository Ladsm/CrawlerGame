#include <string>
#include "MainMenu.h"
#include "Inventory.h"
#include "ActionMenu.h"

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
    SetConsoleTextAttribute(h, 4);
    std::cout << "/--- GAME MENU ---/\n";
    SetConsoleTextAttribute(h, 7);
    if (!fight) { std::cout << "1. Action\n"; }
    else { std::cout << "1. Fight\n"; }
    std::cout << "2. Stats and inventory\n";
    std::cout << "3. Save Game\n";
    std::cout << "4. Load Game\n";
    std::cout << "5. Quit\n";
    std::cout << "Enter the number of your choice\n";
}

void Gamemenu_Large_Menu() {
    std::string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
    Gamemenu_Large_Write();
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
    case 1:
        system("cls");
        Gamemenu_Action_Menu();
        break;
    case 2:
        system("cls");
        Gamemenu_Inventory_Menu();
        break;
    case 3:
        system("cls");
        Crplayer.saveToFile(saveFile);
        std::cout << "Game saved!\n";
        break;
    case 4:
        system("cls");
        Menu_Loadgame();
        break;
    case 5:
        system("cls");
        PlaySound(TEXT("Sounds&Mus\\Gamemenu\\leaveing.wav"), NULL, SND_FILENAME);
        exit(1);
        break;
    default:
        system("cls");
        Menu_Switch_Fail();
        break;
    }
}

void Gamemenu_Action_Write() {
    if (!fight) {
        switch (Story) {
        case 0:
            actionMenu.ActionWrite(DefaltSet);
            break;
        case 1:
            actionMenu.ActionWrite(FirstSet);
            break;
        default:
            actionMenu.ActionWrite(DefaltSet);
            break;
        }
    }
    else {
        actionMenu.ActionWrite(FightSet);
    }
}

void Gamemenu_Action_Menu() {
    Gamemenu_Action_Write();
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
        actionMenu.ActionMenuMenu(FightSet);
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
        system("cls");
        Gamemenu_Inventory_Menu();
        break;
    case 2:
        std::cout << "Which item do you want to remove?\n";
        std::cin >> placement;
        LocalInventory.Inv_RemoveItemFromInv_User(placement);
        system("cls");
        Gamemenu_Inventory_Menu();
        break;
    case 3:
        system("cls");
        Gamemenu_Large_Menu();
        break;
    default:
        system("cls");
        Menu_Switch_Fail();
        Gamemenu_Inventory_Menu();
    }
}

void PlayerDead() {
    int choice;
    std::string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
    std::cout << "/--- YOU DEAD ---/\n";
    std::cout << "1. Continue from last save\n";
    std::cout << "2. Quit\n";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        if (Crplayer.loadFromFile(saveFile))
            std::cout << "Game loaded!\n";
        else
            std::cout << "Failed to load game.\n";
        break;
    case 2:
        system("cls");
        exit(1);
        break;
    default:
        system("cls");
        Menu_Switch_Fail();
        break;
    }
}

void Menu_Loadgame() {
    int choice;
    std::string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
    std::cout << "Are you sure?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";
    std::cin >> choice;
    switch (choice) {
    case 1:
        if (Crplayer.loadFromFile(saveFile)) {
            system("cls");
            std::cout << "Game loaded!\n";
        }
        else {
            std::cout << "Failed to load game.\n";
        }
        break;
    default:
        system("cls");
        break;
    }
}