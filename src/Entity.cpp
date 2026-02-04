#include "Entity.h"
#include <iostream>
#include "MenuExterns.h"
#include "CrawlerPlayer.h"

void Entity::AttackPlayer() {
	int x = ammountOfDamage();
	for (int i = 0; i < x; i++) {
		Crplayer.Health--;
	}
	std::cout << name << " hit you and delt : " << x << " damage\n";
	return;
}