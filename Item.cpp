#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Item.h"
#include "Inventory.h"

extern Inventory LocalInventory;

using namespace std;

void init() {
	item itemtest("Test Item", 1);
	LocalInventory.Inv_AddItemToInv(&itemtest);
	/* This works but shows the
	memery adress not the item name*/
}