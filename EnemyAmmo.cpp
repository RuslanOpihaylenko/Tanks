#include "EnemyAmmo.h"
#include "GameForm.h"

EnemyAmmo::EnemyAmmo()
{
    this->brush = gcnew SolidBrush(Color::Green);
}

void EnemyAmmo::EAPosition()
{
    EnemyAmmoPosition.X = this->position.X;
    EnemyAmmoPosition.Y = this->position.Y;
}

void EnemyAmmo::EnemyAmmoRoad()
{
	if (look == -1)
	{
		do {
			EnemyAmmoPosition.Y -= this->size;
		} while (EAPosition != WallPosition || EAPosition != Playerposition);
		EAPosition();
		PlaceWall();
	}
	else if (look == 1)
	{
		do {
			EnemyAmmoPosition.Y += this->size;
		} while (EAPosition != WallPosition || EAPosition != Playerposition);
		EAPosition();
		PlaceWall();
	}
	else if (look == -2)
	{
		do {
			EnemyAmmoPosition.X -= this->size;
		} while (EAPosition != WallPosition || EAPosition != Playerposition);
		EAPosition();
		PlaceWall();
	}
	else if (look == 2)
	{
		do {
			EnemyAmmoPosition.X += this->size;
		} while (EAPosition != WallPosition || EAPosition != Playerposition);
		EAPosition();
		PlaceWall();
	}
}
