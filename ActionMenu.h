#pragma once
#include <iostream>
#include "MainMenu.h"

class ActionItem {
public:
    std::string ActionName;
    bool StartFight;
    ActionItem() {
        ActionName = "#Fail";
        StartFight = false;
    }
    ActionItem(std::string Name)/*No fight*/ {
        ActionName = Name;
        StartFight = false;
    }
    ActionItem(std::string Name, bool fight)/*Yes fight*/ {
        ActionName = Name;
        StartFight = fight;
    }
};
class ActionSet {
public:
    std::string SetName;
    ActionItem SetContents[4];
    void SetWrite();
    ActionSet(std::string name, ActionItem one, ActionItem two, ActionItem three, ActionItem four) {
        SetName = name;
        SetContents[0] = one;
        SetContents[1] = two;
        SetContents[2] = three;
        SetContents[3] = four;
    }
};
class ActionMenu {
public:
    void ActionWrite(ActionSet WriteOptions);
};

