#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "MainMenu.h"
#include "CrawlerPlayer.h"

class Inventory;
extern Inventory LocalInventory;

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
	int HealAmount = 0;
	HealingItem() = default;
	HealingItem(std::string name, int id, int healAmount) {
		itemName = name;
		itemId = id;
		HealAmount = healAmount;
	}
	void Item_Heal(int HealAmount);
	void Item_Use();
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

bool FastItemToInv(std::unique_ptr<item> newItem);