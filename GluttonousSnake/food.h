#pragma once
#include"scene.h"

class Food
{
public:
	Food(Scene &sce);
	~Food();

	void PlaceFood();

private :
	int x;
	int y;
	Scene &scene;

};

