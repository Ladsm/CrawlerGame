#pragma once
#define NOMINMAX
#define _NO_CVTE_BYTE_
#include <windows.h>
#include <mmsystem.h>
#include "CrawlerPlayer.h"
#include "Item.h"
#include <cmath>
#include <iostream>
#include <shlobj.h>
#include <stdlib.h>
#pragma comment(lib, "Winmm.lib")

/* This is for the SetConsoleTextAttribute function, enjoy.
1: blue
2: green
3: cyan
4: red
5: purple
6: yellow (dark)
7: default white
8: gray/grey
9: bright blue
10: bright green
11: bright cyan
12: bright red
13: pink/magenta
14: yellow
15: bright white*/

using namespace std;

extern int points;
extern bool start;
extern HANDLE h;
extern bool MainMenu;
extern bool Gamerunnin;
extern CrawlerPlayer Crplayer;
extern bool NoStartUp;

void Menu_Switch_Fail();
void BeepSound();

void MainMenu_splash() {
    if (NoStartUp == false) {
        PlaySound(TEXT("Sounds&Mus\\Mainmenu\\LDGW.wav"), NULL, SND_ASYNC);
        cout << "                                                                                                      AAA               " << endl; Sleep(50);
        cout << "      AAAAA             AAAAAA         AAAAAAAAAAAA        AAAAAAAAAA     AAAAAAA         AAAAAAA    AAAA               " << endl; Sleep(50);
        cout << "      AAAAA            AAAAAAAA       AAAAAAAAAAAAAAAA    AAAAAAAA       AAAAAAAA        AAAAAAAA    AAA                " << endl; Sleep(50);
        cout << "      AAAA            AAAA AAAA       AAAA       AAAAA    AAAA           AAAAAAAA       AAAAAAAAA    AAA     AAAAAA     " << endl; Sleep(50);
        cout << "     AAAAA           AAAAA AAAA       AAAA        AAAA    AAAAA          AAAA AAA     AAAAA AAAA           AAAAAAAAA    " << endl; Sleep(50);
        cout << "     AAAA           AAAA   AAAAA      AAAA        AAAAA   AAAAAAAA      AAAA  AAAA    AAAA  AAAA          AAAA          " << endl; Sleep(50);
        cout << "    AAAAA          AAAA    AAAAA      AAAA        AAAA      AAAAAAAA   AAAAA   AAA  AAAAA  AAAA           AAAAAAA       " << endl; Sleep(50);
        cout << "    AAAAA         AAAAAAAAAAAAAA     AAAAA      AAAAA          AAAAA   AAAAA   AAAAAAAAA   AAAA            AAAAAAAA     " << endl; Sleep(50);
        cout << "    AAAAA        AAAAAAAAAAAAAAA     AAAAA     AAAAAA          AAAAA   AAAA    AAAAAAAA   AAAAA                AAAAA    " << endl; Sleep(50);
        cout << "   AAAAAAAAAAAAAAAAAA        AAAAA AAAAAAAAAAAAAAAAAAA    AAAAAAAAAAAAAAAAA    AAAAAAA    AAAA                 AAAAA    " << endl; Sleep(50);
        cout << "   AAAAAAAAAAAAAAAA          AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA      AAAAA     AAAA             AAAAAAA      " << endl; Sleep(50);
        cout << "                                                                                                                        " << endl; Sleep(50);
        cout << "   AAAAAAAAAA     AAAAA     AAAAA     AAAAAA  AAAAAAAAAAAAA    AAA     AAA   AAAAAAAAA    AAAAAAAA   AAA   AAAA  AAAAAAA" << endl; Sleep(50);
        cout << " AAAAA    AAA    AAAAAA    AAA AA     AAAAAA  AAA       AAA   AAAAA   AAAA AAAA    AAAA  AAAA  AAAA  AAAA AAAA  AAA     " << endl; Sleep(50);
        cout << "AAAA            AAA AAA    AAA AAA   AAAAAA   AAA       AAA  AAAAAA  AAA  AAAA     AAAA  AAA   AAAA  AAAAAAA    AAAA    " << endl; Sleep(50);
        cout << "AAAA   AAAAA   AAA  AAA    AAA AAA  AA  AAA  AAAAAAAA   AAA  AAAAAA  AAA  AAA      AAAA  AAAAAAAAA   AAAA         AAAAA " << endl; Sleep(50);
        cout << "AAA     AAA   AAAAAAAAAA  AAA  AAA AAA AAA   AAA        AAAAAAA  AAAAAA   AAA      AAA  AAA  AAAA   AAA AAA         AAAA" << endl; Sleep(50);
        cout << "AAAAA   AAA AAAA     AAA  AAA  AAAAAA  AAA  AAAA        AAAAAA   AAAAA    AAAA   AAAAA  AAA   AAA  AAAA  AAAAA      AAAA" << endl; Sleep(50);
        cout << " AAAAAAAAAAAAAA      AAAAAAA    AAA   AAAAAAAAAAAAAAA   AAAAA   AAAAA      AAAAAAAA     AAA   AAAAAAAAA   AAAAAAAAAAAA  " << endl; Sleep(1500);
        system("cls"); Sleep(500);
        cout << "                                                                Crawler                                                          " << endl;
        cout << "                                                                Game!                                                          " << endl;
        cout << "                                                                |                                                                " << endl;
        cout << "        AAAAAAAAAAAAAAAAAAAAAAA  AAAAAA AAAAAA  AAAAAA  AAAAA   |   AAAAA  AAAAAA  AAAAAA AAAAAAA AAAAAAAAAAAAAAAAAAAAAAA        " << endl;
        cout << "        AAAAAAAAAAAAAAAAAAAAAAA  AAAAAA AAAAAA  AAAAAA  AAAAA   |   AAAAA  AAAAAA  AAAAAA AAAAAAA AAAAAAAAAAAAAAAAAAAAAAA        " << endl;
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
        PlaySound(TEXT("Sounds&Mus\\Mainmenu\\IntroMus.wav"), NULL, SND_FILENAME);
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
        cout << "\n" << CrplayerLocal.Crawler_Name << ", choose a stat to increase:\nWrite 0 to quit.\n";
        SetConsoleTextAttribute(h, 12);
        cout << "1. Damage (" << CrplayerLocal.Damage << ")\n";
        SetConsoleTextAttribute(h, 9);
        cout << "2. Defence (" << CrplayerLocal.Defence << ")\n";
        SetConsoleTextAttribute(h, 11);
        cout << "3. Intelligence (" << CrplayerLocal.intelagince << ")\n";
        SetConsoleTextAttribute(h, 14);
        cout << "4. Mobility (" << CrplayerLocal.Mobility << ")\n";
        SetConsoleTextAttribute(h, 7);
        cout << points << " points left.\n";
        cout << "Enter the number of the stat to increase : ";
        cin >> choice;
        switch (choice) {
        case 0:
            exit(1);
            break;
        case 1:
            BeepSound();
            CrplayerLocal.Damage++;
            break;
        case 2:
            BeepSound();
            CrplayerLocal.Defence++;
            break;
        case 3:
            BeepSound();
            CrplayerLocal.intelagince++;
            break;
        case 4:
            BeepSound();
            CrplayerLocal.Mobility++;
            break;
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
    string saveFile = GetDocumentsPath() + "\\savegame.CrGS";

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
            break;
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
    PlaySound(TEXT("Sounds&Mus\\Mainmenu\\BeepTwo.wav"), NULL, SND_FILENAME | SND_ASYNC);
}