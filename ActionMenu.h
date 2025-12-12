#pragma once
#include <iostream>
#include "MainMenu.h"

extern bool fight;

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
    ActionItem(std::string Name, bool fIght)/*Yes fight ie: starts fight*/ {
        ActionName = Name;
        StartFight = fIght;
        fight = true;
    }
};
class ActionSet {
public:
    ActionItem SetContents[4];
    void SetWrite();
    ActionSet() {
        SetContents[0] = ActionItem();
        SetContents[1] = ActionItem();
        SetContents[2] = ActionItem();
        SetContents[3] = ActionItem();
    }
    ActionSet(ActionItem one, ActionItem two, ActionItem three, ActionItem four) {
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

