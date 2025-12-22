#pragma once
#define NOMINMAX
#define _NO_CVTE_BYTE_
#include <windows.h>
#include <mmsystem.h>
#include "CrawlerPlayer.h"
#include "Item.h"
#include <shlobj.h>
#include <stdlib.h>
#include "LDGWLogo.h"
#include "MenuExterns.h"
#pragma comment(lib, "Winmm.lib")

extern int Story;
extern bool start;
extern HANDLE h;
extern bool MainMenu;
extern bool Gamerunnin;
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

void textColor(int color) {
    switch (color) {
    case 1:
        SetConsoleTextAttribute(h, 4);
        break;
    case 2:
        SetConsoleTextAttribute(h, 7);
        break;
    default:
        std::cout << "This programer is dumb\n";
        break;
    }
}

void MainMenu_splash() {
    if (NoStartUp == false) {
        PlaySound(TEXT("Sounds&Mus\\Mainmenu\\LDGW.wav"), NULL, SND_ASYNC);
        LogoSplash();
        system("cls"); Sleep(1000);
        std::cout << "                                                                Crawler                                                          \n";
        std::cout << "                                                                Game!                                                            \n";
        std::cout << "                                                                |                                                                \n";
        std::cout << "        AAAAAAAAAAAAAAAAAAAAAAA  AAAAAA AAAAAA  AAAAAA  AAAAA   |   AAAAA  AAAAAA  AAAAAA AAAAAAA AAAAAAAAAAAAAAAAAAAAAAA        \n";
        std::cout << "        AAAAAAAAAAAAAAAAAAAAAAA  AAAAAA AAAAAA  AAAAAA  AAAAA   |   AAAAA  AAAAAA  AAAAAA AAAAAAA AAAAAAAAAAAAAAAAAAAAAAA        \n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA                           AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
        PlaySound(TEXT("Sounds&Mus\\Mainmenu\\Menu_Start.wav"), NULL, SND_FILENAME);
        PlaySound(TEXT("Sounds&Mus\\Mainmenu\\Menu_End.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
    SetConsoleTextAttribute(h, 14);
    std::cout << "1. New game\n";
    std::cout << "2. Load game\n";
    std::cout << "3. Quit\n";
    SetConsoleTextAttribute(h, 7);
}

static CrawlerPlayer MainMenu_NewGame() {
    system("cls");
    CrawlerPlayer CrplayerLocal;
    if (FullstaTs == false) {
        CrplayerLocal.points = 5;
        int choice;
        std::cout << "What is your character's name?\n";
        std::getline(std::cin >> std::ws, CrplayerLocal.Crawler_Name);
        system("cls");
        BeepSound();
        while (CrplayerLocal.points > 0) {
            std::cout << CrplayerLocal.Crawler_Name << ", choose a stat to increase:\nWrite 0 to quit.\n";
            SetConsoleTextAttribute(h, 12);
            std::cout << "1. Damage (" << CrplayerLocal.Damage << ")\n";
            SetConsoleTextAttribute(h, 9);
            std::cout << "2. Defence (" << CrplayerLocal.Defence << ")\n";
            SetConsoleTextAttribute(h, 11);
            std::cout << "3. Intelligence (" << CrplayerLocal.intelagince << ")\n";
            SetConsoleTextAttribute(h, 14);
            std::cout << "4. Mobility (" << CrplayerLocal.Mobility << ")\n";
            SetConsoleTextAttribute(h, 7);
            std::cout << CrplayerLocal.points << " points left.\n";
            std::cout << "Enter the number of the stat to increase : ";
            std::cin >> choice;
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
            system("cls");
            CrplayerLocal.points--;
        }
        std::cin.ignore();
        Story = 1;
        system("cls");
        return CrplayerLocal;
    }
    else {
        system("cls");
        return CrplayerLocal;
    }
}

std::string GetDocumentsPath() {
    char path[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
    return std::string(path);
}

void FullStats();
void checkIfUserIsCheater();

bool MainMenu_Menu() {
Loadfail:
    int Choice;
    std::cin >> Choice;
    std::string saveFile = GetDocumentsPath() + "\\savegame.CrGS";

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
        system("cls");
        break;
    case 2:
        BeepSound();
        if (Crplayer.loadFromFile(saveFile)) {
            std::cout << "Game loaded!\n";
            MainMenu = false;
            start = true;
            system("cls");
            break;
        }
        else {
            system("cls");
            std::cout << "Failed to load game.\n";
            goto Loadfail;
        }
        break;
    case 3:
        system("cls");
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
    std::cout << "Invalid option, try again\n";
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