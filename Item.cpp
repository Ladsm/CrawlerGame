#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Item.h"
#include "Inventory.h"

extern Inventory LocalInventory;

item FastItemToInv(item Item) {
	LocalInventory.Inv_AddItemToInv(std::make_unique<item>(Item));
	return Item;
}
void init() {
	item testItem("Test item", 1);
	FastItemToInv(testItem);
}