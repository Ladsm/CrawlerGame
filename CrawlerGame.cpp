#include <windows.h>
#include <shlobj.h>
#include <string>
#include <iostream>
#include <fstream>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "MenuGame.h"
#include "Inventory.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
Inventory LocalInventory;
bool NoStartUp = false;
bool FullstaTs = false;
bool devMode = false;

using namespace std;

int main(int argc, char* argv[]) {
    system("cls");
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[1], "-NoStartUp") == 0) {
            NoStartUp = true;}
        if (strcmp(argv[1], "-FullStats") == 0) {
            FullstaTs = true;}
        if (strcmp(argv[1], "-Dev") == 0) {
            NoStartUp = true;
            devMode = true;
        }
    }
    if (devMode == true) {}
    else {
        AltEnterfullScreen();
    }
    checkIfUserIsCheater();
    init();
    while (MainMenu == true)
    {
        MainMenu_splash();
        MainMenu_Menu();
        if (start == true)
        {
            Gamerunnin = true;
            if (FullstaTs == true) {
                FullStats();
            }
        }
    }
    while (Gamerunnin == true)
    {
        Gamemenu_Large_Menu();
        if (Crplayer.Health <= 0) {
            PlayerDead();
        }
    }
    system("cls");
    return 0;
}