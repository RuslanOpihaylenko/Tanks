#pragma once
#include<time.h>
#include<stdlib.h>
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
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Size = System::Drawing::Size(500,500);
			this->Text = L"WarOfTanks";
			this->BackColor = Color::Black;
			this->ResumeLayout(false);
			srand(time(NULL));
			AmmoPosition = Point(100, 100);
			PlaceWall();
			//RoadOfAmmo();
			timer = gcnew Timer();
			timer->Interval = 200;
			timer->Tick += gcnew EventHandler(this, &GameForm::OnTimerTick);
			timer->Start();
			this->Paint += gcnew PaintEventHandler(this, &GameForm::OnPaint);
			this->KeyDown += gcnew KeyEventHandler(this, &GameForm::OnKeyDown);
		}
#pragma endregion
		void PlaceWall()
		{
			int maxX = this->ClientSize.Width / blockSize;
			int maxY = this->ClientSize.Height / blockSize;
			WallPosition = Point(rand() % maxX * blockSize, rand() % maxY * blockSize);
		}

		/*void RoadOfAmmo()
		{
			AmmoPosition = Point(100+moveX, 0);
		}*/

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
		void OnKeyDown(Object^ obj, KeyEventArgs^ e)
		{
			switch (e->KeyCode)
			{
			case Keys::W:
				moveX = 0;
				moveY = -1;
				break;
			case Keys::S:
				moveX = 0;
				moveY = 1;
				break;
			case Keys::A:
				moveX = -1;
				moveY = 0;
				break;
			case Keys::D:
				moveX = 1;
				moveY = 0;
				break;
			}
		}
	};
}
