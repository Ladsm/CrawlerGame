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
    int points = 5;
    float money = 0;
    std::string Crawler_Name;

    void displayStats();
    void saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};