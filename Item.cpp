#include <iostream>
#include <stdbool.h>
#include <string.h>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Item.h"

using namespace std;

HealingItem Healing_Potion;
HealingItem Bread;

void static Initializers() {
	//Healing_Potion
	Healing_Potion.itemId = 1;
	Healing_Potion.itemName = "Healing Potion";
	Healing_Potion.Item_healAmount(20);
	//Bread
	Bread.itemId = 2;
	Bread.itemName = "Bread";
	Bread.Item_healAmount(5);
}