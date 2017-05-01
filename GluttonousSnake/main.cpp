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
	snake.color = FOREGROUND_RED;

	snake.InitSnake(2,2);

	Snake snake2(scene, food);
	snake2.color = FOREGROUND_GREEN;
	snake2.InitSnake(8, 2);
	
	snake.ticker =  snake2.ticker = clock();


	//int tick = clock();
	//int tick2 = clock();

	 snake.moveKey = 'd';
	 snake2.moveKey = 'd';
	char key = 'd';
	while (true)
	{
		key = _getch();
		if (key == '8' || key == '5' || key == '4' || key == '6')
		{	
			char key2;
			if (key == '8')key2 = MOVE_KEY::UP;
			if (key == '5')key2 = MOVE_KEY::DOWN;
			if (key == '4')key2 = MOVE_KEY::LEFT;
			if (key == '6')key2 = MOVE_KEY::RIGHT;

			if ((snake2.moveKey == MOVE_KEY::DOWN &&   snake2.moveKey == MOVE_KEY::UP) ||
				(snake2.moveKey == MOVE_KEY::UP &&   snake2.moveKey == MOVE_KEY::DOWN) ||
				(snake2.moveKey == MOVE_KEY::LEFT &&   snake2.moveKey == MOVE_KEY::RIGHT) ||
				(snake2.moveKey == MOVE_KEY::RIGHT &&   snake2.moveKey == MOVE_KEY::LEFT))
			{

			}
			else
			{
				snake2.moveKey = key2;
				snake2.ticker = 0;
			}
			
		}


		if (key == MOVE_KEY::UP || key == MOVE_KEY::DOWN ||
			key == MOVE_KEY::LEFT || key == MOVE_KEY::RIGHT)
		{
			if ((snake.moveKey == MOVE_KEY::DOWN &&   snake.moveKey == MOVE_KEY::UP) ||
				(snake.moveKey == MOVE_KEY::UP &&   snake.moveKey == MOVE_KEY::DOWN) ||
				(snake.moveKey == MOVE_KEY::LEFT &&   snake.moveKey == MOVE_KEY::RIGHT) ||
				(snake.moveKey == MOVE_KEY::RIGHT &&   snake.moveKey == MOVE_KEY::LEFT) )
			{

			}
			else
			{
				snake.moveKey = key;
				snake.ticker = 0;
			}

		}


		do
		{

			if ( ( clock() - snake2.ticker ) >= 500)
			{	
			

				if (snake2.SnakeMove((MOVE_KEY)snake2.moveKey) == -1)
				{
					//snake2.DestroySnake();
				}

				snake2.ticker = clock();
			}

			if ((clock() - snake.ticker) >= 500)
			{
				if (snake.SnakeMove((MOVE_KEY)snake.moveKey) == -1)
				{
					//snake.DestroySnake();
				}
				snake.ticker = clock();
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