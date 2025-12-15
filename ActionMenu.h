#pragma once
#include <iostream>
#include "MainMenu.h"

extern bool fight;

void SetSets();
class ActionItem {
public:
    std::string ActionName;
    int type;
    ActionItem() {
        ActionName = "#Fail";
        type = 0;
    }
    ActionItem(std::string Name, int Type) {
        ActionName = Name;
        type = Type;
        switch (Type) {
        case 0:
            break;
        case 1:
            fight = true;
            break;
        }
    }
};
class ActionSet {
public:
    ActionItem SetContents[4];
    void SetWrite() const;
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

