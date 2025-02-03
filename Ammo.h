#pragma once
#include"Creature.h"
ref class Ammo:public Creature
{
private:

public:
	void ListOfPlayers();
	void ListOfEnemies();
	void ListOfWalls();
	void PlayerShoot(KeyEventArgs^ e);
	void EnemyShoot();
};

