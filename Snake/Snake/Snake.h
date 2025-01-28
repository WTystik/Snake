#pragma once
class Snake
{
public:
	int width; //Ширина поля
	int height; //Высота поля
	int tailX[100], tailY[100]; //В массивах кординаты хвоста змейки
	int nTail; //Длинна хвоста змейки
	//Конструктор, задающий начальное значение змейки
	Snake()
	{
		width = 20;
		height = 15;
		nTail = 0;
	}
};
