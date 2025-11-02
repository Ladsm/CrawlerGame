#pragma once
#include <iostream>
#include "Item.h"
#include "CrawlerPlayer.h"

class Inventory
{
	public:
		item inventory[20] = { item{"", 0} };

		bool Inv_AddItemToInv(const item& newItem) {
			for (int i = 0; i < 20; i++) {
				if (inventory[i].itemId == 0) {
					inventory[i] = newItem;
					return true;
				}
			}
			return false;
		}

		bool Inv_RemoveItemFromInv(int Id) {
			for (int i = 0; i < 20; i++) {
				if (inventory[i] == Id) {
					inventory[i] = item{"",0};
					return true;
				}
			}
			return false;
		}

		void displayInventory() {
			int four = 0;
			cout << "/--- Inventory ---/\n";
			for (int i = 0; i < 20; i++, four++) {
				const item& currentItem = inventory[i];
				if (currentItem.itemId != 0) {
					cout << currentItem.itemName << ', '; if (four <= 4) {
						cout << '\n';
						four = 0;
					}
				}
			}
		}
};