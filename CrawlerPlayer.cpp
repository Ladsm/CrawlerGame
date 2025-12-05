#include <memory>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Inventory.h"
#include "Item.h"

extern Inventory LocalInventory;

void CrawlerPlayer::displayStats() {
    textColor(1);
    std::cout << "/--- Stats ---/\n";
    textColor(2);
    std::cout << "Player Name : " << Crawler_Name << std::endl;
    std::cout << "Health : " << Health << std::endl;
    std::cout << "Damage : " << Damage << std::endl;
    std::cout << "Defence : " << Defence << std::endl;
    std::cout << "Intelligence : " << intelagince << std::endl;
    std::cout << "Mobility : " << Mobility << std::endl;
}

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
    out << money << std::endl;
    for (int i = 0; i < 20; i++) {
        if (LocalInventory[i]) {
            out << LocalInventory[i]->type << std::endl;
            out << LocalInventory[i]->itemId << std::endl;
            out << LocalInventory[i]->itemName << std::endl;
            if (LocalInventory[i]->type == 2) {
                auto h = static_cast<HealingItem*>(LocalInventory[i].get());
                out << h->HealAmount << std::endl;
            }
        } else {
            out << 0 << std::endl;
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
    in >> money;
    in.ignore((std::streamsize)2147483647, '\n');
    for (int i = 0; i < 20; i++) {
        int type = 0;
        if (!(in >> type)) {
            for (; i < 20; ++i) LocalInventory[i].reset();
            return false;
        }

        int itemId = 0;
        in >> itemId;
        in.ignore();
        std::string itemName;
        std::getline(in, itemName);

        if (type == 0) {
            LocalInventory[i].reset();
        } else if (type == 1) {
            LocalInventory[i] = std::make_unique<item>(itemName, itemId);
            LocalInventory[i]->type = 1;
        } else if (type == 2) {
            int healAmount = 0;
            if (!(in >> healAmount)) {
                LocalInventory[i].reset();
                in.clear();
                in.ignore((std::streamsize)2147483647, '\n');
            } else {
                in.ignore();
                LocalInventory[i] = std::make_unique<HealingItem>(itemName, itemId, healAmount);
                LocalInventory[i]->type = 2;
            }
        } else if (type == 3) {
            LocalInventory[i] = std::make_unique<item>(itemName, itemId);
            LocalInventory[i]->type = 3;
        } else if (type == 4) {
            LocalInventory[i] = std::make_unique<item>(itemName, itemId);
            LocalInventory[i]->type = 4;
        } else {
            LocalInventory[i].reset();
        }
    }
    return true;
}