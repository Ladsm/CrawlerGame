#include <windows.h>
#include <shlobj.h>
#include <string>
#include <iostream>
#include <fstream>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "MenuGame.h"

using namespace std;

int main() {
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