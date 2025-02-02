#pragma once
#include"Player.h"
#include<time.h>
#include<stdlib.h>
ref class PlayerAmmo:public Player
{
private:
	Point ammoPosition;
public:
	PlayerAmmo();
	void AmmoPosition();
	void PlayerAmmoRoad();
};

