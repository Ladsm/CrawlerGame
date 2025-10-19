#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"

class item{
public:
	string itemName;
	int itemId;
	int itemQuantity;
};

class HealingItem : item {
	int HealAmount;
};

class WeaponItem : item {
	int DamgageOfWeapon;
};

class DefenceItem : item {
	int DefenceOfItem;
};