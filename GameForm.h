#pragma once
#include<fstream>
#include "Player.h"
#include <time.h>
#include "Creature.h"
#include "Enemy.h"
#include <time.h>
#include <stdlib.h>
#include "Node.h"
#include "MyList.h"
#include "Wall.h"

using namespace std;


namespace Project2Tanks {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		virtual void onPaint(System::Object^ obj, PaintEventArgs^ e) override {
			Graphics^ g = e->Graphics;
			for (int i = 1; i <= *enemyCount; i++) {
				Enemy^ cell = enemy->getEnemyFromPosition(i);
				g->FillRectangle(cell->getBrush(), cell->getX(), cell->getY(), cell->getSize(), cell->getSize());
			}
			for (int i = 1; i <= *wallsCount; i++) {
				Wall^ cell = walls->getEnemyFromPosition(i);
				g->FillRectangle(cell->getBrush(), cell->getX(), cell->getY(), cell->getSize(), cell->getSize());
			}
			g->FillRectangle(player->getBrush(), player->getX(), player->getY(), player->getSize(), player->getSize());

		}
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		int^ enemyCount;
		Player^ player;
		MyList<Enemy>^ enemy;
		MyList<Wall>^ walls;
		int^ wallsCount;
		Timer^ timer;
		int turn;
		GameForm^ turns;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			turns = gcnew GameForm();
			turns->ForeColor = Color::White;
			turns->BackColor = Color::Transparent;
			turns->Text = "Turn 0";
			this->Controls->Add(turns);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(500, 500);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			// 
			// MyForm
			// 
			this->player = gcnew Player();
			this->enemy = gcnew MyList<Enemy>();
			this->walls = gcnew MyList<Wall>();
			this->enemyCount = 5;
			this->wallsCount = 100;
			for (int i = 1; i <= *wallsCount; i++) {
				this->walls->addToHead();
			}
			for (int i = 1; i <= *enemyCount; i++) {
				this->enemy->addToHead();
			}

			for (int i = 1; i <= *enemyCount; i++) {
				this->enemy->getEnemyFromPosition(i)->setEnemyList(this->enemy);
				this->enemy->getEnemyFromPosition(i)->setEnemyCount(this->enemyCount);
			}
			for (int i = 1; i <= *enemyCount; i++) {
				this->enemy->getEnemyFromPosition(i)->setWallsList(this->walls);
				this->enemy->getEnemyFromPosition(i)->setWallsCount(this->wallsCount);
			}


			this->player->setEnemyList(this->enemy);
			this->player->setEnemyCount(enemyCount);
			this->player->setWallsList(this->walls);
			this->player->setWallsCount(wallsCount);
			this->player->setBoardSize(Point(this->ClientSize.Width, this->ClientSize.Height));

			placeObjects();
			player->setNewPosition(Point(10, 10));
			timer = gcnew Timer();
			timer->Interval = 200;
			timer->Tick += gcnew EventHandler(this, &GameForm::onTimerTick);
			timer->Start();
			this->Paint += gcnew PaintEventHandler(this, &GameForm::onPaint);
			this->KeyDown += gcnew KeyEventHandler(this, &GameForm::action);



		}
#pragma endregion
		bool isEmpty(Point testPoint) {
			if (testPoint == this->player->getPosition()) {
				return false;
			}
			for (int i = 1; i <= *enemyCount; i++) {
				if (testPoint == this->enemy->getEnemyFromPosition(i)->getPosition()) {
					return false;
				}
			}
			for (int i = 1; i <= *wallsCount; i++) {
				if (testPoint == this->walls->getEnemyFromPosition(i)->getPosition()) {
					return false;
				}
			}
			return true;
		}

		void placeObjects() {
			srand(time(NULL));
			int i = 1;
			while (i == 1) {
				Player^ cell = this->player;
				int maxX = this->ClientSize.Width / cell->getSize();
				int maxY = this->ClientSize.Height / cell->getSize();
				Point testPoint = Point(rand() % maxX * cell->getSize(), rand() % maxY * cell->getSize());
				if (isEmpty(testPoint) == true) {
					cell->setNewPosition(testPoint);
					i++;
				}
			}
			i = 1;
			while (i <= *enemyCount) {
				Enemy^ cell = enemy->getEnemyFromPosition(i);
				int maxX = this->ClientSize.Width / cell->getSize();
				int maxY = this->ClientSize.Height / cell->getSize();
				Point testPoint = Point(rand() % maxX * cell->getSize(), rand() % maxY * cell->getSize());
				if (isEmpty(testPoint) == true) {
					cell->setNewPosition(testPoint);
					i++;
				}
			}
			i = 1;
			while (i <= *wallsCount) {
				Wall^ cell = walls->getEnemyFromPosition(i);
				int maxX = this->ClientSize.Width / cell->getSize();
				int maxY = this->ClientSize.Height / cell->getSize();
				Point testPoint = Point((rand() % (maxX - 0 + 0) + 0) * cell->getSize(), (rand() % (maxY - 0 + 0) + 0) * cell->getSize());
				if (isEmpty(testPoint) == true) {
					cell->setNewPosition(testPoint);
					i++;
				}
			}

		}
		void BinaryFile(int turn)
		{
			int best_turn = 0;
			string fileName = "Counter.bin";
			ifstream fin(fileName, ios::binary);
			if (fin.is_open())
			{
				fin.read((char*)turn, sizeof(turn));
				fin.close();
			}
			else
			{
				MessageBox::Show("Error");
			}
			ofstream fout(fileName, ios::binary);
			if (fout.is_open())
			{
				if (best_turn < turn)
				{
					best_turn = turn;
					fout.write((char*)&turn, sizeof(turn));
					fout.close();
				}
			}
			else
			{
				MessageBox::Show("Error");
			}
			MessageBox::Show("Best_turn: ");
			turns->Text = "Turn: " + turn.ToString();
		}
		void onTimerTick(Object^ obj, EventArgs^ e) {
			if (this->turn % 2 == 0) {
				for (int i = 1; i <= *enemyCount; i++) {
					enemy->getEnemyFromPosition(i)->enemyAction(player->getPosition(), player->getAlive());
				}
				this->turn++;
			}
			this->Invalidate();
			if (*this->player->getAlive() == false) {
				timer->Stop();
				MessageBox::Show("You lose!!!");
				BinaryFile(turn);
				return;
			}
		}
		void action(Object^ obj, KeyEventArgs^ e) {
			if (this->turn % 2 != 0) {
				player->playerAction(e);
				this->turn++;
			}

		}
	};
}
