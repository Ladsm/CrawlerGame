#pragma once
#include <iostream>
#include <string>
#include "MenuExterns.h"
#include "GameExterns.h"
#include "CrawlerPlayer.h"

class Entity {
public:
	std::string name = "Unnamed";
	std::string EncounterString = "A wild bad programmer appears!";
	int health = 1;
	int attack = 1;
	int defence = 1;
	int exp = 1;

	Entity() = default;
	Entity(std::string Name, int Health, int Attack, int Defence, int EXP, std::string Encounter) {
		name = Name;
		health = Health;
		attack = Attack;
		defence = Defence;
		exp = EXP;
		EncounterString = Encounter;
	}
	void checkHealthOfEntity() {
		if (health <= 0 && fight) {
			fight = false;
			std::cout << "You defeated " << name << '\n';
			Crplayer.exp += exp;
			exp = 0;
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
	int AmountOfDamage() {
		int baseDamage = attack;
		if (attack < 5) {
			baseDamage = attack * 2;
		}
		int defenceDividers= Crplayer.Defence + Crplayer.currentArmor.DefenceOfItem / 2;
		if (defenceDividers< 1) {
			int AmmountOfDamage = baseDamage;
			return AmmountOfDamage * 2;
		}
		int AmmountOfDamage = baseDamage / defenceDividers* 2;
		return AmmountOfDamage;
	}
};
