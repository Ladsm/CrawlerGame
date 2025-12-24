#include <memory>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Inventory.h"
#include "Item.h"
#include "GameExterns.h"

extern Inventory LocalInventory;

void CrawlerPlayer::attackEntity() {
    int DaMagetogive = Damage * currentWeapon.DamageOfWeapon;
    CurrentEntity.health - DaMagetogive;
    std::cout << "You delt : " << DaMagetogive << "Damage to " << CurrentEntity.name << '\n';
    return;
}

void CrawlerPlayer::displayStats() {
    textColor(1);
    std::cout << "/--- Stats ---/\n";
    textColor(2);
    std::cout << "Player Name : " << Crawler_Name << '\n';
    std::cout << "Health : " << Health << '\n';
    std::cout << "Damage : " << Damage << '\n';
    std::cout << "Defence : " << Defence << '\n';
    std::cout << "Intelligence : " << intelagince << '\n';
    std::cout << "Mobility : " << Mobility << '\n';
    std::cout << "Current Weapon : " << currentWeapon.itemName << '\n';
    std::cout << "Current Armor : " << currentArmor.itemName << '\n';
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
            out << LocalInventory[i]->itemId << std::endl;
            out << LocalInventory[i]->itemName << std::endl;
            out << LocalInventory[i]->type << std::endl;
            if (LocalInventory[i]->type == 2) {
                auto temp = static_cast<HealingItem*>(LocalInventory[i].get());
                out << temp->HealAmount << std::endl;
            }
            if (LocalInventory[i]->type == 3) {
                auto temp = static_cast<WeaponItem*>(LocalInventory[i].get());
                out << temp->DamageOfWeapon << std::endl;
            }
            if (LocalInventory[i]->type == 4) {
                auto temp = static_cast<DefenceItem*>(LocalInventory[i].get());
                out << temp->DefenceOfItem << std::endl;
            }
        }
        else {
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
    for (int i = 0; i < 20; i++) {
        if (LocalInventory[i]) {
            in >> LocalInventory[i]->itemId;
            in >> LocalInventory[i]->itemName;
            in >> LocalInventory[i]->type;
            if (LocalInventory[i]->type == 2) {
                auto temp = static_cast<HealingItem*>(LocalInventory[i].get());
                in >> temp->HealAmount;
            }
            if (LocalInventory[i]->type == 3) {
                auto temp = static_cast<WeaponItem*>(LocalInventory[i].get());
                in >> temp->DamageOfWeapon;
            }
            if (LocalInventory[i]->type == 4) {
                auto temp = static_cast<DefenceItem*>(LocalInventory[i].get());
                in >> temp->DefenceOfItem;
            }
        }
    }
    return true;
}