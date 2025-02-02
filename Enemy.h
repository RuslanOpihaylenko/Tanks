#pragma once
#include "Creature.h"
#include <time.h>
#include <stdlib.h>
ref class Enemy : public Creature
{
public:
	Enemy();
	void enemyMove(Point playerPosition);
};
