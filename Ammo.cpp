#include "Ammo.h"
#include "Player.h"
#include "Enemy.h"
#include "GameForm.h"
#include <iostream>
#include <list>

using namespace std;

void Ammo::ListOfPlayers()
{
    list<Point> players{ playerPosition.X,  playerPosition.Y };
    Point first{ players.front() };
    Point last{ players.back() };
}

void Ammo::ListOfEnemies()
{
    list<Point> enemies{ enemyPosition.X, enemyPosition.Y };
    Point first{ enemies.front() };
    Point last{ enemies.back() };
}

void Ammo::ListOfWalls()
{
    list<Point> walls{ WallPosition.X, WallPosition.Y };
    Point first{ walls.front() };
    Point last{ walls.back() };
}

void Ammo::PlayerShoot(KeyEventArgs^ e)
{
    switch (e->KeyCode) 
    {
    case Keys::E:
        if (look == 1) 
        {

        }
        else if (look == -1)
        {

        }
        else if (look == 2)
        {

        }
        else if (look == -2)
        {

        }
    }
}

void Ammo::EnemyShoot()
{
    
}
