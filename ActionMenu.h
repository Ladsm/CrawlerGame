#pragma once
#include "MainMenu.h"
#include "MenuGame.h"
#include "Entity.h"
#include "GameExterns.h"

extern bool fight;

void SetSets();
class ActionItem {
private:
    enum {
        undefinded,
        startfight,
        continuestory,
        SaySomeThing
    };
    void writeFromText() const {
        std::cout << TextToWrite << '\n';
    }
public:
    std::string ActionName;
    int type;
    std::string TextToWrite = ".";
    void WriteWithIf() {
        if (TextToWrite == ".") {
            return;
        }
        else {
            writeFromText();
        }
    }
    bool ActionDo(ActionItem WhatActionItem);
    ActionItem() {
        ActionName = "#Fail";
        type = undefinded;
    }
    ActionItem(std::string Name, int Type) {
        ActionName = Name;
        type = Type;
    }
    ActionItem(std::string Name, Entity WhatEntity) {
        ActionName = Name;
        type = startfight;
        CurrentEntity = WhatEntity;
    }
    ActionItem(std::string Name, int Type, std::string Text) {
        ActionName = Name;
        type = Type;
        TextToWrite = Text;
    }
    ActionItem(std::string Name, Entity WhatEntity, std::string Text) {
        ActionName = Name;
        type = startfight;
        CurrentEntity = WhatEntity;
        TextToWrite = Text;
    }
};
class ActionSet {
public:
    ActionItem SetContents[4];
    void SetWrite(ActionSet SetToWrite);
    ActionSet() {
        SetContents[0] = ActionItem();
        SetContents[1] = ActionItem();
        SetContents[2] = ActionItem();
        SetContents[3] = ActionItem();
    }
    ActionSet(ActionItem one) {
        SetContents[0] = one;
    }
    ActionSet(ActionItem one, ActionItem two) {
        SetContents[0] = one;
        SetContents[1] = two;
    }
    ActionSet(ActionItem one, ActionItem two, ActionItem three) {
        SetContents[0] = one;
        SetContents[1] = two;
        SetContents[2] = three;
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
    void FightActionMenu();
    void ActionWrite(ActionSet WriteOptions);
    void ActionMenuMenu(ActionSet SetActionItems);
};
