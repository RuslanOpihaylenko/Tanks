#pragma once
#include<time.h>
#include<stdlib.h>
#include"Player.h"
#include"Enemy.h"
#include"Creature.h"
#include"PlayerAmmo.h"
#include"EnemyAmmo.h"
#include"Wall.h"

namespace Project2Tanks {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

		virtual void OnPaint(System::Object^ obj, PaintEventArgs^ e) override
		{
			Graphics^ paint = e->Graphics;
			paint->FillRectangle(enemy.getBrush(), enemy.getX(), enemy.getY(), enemy.getSize(), enemy.getSize());
			paint->FillRectangle(player.getBrush(), player.getX(), player.getY(), player.getSize(), player.getSize());
			Brush^ WallBrush = gcnew SolidBrush(Color::Gray);
			paint->FillRectangle(WallBrush, WallPosition.X, WallPosition.Y, blockSize, blockSize);

			Brush^ AmmoBrush = gcnew SolidBrush(Color::Red);
			paint->FillRectangle(AmmoBrush, AmmoPosition.X, AmmoPosition.Y, blockSize, blockSize);
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		Player player;
		Enemy enemy;
		Timer^ timer;
		int turn;
		Point WallPosition;
		Point AmmoPosition;
		const int blockSize = 20;
		Timer^ timer;
		int moveX = 1, moveY = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			//Game
			this->turn = 1;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Size = System::Drawing::Size(500,500);
			this->Text = L"WarOfTanks";
			this->BackColor = Color::Black;
			this->ResumeLayout(false);
			srand(time(NULL));
			AmmoPosition = Point(100, 100);
			PlaceWall();
			timer = gcnew Timer();
			timer->Interval = 200;
			timer->Tick += gcnew EventHandler(this, &GameForm::OnTimerTick);
			timer->Start();
			this->Paint += gcnew PaintEventHandler(this, &GameForm::OnPaint);
			this->KeyDown += gcnew KeyEventHandler(this, &GameForm::action);
		}
#pragma endregion
		void PlaceWall()
		{
			int maxX = this->ClientSize.Width / blockSize;
			int maxY = this->ClientSize.Height / blockSize;
			WallPosition = Point(rand() % maxX * blockSize, rand() % maxY * blockSize);
		}



		void OnTimerTick(Object^ obj, EventArgs^ e)
		{
			AmmoPosition.X += moveX * blockSize;
			AmmoPosition.Y += moveY * blockSize;
			if (AmmoPosition == WallPosition)
			{
				PlaceWall();
				AmmoPosition = Point(100, 100);
			}

			if (AmmoPosition.X < 0 || AmmoPosition.Y < 0 || AmmoPosition.X >= this->ClientSize.Width ||
				AmmoPosition.Y >= this->ClientSize.Height)
			{
				AmmoPosition = Point(100, 100);
			}
			this->Invalidate();
		}
		void placeEnemy() {
			srand(time(NULL));
			int maxX = this->ClientSize.Width / enemy.getSize();
			int maxY = this->ClientSize.Height / enemy.getSize();
			enemy.setNewPosition(Point(rand() % maxX * enemy.getSize(), rand() % maxY * enemy.getSize()));
		}
		void onTimerTick(Object^ obj, EventArgs^ e) {
			if (this->turn % 2 == 0) {
				enemy.enemyMove(player.getPosition());
				this->turn++;
			}
			this->Invalidate();
		}
		void action(Object^ obj, KeyEventArgs^ e) {
			if (this->turn % 2 != 0) {
				player.playerAction(e);
				this->turn++;
			}
		}
	};
}
