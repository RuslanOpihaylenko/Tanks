#pragma once
#include"Enemy.h"
#include<time.h>
#include<stdlib.h>
ref class EnemyAmmo:public Enemy
{
private:
	Point EnemyAmmoPosition;
public:
	EnemyAmmo();
	void EAPosition();
	void EnemyAmmoRoad();
};

