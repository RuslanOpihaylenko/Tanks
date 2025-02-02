#pragma once
#include "Creature.h"

ref class Player : public Creature
{
private:

public:
	Player();
	void playerAction(KeyEventArgs^ e);
};
#pragma endregion