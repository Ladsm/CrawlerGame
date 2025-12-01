#pragma once
#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"

void init();

class item{
public:
	std::string itemName;
	int itemId;
	virtual ~item() {}

	bool operator==(int id) const { return itemId == id; }
	item() {
		itemName = "Empty";
		itemId = 0;
	}
	item(std::string name, int id) {
		itemName = name;
		itemId = id;
	}
};

class HealingItem : public item {
public:
	void Item_healAmount(int HealAmount) {
		for (int i = 0; i < HealAmount; i++) {
			if (Crplayer.Health >= 100) {
				std::cout << "Health is max\n";
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
	HealingItem(std::string name, int id, int HealAmount) {
		itemName = name;
		itemId = id;
		Item_healAmount(HealAmount);
	}
};
class WeaponItem : public item {
public:
	int DamageOfWeapon;
	WeaponItem() = default;
	WeaponItem(std::string name, int id, int WeaponDamage) {
		itemName = name;
		itemId = id;
		DamageOfWeapon = WeaponDamage;
	}
};

class DefenceItem : public item {
public:
	int DefenceOfItem;
	DefenceItem() = default;
	DefenceItem(std::string name, int id, int ArmorDefence) {
		itemName = name;
		itemId = id;
		DefenceOfItem = ArmorDefence;
	}
};

item FastItemToInv(item Item);