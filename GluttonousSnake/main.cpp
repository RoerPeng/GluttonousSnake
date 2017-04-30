#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "scene.h"
#include"Snake.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>

void Game()
{
	srand((unsigned)time(NULL));
	Scene scene(20,20);

	scene.InitScene();
	scene.PrintBoard();

	Food food(scene);
	food.PlaceFood();
	
	Snake snake(scene,food);
	snake.InitSnake();
	
	int tick = clock();


	char moveKey = 'd';
	char key = 'd';
	while (true)
	{
		key = _getch();
		if (key == '8')key = MOVE_KEY::UP;
		if (key == '5')key = MOVE_KEY::DOWN;
		if (key == '4')key = MOVE_KEY::LEFT;
		if (key == '6')key = MOVE_KEY::RIGHT;

		if (key == MOVE_KEY::UP || key == MOVE_KEY::DOWN ||
			key == MOVE_KEY::LEFT || key == MOVE_KEY::RIGHT)
		{
			if ((moveKey == MOVE_KEY::DOWN &&  moveKey == MOVE_KEY::UP) ||
				(moveKey == MOVE_KEY::UP &&  moveKey == MOVE_KEY::DOWN) ||
				(moveKey == MOVE_KEY::LEFT &&  moveKey == MOVE_KEY::RIGHT) ||
				(moveKey == MOVE_KEY::RIGHT &&  moveKey == MOVE_KEY::LEFT) )
			{

			}
			else
			{
				moveKey = key;
				tick = 0;
			}

		}


		do
		{

			if ( ( clock() - tick ) >= 500)
			{
				int reslut = snake.SnakeMove((MOVE_KEY)moveKey);
				if (reslut == -1)
				{
					cout << "GAME OVER !" << endl;
					break;
				}
				tick = clock();
			}
			Sleep(10);
		} while (!_kbhit());
	}	

	snake.DestroySnake();	
	system("cls");
	scene.PrintBoard();
	
}

int main()
{
	Game();

	system("pause");
	return EXIT_SUCCESS;
}