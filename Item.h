#pragma once
#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"

class item{
public:
	string itemName;
	int itemId;
	virtual ~item() {}

	bool operator==(int id) const { return itemId == id; }
	item() {
		itemName = "Empty";
		itemId = 0;
	}
	item(string name, int id) {
		itemName = name;
		itemId = id;
	}
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
	HealingItem() {
		Item_healAmount(0);
	}
	HealingItem(string name, int id, int HealAmount) {
		itemName = name;
		itemId = id;
		Item_healAmount(HealAmount);
	}
};
class WeaponItem : public item {
public:
	int DamageOfWeapon;
	WeaponItem() = default;
	WeaponItem(string name, int id, int WeaponDamage) {
		itemName = name;
		itemId = id;
		DamageOfWeapon = WeaponDamage;
	}
};

class DefenceItem : public item {
public:
	int DefenceOfItem;
	DefenceItem() = default;
	DefenceItem(string name, int id, int ArmorDefence) {
		itemName = name;
		itemId = id;
		DefenceOfItem = ArmorDefence;
	}
};