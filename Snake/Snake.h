#pragma once
#include <iostream>
#include <ctime>

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake
{
protected:
	int width; //Ширина поля
	int height; //Высота поля
	int tailX[100], tailY[100]; //В массивах кординаты хвоста змейки
	int nTail; //Длинна хвоста змейки

public:
	//Конструктор, задающий начальное значение змейки
	Snake()
	{
		width = 20;
		height = 15;
		nTail = 0;
	}
};

class Game
{
private:
	int width; //Ширина поля
	int height; //Высота поля
	int tailX[100], tailY[100]; //В массивах кординаты хвоста змейки
	int nTail; //Длинна хвоста змейки
	eDirection dir; // Направление движения змейки
	bool gameOver; // Флаг завершения игры
	int HeadX, HeadY, fruitX, fruitY, score; // Координаты головы змейки, фруктов и счет игрока

public:
	Game() // конструктор для начала игры
	{
		width = 20;
		height = 15;
		srand(time(NULL)); // Инициализация генератора случайных чисел
		gameOver = false;
		dir = STOP;
		HeadX = (width / 2) - 1;
		HeadY = (width / 2) - 1;
		fruitX = rand() % (width - 1);
		fruitY = rand() % height;
		score = 0;
	}

	void Draw(); // Метод Draw отвечает за отрисовку игрового поля
	void Input(); // Метод Input обрабатывает пользовательский ввод 
	void Logic(); // Метод Logic реализует логику игры
	void DrawHorizontalBorders(); // Метод DrawHorizontalBorders рисует горизонтальные границы поля
	void DrawSnakeTailOrSpace(int, int); // Метод DrawSnakeTailOrSpace рисует элементы хвоста змейки
	void TailStep(); // Метод TailStep отвечает за движение хвоста змейки
	void ChangeOfHeadPosition(); // Метод ChangeOfHeadPosition изменяет координаты головы змейки
	void EatingFruits(); // Метод EatingFruits реализует процесс поедания фруктов
	void HeadToTailCheck();     // Метод HeadToTailCheck проверяет столкновение головы с хвостом
	void MeetingWithBorders(); // Метод MeetingWithBorders проверяет столкновение змейки с границами поля

	bool DrawVerticalBorders(int, int); // Метод DrawVerticalBorders рисует вертикальные границы поля
	bool DrawHeadOfSnake(int, int); // Метод DrawHeadOfSnake рисует голову змейки
	bool DrawFruits(int, int);     // Метод DrawFruits рисует фрукты
	bool CheckTailAndFruitCoincidence();     // Метод CheckTailAndFruitCoincidence проверяет совпадение координат хвоста и фруктов
};
