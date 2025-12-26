#include <shlobj.h>
#include <fstream>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "MenuGame.h"
#include "Inventory.h"
#include "ActionMenu.h"
#include "MenuExterns.h"
#include "GameExterns.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
Inventory LocalInventory;
bool NoStartUp = false;
bool FullstaTs = false;
bool devMode = false;

int main(int argc, char* argv[])
{
        system("cls");
        for (int i = 1; i < argc; ++i)
        {
                if (strcmp(argv[1], "-NoStartUp") == 0) 
                {
                        NoStartUp = true;
                }
                if (strcmp(argv[1], "-FullStats") == 0) 
                {
                        FullstaTs = true;
                }
                if (strcmp(argv[1], "-dev") == 0) //Should I add this to readme.txt?
                {
                        NoStartUp = true;
                        devMode = true;
                }
        }
        if(devMode == false)
        {
                AltEnterfullScreen();
        }
        checkIfUserIsCheater();
        SetSets();
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
                if (Defend == true)
                {
                        Crplayer.revertdefendfromEntity();
                }
                CurrentEntity.checkHealthOfEntity();
                Gamemenu_Large_Menu();
                if (fight == true)
                {
                        CurrentEntity.AttackPlayer();
                }
                if (Crplayer.Health <= 0)
                {
                        PlayerDead();
                }
        }
        system("cls");
        return 0;
}