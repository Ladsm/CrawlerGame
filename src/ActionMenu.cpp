#include <iostream>
#include "ActionMenu.h"
#include "MenuGame.h"
#include "MainMenu.h"

extern bool fight;

//<=- defalts -=>
ActionMenu actionMenu;
ActionSet DefaltSet;
//<=- FirstSet -=>
ActionSet FirstSet;
ActionItem tester;
ActionItem StartFights;
Entity Slime;

void SetSets() {
    tester = ActionItem("Test", 2, "This worked");
    FirstSet.SetContents[0] = tester;
    Slime = Entity("Slime", 100, 10, 10, "A slime smuthers through");
    StartFights = ActionItem("Start a fight?", Slime);
    FirstSet.SetContents[1] = StartFights;
}

bool ActionItem::ActionDo(ActionItem WhatActionItem) {
    int Type = WhatActionItem.type;
    switch (Type) {
    case undefinded:
        std::cout << "Man how do you screw this up?\n";
        return false;
        break;
    case startfight:
        fight = true;
        WriteWithIf();
        CurrentEntity.Encounter();
        return true;
        break;
    case continuestory:
        Story++;
        WriteWithIf();
        return true;
        break;
    case SaySomeThing:
        WriteWithIf();
        return true;
        break;
    }
    return false;
}

void ActionSet::SetWrite(ActionSet SetToWrite){
    if (!SetToWrite.SetContents[0].type == 0) {
        std::cout << "1. " << SetToWrite.SetContents[0].ActionName << '\n';
    }
    if (!SetToWrite.SetContents[1].type == 0) {
        std::cout << "2. " << SetToWrite.SetContents[1].ActionName << '\n';
    }
    if (!SetToWrite.SetContents[2].type == 0) {
        std::cout << "3. " << SetToWrite.SetContents[2].ActionName << '\n';
    }
    if (!SetToWrite.SetContents[3].type == 0) {
        std::cout << "4. " << SetToWrite.SetContents[3].ActionName << '\n';
    }
}

void ActionMenu::FightActionMenu() {
    textColor(1);
    std::cout << "/--- Fight MENU ---/\n";
    textColor(2);
    std::cout << "1. Attack\n";
    std::cout << "2. Defend\n";
    std::cout << "3. Enemy info\n";
    std::cout << "5. Back\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
    case 1:
        clear();
        Crplayer.attackEntity();
        break;
    case 2:
        clear();
        Crplayer.defendfromEntity();
        break;
    case 3:
        clear();
        Crplayer.EntityInfo();
        break;
    case 5:
        clear();
        Gamemenu_Large_Menu();
        break;
    default:
        clear();
        Gamemenu_Action_Menu();
        Menu_Switch_Fail();
        break;
    }
}

void ActionMenu::ActionWrite(ActionSet WriteOptions) {
    textColor(1);
    std::cout << "/--- Action MENU ---/\n";
    textColor(2);
    if (!fight) {
        WriteOptions.SetWrite(WriteOptions);
    }
    std::cout << "5. Back\n";
    std::cout << "Enter the number of your choice\n";
}

void ActionMenu::ActionMenuMenu(ActionSet SetActionItems) {
    if (!fight) {
        ActionWrite(SetActionItems);
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1:
            clear();
            if (!SetActionItems.SetContents[0].type == 0) {
                SetActionItems.SetContents[0].ActionDo(SetActionItems.SetContents[0]);
            }
            Gamemenu_Action_Menu();
            break;
        case 2:
            clear();
            if (!SetActionItems.SetContents[1].type == 0) {
                SetActionItems.SetContents[1].ActionDo(SetActionItems.SetContents[1]);
            }
            Gamemenu_Action_Menu();
            break;
        case 3:
            clear();
            if (!SetActionItems.SetContents[2].type == 0) {
                SetActionItems.SetContents[2].ActionDo(SetActionItems.SetContents[2]);
            }
            Gamemenu_Action_Menu();
            break;
        case 4:
            clear();
            if (!SetActionItems.SetContents[3].type == 0) {
                SetActionItems.SetContents[3].ActionDo(SetActionItems.SetContents[3]);
            }
            Gamemenu_Action_Menu();
            break;
        case 5:
            clear();
            Gamemenu_Large_Menu();
            break;
        default:
            clear();
            Gamemenu_Action_Menu();
            Menu_Switch_Fail();
            break;
        }
    }
}