#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Item.h"

extern int Story;
class Inventory;
extern Inventory LocalInventory;

class CrawlerPlayer
{
private:
    WeaponItem Stick = WeaponItem("Stick", 31, 3);
    DefenceItem ClothShirt = DefenceItem("Cloth Shirt", 41, 3);
public:
    int Health = 100;
    int Damage = 3;
    int Defence = 3;
    int intelagince = 3;
    int Mobility = 3;
    int points = 5;
    float money = 0;
    std::string Crawler_Name;
    WeaponItem currentWeapon = Stick;
    DefenceItem currentArmor = ClothShirt;

    void attackEntity();
    CrawlerPlayer() = default;
    void displayStats();
    void saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};