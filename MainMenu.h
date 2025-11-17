#pragma once
#include <windows.h>
#include <string>
#include "CrawlerPlayer.h"

extern HANDLE h;

extern int points;
extern bool start;
extern bool MainMenu;
extern bool Gamerunnin;
extern CrawlerPlayer Crplayer;
extern bool NoStartUp;
extern bool FullstaTs;

void AltEnterfullScreen();
void Menu_Switch_Fail();
void BeepSound();
void MainMenu_splash();
CrawlerPlayer MainMenu_NewGame();
std::string GetDocumentsPath();
bool MainMenu_Menu();
void FullStats();
void checkIfUserIsCheater();