#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class CrawlerPlayer
{
public:
    string Inventory[20] = { "" };
	int Damage = 5;
	int Defence = 5;
	int intelagince = 5;
	int Mobility = 5;
	string Crawler_Name;

	void displayStats() const {
        cout << "/--- Stats ---/\n";
		cout << "Player Name : " << Crawler_Name << endl;
		cout << "Damage : " << Damage << endl;
		cout << "Defence : " << Defence << endl;
		cout << "Intelligence : " << intelagince << endl;
		cout << "Mobility : " << Mobility << endl;
	}
    void saveToFile(const string& filename) const {
        ofstream out(filename);
        out << Crawler_Name << endl;
        out << Damage << endl;
        out << Defence << endl;
        out << intelagince << endl;
        out << Mobility << endl;
    }

    bool loadFromFile(const string& filename) {
        ifstream in(filename);
        if (!in) return false;
        getline(in, Crawler_Name);
        in >> Damage;
        in >> Defence;
        in >> intelagince;
        in >> Mobility;
        return true;
    }
};