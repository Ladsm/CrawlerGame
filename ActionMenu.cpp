#include <iostream>
#include "ActionMenu.h"

extern bool fight;

ActionSet DefaltSet;
ActionSet FightSet;
ActionMenu actionMenu;
ActionItem ActionFight;

void SetSets() {
    ActionFight = ActionItem("Fight", 0);
    FightSet.SetContents[0] = ActionFight;
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
