#pragma once
#include <iostream>
#include "Item.h"
#include "CrawlerPlayer.h"

class Inventory
{
	public:
		int inventory[20];

		int Inv_AddItemToInv(int Id) {
			for (int i = 0; i < 20; i++) {
				if (inventory[i] == 0) {
					inventory[i] = Id;
				}
			}
		}

		int Inv_RemoveItemFromInv(int Id) {
			for (int i = 0; i < 20; i++) {
				if (inventory[i] == Id) {
					inventory[i] = 0;
				}
			}
		}
};