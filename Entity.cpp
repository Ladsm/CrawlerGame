#include "Entity.h"
#include <iostream>
#include "MenuExterns.h"
#include "CrawlerPlayer.h"

void Entity::AttackPlayer() {
	int baseDamage = Crplayer.Health - attack;
	int defenceDeviders = Crplayer.Defence + Crplayer.currentArmor.DefenceOfItem;
	int ammountOfDamage = baseDamage / defenceDeviders;
	Crplayer.Health - ammountOfDamage;
	std::cout << name << " hit you and delt : " << ammountOfDamage << " damage\n";
	return;
}