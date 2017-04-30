#pragma once
#include "scene.h"
#include <iostream>
#include "food.h"

class Snake
{
	struct  Note
	{
		int x;
		int y;
		Note * next = NULL;
	};

public:
	Snake(Scene & sce , Food & fd );
	~Snake();

	void InitSnake();

	Note * AddNote(int x, int y);

	void DestroySnake();

	void DeleteTail();

	int SnakeMove(MOVE_KEY key);

private :
	Scene & scene;
	Note * list;
	int score;
	Note * tail;
	Food & food;
};

