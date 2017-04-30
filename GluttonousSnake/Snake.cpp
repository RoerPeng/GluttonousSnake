#include "Snake.h"
#include <iostream>
using namespace std;

Snake::Snake(Scene & sce, Food & fd) : scene(sce),food(fd)
{
	
}


Snake::~Snake()
{

}

void Snake::InitSnake()
{
	list = new Note;

	for (int i = 0; i < 3; ++i)
	{
		if (i == 0)
		{
			tail=AddNote(2, i + 1);
		}
		else
		{
			AddNote(2, i + 1);
		}
	}

}

Snake::Note * Snake::AddNote(int x, int y)
{
	Note * newOne = new Note();
	newOne->x = x;
	newOne->y = y;
	newOne->next = NULL;
	if (list->next != NULL)
	{
		scene.SetCell(list->next->x, list->next->y, 'o');
	}
	newOne->next = list->next;
	list->next = newOne;
	scene.SetCell(newOne->x, newOne->y, 'a');
	++score;

	return newOne;
}

void Snake::DestroySnake()
{
	if (list==NULL)
	{
		cout << "No Snake!" << endl;
		return;
	}

	Note * next = list->next;
	while (next != NULL)
	{
		Note * temp = next->next;
		scene.SetCell(next->x, next->y, ' ');
		delete next;
		next = temp;
	}
	delete list;
	list = NULL;
	score = 0;
	scene.SetScore(score);
}

void Snake::DeleteTail()
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == list->next)
	{
		return;
	}

	Note * cur = list ;
	Note * del = list->next ;
	while (del->next != NULL)
	{
		cur = del;
		del = del->next;
	}
	scene.SetCell(del->x, del->y, ' ');
	delete del;
	cur->next = NULL;
	tail = cur;
	--score;
}

int Snake::SnakeMove(MOVE_KEY key)
{
	if (NULL == list || NULL == list->next)
	{
		return 0;
	}

	int x = list->next->x;
	int y = list->next->y;
	
	switch (key)
	{
		case MOVE_KEY::UP:
			--x;
			break;
		case MOVE_KEY::DOWN :
			++x;
			break;
		case MOVE_KEY::LEFT:
			--y;
			break;
		case MOVE_KEY::RIGHT:
			++y;
			break;
		default:
			break;
	}
	
	Note * note2 = list->next->next;
	if(note2!=NULL)
	{
		if (x == note2->x && y == note2->y)
		{
			return 0;
		}
	}

	char to = scene.GetCell(x, y);


	if (to == 'o')
	{
		if (x == tail->x&&y == tail->y)
		{
			to = ' ';
		}
		else
		{
			to = '*';
		}
	}

	if (to == '*')
	{
		return -1;
	}
	
	if (to == ' ')
	{
		DeleteTail();
		AddNote(x,y);		
	}
	
	if( to == '#')
	{
		AddNote(x, y);
		food.PlaceFood();
		scene.SetScore(score-3);
	}
	return 1;
}


