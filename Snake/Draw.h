#pragma once
#include <iostream>

//��������� ������, � ������� ����������� ����������� �����
class Draw
{
public:
	virtual bool DrawVerticalBorders(int, int) = 0; // ����� DrawVerticalBorders ������ ������������ ������� ����
	virtual bool DrawHeadOfSnake(int, int) = 0; // ����� DrawHeadOfSnake ������ ������ ������
	virtual bool DrawFruits(int, int) = 0;     // ����� DrawFruits ������ ������
	virtual void DrawHorizontalBorders() = 0; // ����� DrawHorizontalBorders ������ �������������� ������� ����
	virtual void DrawSnakeTailOrSpace(int, int) = 0; // ����� DrawSnakeTailOrSpace ������ �������� ������ ������
};
