#pragma once
#include <windows.h>
#include <string>
#include "CrawlerPlayer.h"

extern HANDLE h;

extern bool start;
extern bool MainMenu;
extern bool Gamerunnin;
extern bool NoStartUp;
extern bool FullstaTs;

void textColor(int color);
void AltEnterfullScreen();
void Menu_Switch_Fail();
void BeepSound();
void MainMenu_splash();
std::string GetDocumentsPath();
bool MainMenu_Menu();
void FullStats();
void checkIfUserIsCheater();