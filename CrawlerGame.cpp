#include <windows.h>
#include <shlobj.h>
#include <string>
#include <iostream>
#include <fstream>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "MenuGame.h"

using namespace std;

extern bool NoSND;
extern bool showSplash;

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[1], "-NoSound") == 0) {
            NoSND = true;
        }
    }
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
        if (Crplayer.Health <= 0) {
            PlayerDead();
        }
    }
    return 0;
}