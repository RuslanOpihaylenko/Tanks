#include "PlayerAmmo.h"
#include "GameForm.h"
PlayerAmmo::PlayerAmmo()
{
	this->brush = gcnew SolidBrush(Color::Blue);
	this->look = -1;
}

void PlayerAmmo::AmmoPosition()
{
	ammoPosition.X = this->position.X;
	ammoPosition.Y = this->position.Y;
}

void PlayerAmmo::PlayerAmmoRoad()
{
	if (look == -1)
	{
		do {
			ammoPosition.Y -= this->size;
		} while (AmmoPosition!=WallPosition || AmmoPosition != placeEnemy);
		AmmoPosition();
		PlaceWall();
	}
	else if (look == 1)
	{
		do {
			ammoPosition.Y += this->size;
		} while (AmmoPosition != WallPosition || AmmoPosition != placeEnemy);
		AmmoPosition();
		PlaceWall();
	}
	else if (look == -2)
	{
		do {
			ammoPosition.X -= this->size;
		} while (AmmoPosition != WallPosition || AmmoPosition != placeEnemy);
		AmmoPosition();
		PlaceWall();
	}
	else if (look == 2)
	{
		do {
			ammoPosition.X += this->size;
		} while (AmmoPosition != WallPosition || AmmoPosition != placeEnemy);
		AmmoPosition();
		PlaceWall();
	}
}
