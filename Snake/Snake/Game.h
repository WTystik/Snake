#pragma once
#include <iostream>
#include <ctime>
#include "Draw.h"
#include "Snake.h"

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Game : public Draw
{
public:
	Snake *snake;
	int tailX[100], tailY[100]; //В массивах кординаты хвоста змейки
	eDirection dir; // Направление движения змейки
	bool gameOver; // Флаг завершения игры
	int HeadX, HeadY, fruitX, fruitY, score; // Координаты головы змейки, фруктов и счет игрока

	Game(); // конструктор для начала игры
	bool DrawVerticalBorders(int, int) override; // Метод DrawVerticalBorders рисует вертикальные границы поля
	bool DrawHeadOfSnake(int, int) override; // Метод DrawHeadOfSnake рисует голову змейки
	bool DrawFruits(int, int) override;     // Метод DrawFruits рисует фрукты
	void DrawHorizontalBorders() override; // Метод DrawHorizontalBorders рисует горизонтальные границы поля
	void DrawSnakeTailOrSpace(int, int) override; // Метод DrawSnakeTailOrSpace рисует элементы хвоста змейки
	void Draw(); // Метод Draw отвечает за отрисовку игрового поля
	void Input(); // Метод Input обрабатывает пользовательский ввод 
	void Logic(); // Метод Logic реализует логику игры
	void TailStep(); // Метод TailStep отвечает за движение хвоста змейки
	void ChangeOfHeadPosition(); // Метод ChangeOfHeadPosition изменяет координаты головы змейки
	void EatingFruits(); // Метод EatingFruits реализует процесс поедания фруктов
	void HeadToTailCheck();     // Метод HeadToTailCheck проверяет столкновение головы с хвостом
	void MeetingWithBorders(); // Метод MeetingWithBorders проверяет столкновение змейки с границами поля

	bool CheckTailAndFruitCoincidence();     // Метод CheckTailAndFruitCoincidence проверяет совпадение координат хвоста и фруктов
};
