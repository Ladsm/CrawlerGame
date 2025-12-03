#include <memory>
#include "CrawlerPlayer.h"
#include "Inventory.h"
#include "Item.h"

extern Inventory LocalInventory;

void CrawlerPlayer::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    out << Crawler_Name << std::endl;
    out << Health << std::endl;
    out << Damage << std::endl;
    out << Defence << std::endl;
    out << intelagince << std::endl;
    out << Mobility << std::endl;
    out << points << std::endl;
    out << Story << std::endl;
    for (int i = 0; i < 20; i++) {
        if (LocalInventory[i]) {
            out << LocalInventory[i]->itemId << std::endl;
            out << LocalInventory[i]->itemName << std::endl;
        } else {
            out << 0 << std::endl;
            out << "" << std::endl;
        }
    }
}

bool CrawlerPlayer::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return false;
    getline(in, Crawler_Name);
    in >> Health;
    in >> Damage;
    in >> Defence;
    in >> intelagince;
    in >> Mobility;
    in >> points;
    in >> Story;
    for (int i = 0; i < 20; i++) {
        int itemId;
        std::string itemName;
        in >> itemId;
        in.ignore();
        std::getline(in, itemName);

        if (itemId != 0) {
            LocalInventory[i] = std::make_unique<item>(itemName, itemId);
        } else {
            LocalInventory[i].reset();
        }
    }
    return true;
}