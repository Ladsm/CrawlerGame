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
public:
	int HealAmount;
};

class WeaponItem : item {
public:
	int DamgageOfWeapon;
};

class DefenceItem : item {
public:
	int DefenceOfItem;
};