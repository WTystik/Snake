#pragma once
#include <iostream>

//Интерфейс класса, в котором реализована графическая часть
class Draw
{
public:
	virtual bool DrawVerticalBorders(int, int) = 0; // Метод DrawVerticalBorders рисует вертикальные границы поля
	virtual bool DrawHeadOfSnake(int, int) = 0; // Метод DrawHeadOfSnake рисует голову змейки
	virtual bool DrawFruits(int, int) = 0;     // Метод DrawFruits рисует фрукты
	virtual void DrawHorizontalBorders() = 0; // Метод DrawHorizontalBorders рисует горизонтальные границы поля
	virtual void DrawSnakeTailOrSpace(int, int) = 0; // Метод DrawSnakeTailOrSpace рисует элементы хвоста змейки
};
