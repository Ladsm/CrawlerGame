#pragma once
#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"

using namespace std;

void Gamemenu_Inventory_Write();
void Gamemenu_Action_Menu();

void Gamemenu_Large_Write() {
    cout << "/--- GAME MENU ---/\n";
    cout << "1. Action\n";
    cout << "2. Stats and inventory\n";
    cout << "3. Save Game\n";
    cout << "4. Load Game\n";
    cout << "5. Quit\n";
    cout << "Enter the number of your choice\n";
}

void Gamemenu_Large_Menu() {
    Gamerunnin = true;
    string saveFile = GetDocumentsPath() + "\\savegame.txt";
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
            if (Crplayer.loadFromFile(saveFile))
                cout << "Game loaded!\n";
            else
                cout << "Failed to load game.\n";
            break;
        case 5:
            Gamerunnin = false;
            break;
        default:
            Menu_Switch_Fail();
            break;
        }
}

void Gamemenu_Action_Write(){
    cout << "/--- Action MENU ---/\n";
    cout << "1. Action\n";
    cout << "2. Stats and inventory\n";
    cout << "3. Save Game\n";
    cout << "4. Load Game\n";
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
    cout << "/--- Inventory ---/\n";
    cout << Crplayer.Inventory << endl;
}