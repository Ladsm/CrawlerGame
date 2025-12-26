#pragma once
#include <iostream>
#include <string>
#include "MenuExterns.h"
#include "GameExterns.h"
#include "CrawlerPlayer.h"
class Entity {
public:
	std::string name = "Unamed";
	std::string EncounterString = "A wild bad programer appers!";
	int health = 1;
	int attack = 1;
	int defence = 1;

	Entity() = default;
	Entity(std::string Name, int Health, int Attack, int Defence, std::string Encounter) {
		name = Name;
		health = Health;
		attack = Attack;
		defence = Defence;
		EncounterString = Encounter;
	}
	void checkHealthOfEntity() {
		if (health < 0) {
			fight = false;
			std::cout << "You defeated " << name << '\n';
			Story++;
			return;
		}
		return;
	}
	void Encounter() {
		std::cout << EncounterString << '\n';
	}
	void AttackPlayer();
private:
	int ammountOfDamage() {
		int baseDamage = attack;
		if (attack < 5) {
			baseDamage = attack * 2;
		}
		int defenceDeviders = Crplayer.Defence + Crplayer.currentArmor.DefenceOfItem / 2;
		if (defenceDeviders < 1) {
			int AmmountOfDamage = baseDamage;
			return AmmountOfDamage * 2;
		}
		int AmmountOfDamage = baseDamage / defenceDeviders * 2;
		return AmmountOfDamage;
	}
};
