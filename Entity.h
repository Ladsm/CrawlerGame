#pragma once
#include <iostream>
#include <string>
#include "MenuExterns.h"
#include "GameExterns.h"
#include "CrawlerPlayer.h"
class Entity {
public:
	std::string name = "Unamed";
	int health = 0;
	int attack = 0;
	int defence = 0;

	Entity() = default;
	Entity(std::string a, int b, int c, int d) {
		name = a;
		health = b;
		attack = c;
		defence = c;
	}
	void checkHealthOfEntity() {
		if (health < 0) {
			fight = false;
			std::cout << "You defeated " << name;
			return;
		}
		return;
	}
	void AttackPlayer();
};
