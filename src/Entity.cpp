#include "Entity.h"
#include "MenuExterns.h"

void Entity::AttackPlayer() {
	int x = AmountOfDamage();
	for (int i = 0; i < x; i++) {
		Crplayer.Health--;
	}
	std::cout << name << " hit you and delt : " << x << " damage\n";
	return;
}