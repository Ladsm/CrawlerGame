#include <iostream>
#include <string>
#include "MainMenu.h"
#include "CrawlerPlayer.h"
#include "Item.h"
#include "Inventory.h"

using namespace std;

void static init() {
	item itemtest("Test Item", 1);
	/*Inventory::Inv_AddItemToInv(itemtest*); This is how I want to add items to the inventory.
	I might have to rework the whole inventory system 😭😭😭*/
}