#include <windows.h>
#include <shlobj.h>
#include <string>
#include <iostream>
#include <fstream>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "MenuGame.h"
#include "Inventory.h"
#include "Item.cpp"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
Inventory LocalInventory;
bool NoStartUp = false;

using namespace std;

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[1], "-NoStartUp") == 0) {
            NoStartUp = true;
        }
    }
    init();
    while (MainMenu == true)
    {
        MainMenu_splash();
        MainMenu_Menu();
        if (start == true) 
        {
            Gamerunnin = true;
        }
    }
    while (Gamerunnin == true)
    {
        Gamemenu_Large_Menu();
        while (1 == 1)
        {
            Sleep(1000);
            if (Crplayer.Health <= 0) {
                PlayerDead();
            }
        }
    }
    return 0;
}