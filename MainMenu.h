#pragma once
#define NOMINMAX
#define _NO_CVTE_BYTE_ // Dont know why but it needs this for windows.h to work
#include <windows.h>
#include <mmsystem.h>
#include "CrawlerPlayer.h"
#include <cmath>
#include <iostream>
#include <shlobj.h>
#pragma comment(lib, "Winmm.lib")
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

extern int points;
extern bool start;
extern bool MainMenu;
extern bool NoSND;
extern bool Gamerunnin;
extern CrawlerPlayer Crplayer;

void Menu_Switch_Fail();
void BeepSound();

void MainMenu_splash() {
        cout << "                                                            Crawler Game!                                                        " << endl;
        cout << "                                                                                                                                 " << endl;
        cout << "                                                                AAAAAA                                                           " << endl;
        cout << "                                                                AAAAAA                                                           " << endl;
        cout << "                                                                A                                                                " << endl;
        cout << "        AAAAAAAAAAAAAAAAAAAAAAA  AAAAAA AAAAAA  AAAAAA  AAAAA   A   AAAAA  AAAAAA  AAAAAA AAAAAAA AAAAAAAAAAAAAAAAAAAAAAA        " << endl;
        cout << "        AAAAAAAAAAAAAAAAAAAAAAA  AAAAAA AAAAAA  AAAAAA  AAAAA   A   AAAAA  AAAAAA  AAAAAA AAAAAAA AAAAAAAAAAAAAAAAAAAAAAA        " << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
    if (NoSND == false) {
        PlaySound(TEXT("Sounds&Mus\\IntroMus.wav"), NULL, SND_FILENAME);
    }
    SetConsoleTextAttribute(h, 14);
    cout << "1. New game\n";
    cout << "2. Load game\n";
    cout << "3. Quit\n";
    SetConsoleTextAttribute(h, 7);
}

CrawlerPlayer MainMenu_NewGame() {
    CrawlerPlayer CrplayerLocal;
    points = 5;
    int choice;
    cout << "What is your character's name?\n";
    getline(cin >> ws, CrplayerLocal.Crawler_Name);
    BeepSound();
    while (points > 0) {
        cout << "\n" << CrplayerLocal.Crawler_Name << ", choose a stat to increase:\n";
        cout << "1. Damage (" << CrplayerLocal.Damage << ")\n";
        cout << "2. Defence (" << CrplayerLocal.Defence << ")\n";
        cout << "3. Intelligence (" << CrplayerLocal.intelagince << ")\n";
        cout << "4. Mobility (" << CrplayerLocal.Mobility << ")\n";
        cout << points << " points left.\n";
        cout << "Enter the number of the stat to increase : ";
        cin >> choice;
        switch (choice) {
            case 1:
                BeepSound();
                CrplayerLocal.Damage++; break;
            case 2:
                BeepSound();
                CrplayerLocal.Defence++; break;
            case 3:
                BeepSound();
                CrplayerLocal.intelagince++; break;
            case 4:
                BeepSound();
                CrplayerLocal.Mobility++; break;
            default:
                Menu_Switch_Fail();
                continue;
        }
        points--;
    }
    cin.ignore();
    return CrplayerLocal;
}

string GetDocumentsPath() {
    char path[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
    return string(path);
}

bool MainMenu_Menu() {
Loadfail:
    int Choice;
    cin >> Choice;
    string saveFile = GetDocumentsPath() + "\\savegame.txt";

    switch (Choice)
    {
    case 1:
        BeepSound();
        Crplayer = MainMenu_NewGame();
        MainMenu = false;
        start = true;
        Crplayer.saveToFile(saveFile);
        break;
    case 2:
        BeepSound();
        if (Crplayer.loadFromFile(saveFile)) {
            cout << "Game loaded!\n";
            MainMenu = false;
            start = true;
        }
        else {
            cout << "Failed to load game.\n";
            goto Loadfail;
        }
        break;
    case 3:
        exit(1);
        return 0;
    default:
        Menu_Switch_Fail();
        goto Loadfail;
        break;
    }
    return 0;
}

void Menu_Switch_Fail() {
    cout << "Invalid option, try again\n";
}

void BeepSound() {
    if (NoSND == false)
    {
        PlaySound(TEXT("Sounds&Mus\\BeepTwo.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    else
    {

    }
}