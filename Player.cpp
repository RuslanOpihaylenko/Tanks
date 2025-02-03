#include "Player.h"

Player::Player() {
	this->brush = gcnew SolidBrush(Color::Orange);
	this->look = -1;
}

void Player::playerAction(KeyEventArgs^ e) {
	switch (e->KeyCode)
	{
	case Keys::W:
		this->position.Y -= this->size;
		this->look = -1;
		break;
	case Keys::S:
		this->position.Y += this->size;
		this->look = 1;
		break;
	case Keys::A:
		this->position.X -= this->size;
		this->look = -2;
		break;
	case Keys::D:
		this->position.X += this->size;
		this->look = 2;
		break;
	default:
		break;
	}
}
