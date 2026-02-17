#include <memory>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Inventory.h"
#include "Item.h"
#include "GameExterns.h"

extern Inventory LocalInventory;

void CrawlerPlayer::attackEntity() {
    int DaMagetogive = Damage * currentWeapon.DamageOfWeapon;
    for (int i = 0; i < DaMagetogive; i++) {
        CurrentEntity.health--;
    }
    std::cout << "You delt : " << DaMagetogive << " damage to " << CurrentEntity.name << '\n';
    return;
}

void CrawlerPlayer::defendfromEntity() {
    CurrentEntity.attack = CurrentEntity.attack / 2;
    if (CurrentEntity.attack <= 0) {
        CurrentEntity.attack = 2;
    }
    Defend = true;
}

void CrawlerPlayer::revertdefendfromEntity() {
    CurrentEntity.attack = CurrentEntity.attack * 2;
    Defend = false;
}

void CrawlerPlayer::EntityInfo() {
    std::cout << "Name of enemy: " << CurrentEntity.name << '\n';
    std::cout << "Health: " << CurrentEntity.health << '\n';
    if (intelligence > 5) {
        std::cout << "Amount of base attack: " << CurrentEntity.attack << '\n';
        std::cout << "Amount of defence: " << CurrentEntity.defence << '\n';
    }
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
    std::cout << "Intelligence : " << intelligence << '\n';
    std::cout << "Mobility : " << Mobility << '\n';
    std::cout << "Current Weapon : " << currentWeapon.itemName << '\n';
    std::cout << "Current Armor : " << currentArmor.itemName << '\n';
    std::cout << "Cash : " << money << '\n';
    std::cout << "Level and EXP : " << level << ", " << exp << '\n';
}

void CrawlerPlayer::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    out << Crawler_Name << std::endl;
    out << Health << std::endl;
    out << Damage << std::endl;
    out << Defence << std::endl;
    out << intelligence << std::endl;
    out << Mobility << std::endl;
    out << points << std::endl;
    out << Story << std::endl;
    out << money << std::endl;
    out << exp << std::endl;
    out << level << std::endl;
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
    in >> intelligence;
    in >> Mobility;
    in >> points;
    in >> Story;
    in >> money;
    in >> exp;
    in >> level;
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
void CrawlerPlayer::levelUp() {
    static const int thresholds[] = { 100, 300, 750, 1500, 2500 };
    bool leveled = false;
    while ((level - 1) < static_cast<int>(std::size(thresholds)) &&
        exp >= thresholds[level - 1]) {
        level++;
        points++;
        leveled = true;
    }
    canUpgrade = leveled;
}