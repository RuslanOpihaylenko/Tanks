#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
//-1 up
// 1 down
//-2 left
// 2 right
ref class Creature
{
protected:
	Point position;
	Brush^ brush;
	int size;
	int look;
public:
	Creature();
	Creature(int positionX, int positionY);
	void setNewPosition(Point obj);
	Point getPosition();
	int getX();
	int getY();
	int getSize();
	Brush^ getBrush();
};

