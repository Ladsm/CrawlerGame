#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"

void Initializers();

class item{
public:
	string itemName;
	int itemId;
	virtual ~item() {}

	bool operator==(int id) const { return itemId == id; }
};

class HealingItem : public item {
public:
	void Item_healAmount(int HealAmount) {
		for (int i = 0; i < HealAmount; i++) {
			if (Crplayer.Health >= 100) {
				cout << "Health is max\n";
				return;
			}
			else {
				Crplayer.Health++;
			}
		}
		return;
	}
};

class WeaponItem : public item {
public:
	int DamageOfWeapon;
};

class DefenceItem : public item {
public:
	int DefenceOfItem;
};