//I dont remember how this works... I will rework this later.
#pragma once
#include <iostream>
#include "Item.h"
#include "CrawlerPlayer.h"

class Inventory
{
	public:
		item* inventory[20] = { nullptr };

		bool Inv_AddItemToInv(item* newItem) {
			for (int i = 0; i < 20; i++) {
				if (inventory[i] == nullptr) {
					inventory[i] = newItem;
					return true;
				}
			}
			return false;
		}

		bool Inv_RemoveItemFromInv(int Id) {
			for (int i = 0; i < 20; i++) {
				if (inventory[i] != nullptr && inventory[i]->itemId == Id) {
					delete inventory[i];
					inventory[i] = nullptr;
					return true;
				}
			}
			return false;
		}

		void displayInventory() const {
			int four = 0;
			cout << "/--- Inventory ---/\n";
			for (int i = 0; i < 20; i++, four++) {
				if (inventory[i] != nullptr && inventory[i]->itemId !=0) {
					cout << inventory[i]->itemName << ', '; 
					if (four >= 4) {
						cout << '\n';
						four = 0;
					}
				}
			}
		}
};