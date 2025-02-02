#include "Enemy.h"
#include <time.h>
#include <stdlib.h>
#include "EnemyAmmo.h"
Enemy::Enemy() {
	this->brush = gcnew SolidBrush(Color::Red);
}

void Enemy::enemyMove(Point playerPosition) {
	if (playerPosition.X > this->position.X) {
		this->position.X += this->size;
		this->look = 2;
		EnemyAmmoRoad();
	}
	else if (playerPosition.X < this->position.X) {
		this->position.X -= this->size;
		this->look = -2;
		EnemyAmmoRoad();
	}
	else if (playerPosition.X == this->position.X) {
		if (playerPosition.Y > this->position.Y) {
			this->position.Y += this->size;
			this->look = 1;
			EnemyAmmoRoad();
		}
		else if (playerPosition.Y < this->position.Y) {
			this->position.Y -= this->size;
			this->look = -1;
			EnemyAmmoRoad();
		}
	}
}
