#pragma once
#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Inventory.h"

using namespace std;

extern Inventory LocalInventory;

void Gamemenu_Inventory_Write();
void Gamemenu_Action_Menu();
void Menu_Loadgame();

void Gamemenu_Large_Write() {
    SetConsoleTextAttribute(h, 4);
    cout << "/--- GAME MENU ---/\n";
    SetConsoleTextAttribute(h, 7);
    cout << "1. Action\n";
    cout << "2. Stats and inventory\n";
    cout << "3. Save Game\n";
    cout << "4. Load Game\n";
    cout << "5. Quit\n";
    cout << "Enter the number of your choice\n";
}

void Gamemenu_Large_Menu() {
    Gamerunnin = true;
    string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
    Gamemenu_Large_Write();
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
        Gamemenu_Action_Menu();
        break;
    case 2:
        Gamemenu_Inventory_Write();
        break;
    case 3:
        Crplayer.saveToFile(saveFile);
        cout << "Game saved!\n";
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
    cout << "/--- Action MENU ---/\n";
    SetConsoleTextAttribute(h, 7);
    cout << "1. #NOT DONE\n";
    cout << "2. #NOT DONE\n";
    cout << "3. #NOT DONE\n";
    cout << "4. #NOT DONE\n";
    cout << "5. Back\n";
    cout << "Enter the number of your choice\n";
}

void Gamemenu_Action_Menu() {
    Gamemenu_Action_Write();
    int choice;
    cin >> choice;
    cin.ignore();
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
}

void PlayerDead() {
    int choice;
    string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
    cout << "/--- YOU DEAD ---/\n";
    cout << "1. Continue from last save\n";
    cout << "2. Quit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        if (Crplayer.loadFromFile(saveFile))
            cout << "Game loaded!\n";
        else
            cout << "Failed to load game.\n";
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
    string saveFile = GetDocumentsPath() + "\\savegame.CrGS";
    cout << "Are you sure?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> choice;
    switch (choice) {
    case 1:
        if (Crplayer.loadFromFile(saveFile))
            cout << "Game loaded!\n";
        else
            cout << "Failed to load game.\n";
        break;
    default:
        break;
    }
}