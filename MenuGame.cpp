#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Inventory.h"

extern Inventory LocalInventory;

void Gamemenu_Inventory_Write();
void Gamemenu_Inventory_Menu();
void Gamemenu_Action_Menu();
void Menu_Loadgame();

void Gamemenu_Large_Write() {
    SetConsoleTextAttribute(h, 4);
    std::cout << "/--- GAME MENU ---/\n";
    SetConsoleTextAttribute(h, 7);
    std::cout << "1. Action\n";
    std::cout << "2. Stats and inventory\n";
    std::cout << "3. Save Game\n";
    std::cout << "4. Load Game\n";
    std::cout << "5. Quit\n";
    std::cout << "Enter the number of your choice\n";
}

void Gamemenu_Large_Menu() {
    Gamerunnin = true;
    std::string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
    Gamemenu_Large_Write();
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
    case 1:
        Gamemenu_Action_Menu();
        break;
    case 2:
        Gamemenu_Inventory_Menu();
        break;
    case 3:
        Crplayer.saveToFile(saveFile);
        std::cout << "Game saved!\n";
        break;
    case 4:
        Menu_Loadgame();
        break;
    case 5:
        PlaySound(TEXT("Sounds&Mus\\Gamemenu\\leaveing.wav"), NULL, SND_FILENAME);
        exit(1);
        break;
    default:
        Menu_Switch_Fail();
        break;
    }
}

static void Gamemenu_Action_Write() {
    SetConsoleTextAttribute(h, 4);
    std::cout << "/--- Action MENU ---/\n";
    SetConsoleTextAttribute(h, 7);
    std::cout << "1. #NOT DONE\n";
    std::cout << "2. #NOT DONE\n";
    std::cout << "3. #NOT DONE\n";
    std::cout << "4. #NOT DONE\n";
    std::cout << "5. Back\n";
    std::cout << "Enter the number of your choice\n";
}

void Gamemenu_Action_Menu() {
    Gamemenu_Action_Write();
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        Gamemenu_Large_Menu();
        break;
    default:
        Menu_Switch_Fail();
        break;
    }
}

void Gamemenu_Inventory_Write() {
    Crplayer.displayStats();
    LocalInventory.displayInventory();
    std::cout << "1. Use an item from inventory\n";
    std::cout << "2. Remove an item from inventory\n";
    std::cout << "3. Back\n";
}

void Gamemenu_Inventory_Menu() {
    Gamemenu_Inventory_Write();
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "Which item do you want to use?\n";
        int placement = +1;
        std::cin >> placement;
        LocalInventory.Inv_UseItem(placement);
        Gamemenu_Inventory_Menu();
        return;
    }
    if(choice == 2) {
        std::cout << "Which item do you want to remove?\n";
        int placement = +1;
        std::cin >> placement;
        LocalInventory.Inv_RemoveItemFromInv_User(placement);
        Gamemenu_Inventory_Menu();
        return;
    }
    if (choice == 3) {
        Gamemenu_Large_Menu();
        return;
    }
    else {
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
        if (Crplayer.loadFromFile(saveFile))
            std::cout << "Game loaded!\n";
        else
            std::cout << "Failed to load game.\n";
        break;
    case 2:
        exit(1);
        break;
    default:
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
        if (Crplayer.loadFromFile(saveFile))
            std::cout << "Game loaded!\n";
        else
            std::cout << "Failed to load game.\n";
        break;
    default:
        break;
    }
}