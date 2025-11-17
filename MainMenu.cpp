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
#include "LDGWLogo.h"
#pragma comment(lib, "Winmm.lib")

using namespace std;

extern int points;
extern int Story;
extern bool start;
extern HANDLE h;
extern bool MainMenu;
extern bool Gamerunnin;
extern CrawlerPlayer Crplayer;
extern bool NoStartUp;
extern bool FullstaTs;
extern bool devMode;

void Menu_Switch_Fail();
void BeepSound();

void AltEnterfullScreen(){
    keybd_event(VK_MENU, 0, 0, 0);//Alt Down
    keybd_event(VK_RETURN, 0, 0, 0);//Enter Down
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Enter Up
    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);//Alt up
}

void MainMenu_splash() {
    if (NoStartUp == false) {
        PlaySound(TEXT("Sounds&Mus\\Mainmenu\\LDGW.wav"), NULL, SND_ASYNC);
        LogoSplash();
        system("cls"); Sleep(1000);
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
    if (FullstaTs == false) {
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
        Story = 0;
        return CrplayerLocal;
    }
    else {
        return CrplayerLocal;
    }
}

string GetDocumentsPath() {
    char path[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
    return string(path);
}

void FullStats();
void checkIfUserIsCheater();

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
        if (FullstaTs == true) {
            FullStats();
        }
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

void FullStats() {
    Crplayer.Crawler_Name = "CHEATER!";
    Crplayer.Damage = 10;
    Crplayer.Defence = 10;
    Crplayer.intelagince = 10;
    Crplayer.Mobility = 10;
}

void checkIfUserIsCheater() {
    if (Crplayer.Crawler_Name == "CHEATER!") {
        FullstaTs = true;
    }
}