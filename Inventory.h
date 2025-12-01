#pragma once
#include <iostream>
#include <memory>
#include "Item.h"

class Inventory
{
public:
    std::unique_ptr<item> inventory[20]{};

    bool Inv_AddItemToInv(std::unique_ptr<item> newItem) {
        for (int i = 0; i < 20; i++) {
            if (!inventory[i]) {
                inventory[i] = std::move(newItem);
                std::cout << "Added " << inventory[i]->itemName << " to your inventory\n";
                return true;
            }
        }
        std::cout << "Inventory full!\n";
        return false;
    }

    bool Inv_RemoveItemFromInv_User(int itemPlacement) {
        for (int i = 0; i < 20; i++) {
            if (inventory[i] && *(inventory[i]) == itemPlacement) {
                inventory[i].reset();
                return true;
            }
        }
        std::cout << "Not an item in the inventory\n";
        return false;
    }

    bool Inv_RemoveItemFromInv_Forced(int id) {
        for (int i = 0; i < 20; i++) {
            if (inventory[i] && inventory[i]->itemId == id) {
                inventory[i].reset();
                return true;
            }
        }
        std::cout << "Not an item in the inventory\n";
        return false;
    }

    bool Inv_UseItem(int placement) {
        if (placement < 1 || placement > 20) {
            std::cout << "Invalid slot\n";
            return false;
        }
        int idx = placement - 1;
        if (!inventory[idx] || inventory[idx]->itemId == 0) {
            std::cout << "No item in that slot\n";
            return false;
        }
        if (auto heal = dynamic_cast<HealingItem*>(inventory[idx].get())) {
            heal->Item_Use();
            if (inventory[idx] && inventory[idx]->itemId == heal->itemId) {
                inventory[idx].reset();
            }
            return true;
        }
        std::cout << "That item cannot be used\n";
        return false;
    }

    void displayInventory() const {
        int four = 0;
        std::cout << "/--- Inventory ---/\n";
        for (int i = 0; i < 20; i++, four++) {
            if (inventory[i] && inventory[i]->itemId != 0) {
                std::cout << i + 1 << '.' << inventory[i]->itemName << ", ";
                if (four >= 4) {
                    std::cout << '\n';
                    four = 0;
                }
            }
        }
        std::cout << '\n';
    }
    // Add operator[] to allow array-like access to inventory items
    std::unique_ptr<item>& operator[](int index) {
        return inventory[index];
    }

    const std::unique_ptr<item>& operator[](int index) const {
        return inventory[index];
    }
};