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
	int tailX[100], tailY[100]; //� �������� ��������� ������ ������
	eDirection dir; // ����������� �������� ������
	bool gameOver; // ���� ���������� ����
	int HeadX, HeadY, fruitX, fruitY, score; // ���������� ������ ������, ������� � ���� ������

	Game(); // ����������� ��� ������ ����
	bool DrawVerticalBorders(int, int) override; // ����� DrawVerticalBorders ������ ������������ ������� ����
	bool DrawHeadOfSnake(int, int) override; // ����� DrawHeadOfSnake ������ ������ ������
	bool DrawFruits(int, int) override;     // ����� DrawFruits ������ ������
	void DrawHorizontalBorders() override; // ����� DrawHorizontalBorders ������ �������������� ������� ����
	void DrawSnakeTailOrSpace(int, int) override; // ����� DrawSnakeTailOrSpace ������ �������� ������ ������
	void Draw(); // ����� Draw �������� �� ��������� �������� ����
	void Input(); // ����� Input ������������ ���������������� ���� 
	void Logic(); // ����� Logic ��������� ������ ����
	void TailStep(); // ����� TailStep �������� �� �������� ������ ������
	void ChangeOfHeadPosition(); // ����� ChangeOfHeadPosition �������� ���������� ������ ������
	void EatingFruits(); // ����� EatingFruits ��������� ������� �������� �������
	void HeadToTailCheck();     // ����� HeadToTailCheck ��������� ������������ ������ � �������
	void MeetingWithBorders(); // ����� MeetingWithBorders ��������� ������������ ������ � ��������� ����

	bool CheckTailAndFruitCoincidence();     // ����� CheckTailAndFruitCoincidence ��������� ���������� ��������� ������ � �������
};
