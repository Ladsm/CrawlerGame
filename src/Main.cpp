#include <fstream>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "MenuGame.h"
#include "Inventory.h"
#include "ActionMenu.h"
#include "MenuExterns.h"
#include "GameExterns.h"

#if defined(_WIN32)
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
Inventory LocalInventory;
bool NoStartUp = false;
bool FullstaTs = false;
bool devMode = false;

int main(int argc, char* argv[])
{
#if defined(_WIN32)
        system("cls");
#elif defined(__linux__)
        system("clear");
#endif
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
                if (strcmp(argv[1], "-dev") == 0)
                {
                        NoStartUp = true;
                        devMode = true;
                }
                if (strcmp(argv[1], "-h") == 0)
                {
                    std::cout << "-NoStartUp : goes to main menu without start-up\n-FullStats : gives you 10 points on evrything\n-dev : dev mode\n-h : you're here X\n";
                    std::_Exit(42069);
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
        int defendThree = 0;
        while (Gamerunnin == true) // main main loop
        {
                if (Defend == true)
                {
                    defendThree++;
                    if (defendThree > 3)
                    {
                        Crplayer.revertdefendfromEntity();
                    }
                }
                Crplayer.levelUp();
                Gamemenu_Large_Menu();
                if (fight == true)
                {
                        CurrentEntity.checkHealthOfEntity();
                        CurrentEntity.AttackPlayer();
                }
                if (Crplayer.Health <= 0)
                {
                        PlayerDead();
                }
        }
#if defined(_WIN32)
        system("cls");
#elif defined(__linux__)
        system("clear");
#endif
        return 0;
}