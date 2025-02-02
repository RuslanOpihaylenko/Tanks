#include "Creature.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Creature::Creature() {
	this->position = Point(100, 100);
	this->size = 10;
}

Creature::Creature(int positionX, int positionY) {
	this->position = Point(positionX, positionY);
	this->size = 10;
}

void Creature::setNewPosition(Point obj) {
	this->position = obj;
}


Point Creature::getPosition() {
	return this->position;
}

int Creature::getX() {
	return this->position.X;
}

int Creature::getY() {
	return this->position.Y;
}

int Creature::getSize() {
	return this->size;
}

Brush^ Creature::getBrush() {
	return this->brush;
}