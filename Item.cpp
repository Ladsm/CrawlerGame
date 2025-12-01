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

void init() {
	//auto healtest = std::make_unique<HealingItem>("Heal test", 2, 20);
	//FastItemToInv(std::move(healtest));
}