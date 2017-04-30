#pragma once
#include<Windows.h>
enum MOVE_KEY
{
	UP = 'w',
	DOWN = 's',
	LEFT = 'a',
	RIGHT = 'd' 
};

class Scene
{


public:
	const static int ROW = 26;
	const static int COMLUME = 26;
		
public:
	Scene(int width , int length);

	void InitScene();
	
	void SetCell(int x, int y , char ch);

	void SetScore(int score);

	char GetCell(int x, int y);

	void PrintBoard();

	int Width() const;
	int Length() const;

	~Scene();

	 void gotoxy(int x, int y);

	 HANDLE hOut;

private:
	int width;
	int length;
	char board[ROW][COMLUME];
};

