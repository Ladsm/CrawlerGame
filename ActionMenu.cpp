#include <iostream>
#include "ActionMenu.h"

void ActionSet::SetWrite() {
    std::cout << SetContents[0].ActionName << '\n';
    std::cout << SetContents[1].ActionName << '\n';
    std::cout << SetContents[2].ActionName << '\n';
    std::cout << SetContents[3].ActionName << '\n';
}

void ActionMenu::ActionWrite(ActionSet WriteOptions) {
    textColor(1);
    std::cout << "/--- Action MENU ---/\n";
    textColor(2);
    WriteOptions.SetWrite();
    std::cout << "5. Back\n";
    std::cout << "Enter the number of your choice\n";
}
