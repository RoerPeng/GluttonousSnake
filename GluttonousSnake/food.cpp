#include "food.h"
#include<iostream>

Food::Food(Scene & sce) : scene(sce)
{

}

Food::~Food()
{

}

void Food::PlaceFood()
{
	while (true)
	{
		int x = (rand() % (scene.Length() - 2))+1;
		int y = (rand() % (scene.Width() - 2))+1;
		if (scene.GetCell(x, y) == ' ')
		{
			scene.SetCell(x,y,'#');
			break;
		}
	}


}
