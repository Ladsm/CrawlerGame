#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

extern int Story;
class Inventory;
extern Inventory LocalInventory;

class CrawlerPlayer
{
public:
    int Health = 100;
    int Damage = 5;
    int Defence = 5;
    int intelagince = 5;
    int Mobility = 5;
    std::string Crawler_Name;

    void displayStats() const {
        std::cout << "/--- Stats ---/\n";
        std::cout << "Player Name : " << Crawler_Name << std::endl;
        std::cout << "Health : " << Health << std::endl;
        std::cout << "Damage : " << Damage << std::endl;
        std::cout << "Defence : " << Defence << std::endl;
        std::cout << "Intelligence : " << intelagince << std::endl;
        std::cout << "Mobility : " << Mobility << std::endl;
    }
    void saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};