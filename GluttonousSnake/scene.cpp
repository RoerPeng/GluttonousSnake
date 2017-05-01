#include "scene.h"
#include <iostream>
#include <string>
using namespace std;

Scene::Scene(int width, int length)
{
	this->width = width;
	this->length = length;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

Scene::~Scene()
{
}

void Scene::gotoxy(int x, int y , unsigned short ForeColor = FOREGROUND_INTENSITY)
{
	COORD pos;
	pos.X = x ;
	pos.Y = y;
	SetConsoleCursorPosition(hOut,pos);

	SetConsoleTextAttribute(hOut, ForeColor);
}


void Scene::InitScene()
{

	for (int x = 0; x < ROW; ++x)
	{
		for (int y = 0; y < COMLUME; ++y)
		{
			if ( x == 0 || y == 0 || x == width - 1 || y == length - 1)
			{
				board[x][y] = '*';
			}
			else
			{
				board[x][y] = ' ';
			}
		}
	}
}



void Scene::SetCell(int x, int y , char ch ,
					unsigned short ForeColor)
{
	board[x][y] = ch;

	gotoxy(y * 2, x , ForeColor);
	cout << ch;
	gotoxy(0, length);

}

void Scene::SetScore(int score)
{
	gotoxy( (length-1) * 2 + 10 , 7);
	cout << score;
	gotoxy(0, length);
}

char Scene::GetCell(int x, int y)
{
	return board[x][y];
}

void Scene::PrintBoard()
{
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < length; ++y)
		{
			cout << board[x][y]<<' ';
		}

		if (x == 2)
		{
			cout << "Gluttonous Snake 1.0 ";
		}

		if (x == 3)
		{
			cout << "up : w";
		}

		if (x == 4)
		{
			cout << "down : s";
		}

		if (x == 5)
		{
			cout << "left : a";
		}

		if (x == 6)
		{
			cout << "right : d";
		}

		if (x == 7)
		{
			cout << "Score : ";// << score;
		}

		if (x == 12)
		{
			cout << "       By : Peng Hao";
		}

		cout << endl;
	}
}

int Scene::Width() const
{
	return width;
}

int Scene::Length() const
{
	return length;
}


