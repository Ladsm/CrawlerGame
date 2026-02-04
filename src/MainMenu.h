#pragma once
#if defined(_WIN32)
#include <windows.h>
#endif
#include <string>
#include "CrawlerPlayer.h"
#if defined(_WIN32)
extern HANDLE h;
#endif

extern bool start;
extern bool MainMenu;
extern bool Gamerunnin;
extern bool NoStartUp;
extern bool FullstaTs;

void clear();
void textColor(int color);
void AltEnterfullScreen();
void Menu_Switch_Fail();
void BeepSound();
void MainMenu_splash();
std::string GetDocumentsPath();
bool MainMenu_Menu();
void FullStats();
void checkIfUserIsCheater();