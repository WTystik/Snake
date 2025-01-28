#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "Snake.h"

using namespace std;

void Game::DrawHorizontalBorders()
{
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
}

bool Game::DrawVerticalBorders(int y_coordinate, int x_coordinate)
{
	if (x_coordinate == 0 || x_coordinate == width - 1) // вывод вертикальных границ поля  -1 т.к мы стартуем с 0
	{
		cout << "#";
		return true;
	}
	return false;
}

bool Game::DrawHeadOfSnake(int y_coordinate, int x_coordinate)
{
	if (y_coordinate == HeadY && x_coordinate == HeadX) //вывод головы
	{
		cout << "0";
		return true;
	}
	return false;
}

bool Game::DrawFruits(int y_coordinate, int x_coordinate)
{
	if (y_coordinate == fruitY && x_coordinate == fruitX) //вывод фрукта
	{
		cout << "%";
		return true;
	}
	return false;
}

void Game::DrawSnakeTailOrSpace(int y_coordinate, int x_coordinate)
{
	bool print = false; // переменная примет true если мы нарисовали элемент хвоста
	for (int i = 0; i < nTail; i++)
		if (tailY[i] == y_coordinate && tailX[i] == x_coordinate)
		{
			print = true;
			cout << "o";
		}
	if (!print)//если не нарисовали элемент хвоста, то ставим пробел
		cout << ' ';
}

void Game::Draw()
{
	system("cls");//отчистка консоли
	DrawHorizontalBorders();// рисуем вверхнюю границу
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (DrawVerticalBorders(i, j));
			if (DrawHeadOfSnake(i, j));
			else
			{
				if (DrawFruits(i, j));
				else
				{
					DrawSnakeTailOrSpace(i, j);
				}
			}
		}
		cout << endl;
	}
	DrawHorizontalBorders();
	cout << "Score: " << score << endl;// вывод счета на экран
}

void Game::Input()
{
	if (_kbhit())//true если пользователь нажал клавишу 
	{
		switch (_getch())// какую клавишу надал пользователь
		{
		case 'a':
		{
			dir = LEFT;
			break;
		}
		case 's':
		{
			dir = DOWN;
			break;
		}
		case 'd':
		{
			dir = RIGHT;
			break;
		}
		case 'w':
		{
			dir = UP;
			break;
		}
		case 'x'://выход из игры
		{
			gameOver = true;
			break;
		}
		}
	}
}

void Game::TailStep()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;//следующий эл хвоста
	tailX[0] = HeadX;
	tailY[0] = HeadY;
	for (int i = 1; i < nTail; i++)//1 т.к мы записывали в prev 1 значение - 0 элемент, поэтому не проверяем,процесс движение хвоста, где каждый последующий эл змейки принимает координаты пред эл 
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
}

void Game::ChangeOfHeadPosition()
{
	switch (dir)// взависимости от значения перечисления dir изменяем координаты головы
	{
	case LEFT:
	{
		HeadX--;
		break;
	}
	case RIGHT:
	{
		HeadX++;
		break;
	}
	case UP:
	{
		HeadY--;
		break;
	}
	case DOWN:
	{
		HeadY++;
		break;
	}
	}
}

void Game::MeetingWithBorders()//реализация случая, когда голова змейки попадает на границу
{
	if (HeadX > width || HeadX < 0 || HeadY > height || HeadY < 0)
	gameOver = true;
}

void Game::HeadToTailCheck()
{
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == HeadX && tailY[i] == HeadY) //если змейка врезается в хвост
			gameOver = true;
	}
}

bool Game::CheckTailAndFruitCoincidence()
{
	bool f = true;
	for (int i = 0; i < nTail && f; i++)
	{
		f = false;
		if (tailX[i] == fruitX && tailY[i] == fruitY)
		{
			fruitX = rand() % (width - 1);
			fruitY = rand() % height;
			f = true;
		}
		else f = false;
	}
	return f;
}

void Game::EatingFruits()
{
	if (HeadX == fruitX && HeadY == fruitY)
	{
		score += 1;
		fruitX = rand() % (width - 1);//определяем координаты фрукта
		fruitY = rand() % height;
		if (nTail > 0)
			while (CheckTailAndFruitCoincidence());//проверка на совпадение координат
		nTail++;
	}
}

void Game::Logic()
{
	TailStep();
	ChangeOfHeadPosition();
	MeetingWithBorders();
	HeadToTailCheck();
	EatingFruits();
}