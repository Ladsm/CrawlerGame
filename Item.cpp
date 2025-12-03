#include <iostream>
#include <string>
#include <memory>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Item.h"
#include "Inventory.h"

extern Inventory LocalInventory;

void HealingItem::Item_Heal(int HealAmount) {
	if (HealAmount <= 0) {
		return;
	}
	for (int i = 0; i < HealAmount; i++) {
		if (Crplayer.Health >= 100) {
			std::cout << "Health is max\n";
			return;
		}
		else {
			Crplayer.Health++;
		}
	}
	LocalInventory.Inv_RemoveItemFromInv_Forced(itemId);
	return;
}
void HealingItem::Item_Use() {
	Item_Heal(HealAmount);
}

bool FastItemToInv(std::unique_ptr<item> newItem) {
	return LocalInventory.Inv_AddItemToInv(std::move(newItem));
}

/*
For b7347812-maker https://youtu.be/IajElu8yIEg
item types : item, HealingItem, WeaponItem(wip), DefenceItem(wip).
The way Items are created :
auto codeItemName = std::make_unique<item>("itemname", number id); For regular items
auto codeItemName = std::make_unique<HealingItem>("itemname", number id, heal amount); For Healing items
auto codeItemName = std::make_unique<WeaponItem>("itemname", number id, weapon damage); For Weapon items
auto codeItemName = std::make_unique<DefenceItem>("itemname", number id, defence amount); For Defence items
The way to add items to the inventory:
FastItemToInv(std::move(codeItemName));
*/

void init() {
	auto healtest = std::make_unique<HealingItem>("Heal test", 2, 20);
	//FastItemToInv(std::move(healtest));
}