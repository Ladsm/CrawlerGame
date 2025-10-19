#include <windows.h>
#include <shlobj.h>
#include <string>
#include <iostream>
#include <fstream>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "MenuGame.h"

using namespace std;

int main(int argc, char* argv[]) {
    bool showSplash = true;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-nosplash") == 0) {
            showSplash = false;
        }
    }
    while (MainMenu == true)
    {
        if (showSplash == true)
        {
            MainMenu_splash();
        }
        else {
            MainMenu_Splash_Alt();
        }
        MainMenu_Menu();
        if (start == true) 
        {
            Gamerunnin = true;
        }
    }
    while (Gamerunnin == true)
    {
        Gamemenu_Large_Menu();
    }
    return 0;
}