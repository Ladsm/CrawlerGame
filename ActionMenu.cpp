#include <iostream>
#include "ActionMenu.h"
#include "MenuGame.h"

extern bool fight;
extern int Story;

ActionSet DefaltSet;
ActionSet FightSet;
ActionMenu actionMenu;
ActionItem ActionFight;

void SetSets() {
    ActionFight = ActionItem("Fight", 0);
    FightSet.SetContents[0] = ActionFight;
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
        return true;
        break;
    case continuestory:
        Story++;
        return true;
        break;
    }
    return false;
}

void ActionSet::SetWrite() const {
    std::cout << "1. " << SetContents[0].ActionName << '\n';
    std::cout << "2. " << SetContents[1].ActionName << '\n';
    std::cout << "3. " << SetContents[2].ActionName << '\n';
    std::cout << "4. " << SetContents[3].ActionName << '\n';
}

void ActionMenu::ActionWrite(ActionSet WriteOptions) {
    textColor(1);
    if (!fight){
    std::cout << "/--- Action MENU ---/\n";}
    else{ std::cout << "/--- Fight MENU ---/\n";}
    textColor(2);
    if (!fight) {
        WriteOptions.SetWrite(); }
    else {
        FightSet.SetWrite(); }
    std::cout << "5. Back\n";
    std::cout << "Enter the number of your choice\n";
}

void ActionMenu::ActionMenuMenu(ActionSet SetActionItems) {
    if (!fight) {
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1:
            SetActionItems.SetContents[0].ActionDo(SetActionItems.SetContents[0]);
            system("cls");
            Gamemenu_Action_Menu();
            break;
        case 2:
            SetActionItems.SetContents[1].ActionDo(SetActionItems.SetContents[1]);
            system("cls");
            Gamemenu_Action_Menu();
            break;
        case 3:
            SetActionItems.SetContents[2].ActionDo(SetActionItems.SetContents[2]);
            system("cls");
            Gamemenu_Action_Menu();
            break;
        case 4:
            SetActionItems.SetContents[3].ActionDo(SetActionItems.SetContents[3]);
            system("cls");
            Gamemenu_Action_Menu();
            break;
        case 5:
            system("cls");
            Gamemenu_Large_Menu();
            break;
        }
    }
    else {
        //Later
        system("cls");
    }
}