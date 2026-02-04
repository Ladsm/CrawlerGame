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
	int type = 1;
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
	HealingItem(std::string name, int id, int healAmount)
		: item(name, id), HealAmount(healAmount) {
		type = 2;
	}
	void Item_Heal(int HealAmount);
	void Item_Use();
};
class WeaponItem : public item {
public:
	int DamageOfWeapon = 0;
	WeaponItem() = default;
	WeaponItem(std::string name, int id, int WeaponDamage)
		: item(name, id), DamageOfWeapon(WeaponDamage)
	{
		type = 3;
	}
};

class DefenceItem : public item {
public:
	int DefenceOfItem = 0;
	DefenceItem() = default;
	DefenceItem(std::string name, int id, int ArmorDefence)
		: item(name, id), DefenceOfItem(ArmorDefence)
	{
		type = 4;
	}
};

void ItemUseWeapon(WeaponItem weapon);
void ItemUseArmor(DefenceItem Armor);
bool FastItemToInv(std::unique_ptr<item> newItem);