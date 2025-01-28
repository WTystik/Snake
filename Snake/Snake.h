#pragma once
#include <iostream>
#include <ctime>

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

class Snake
{
protected:
	int width; //������ ����
	int height; //������ ����
	int tailX[100], tailY[100]; //� �������� ��������� ������ ������
	int nTail; //������ ������ ������

public:
	//�����������, �������� ��������� �������� ������
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
	int width; //������ ����
	int height; //������ ����
	int tailX[100], tailY[100]; //� �������� ��������� ������ ������
	int nTail; //������ ������ ������
	eDirection dir; // ����������� �������� ������
	bool gameOver; // ���� ���������� ����
	int HeadX, HeadY, fruitX, fruitY, score; // ���������� ������ ������, ������� � ���� ������

public:
	Game() // ����������� ��� ������ ����
	{
		width = 20;
		height = 15;
		srand(time(NULL)); // ������������� ���������� ��������� �����
		gameOver = false;
		dir = STOP;
		HeadX = (width / 2) - 1;
		HeadY = (width / 2) - 1;
		fruitX = rand() % (width - 1);
		fruitY = rand() % height;
		score = 0;
	}

	void Draw(); // ����� Draw �������� �� ��������� �������� ����
	void Input(); // ����� Input ������������ ���������������� ���� 
	void Logic(); // ����� Logic ��������� ������ ����
	void DrawHorizontalBorders(); // ����� DrawHorizontalBorders ������ �������������� ������� ����
	void DrawSnakeTailOrSpace(int, int); // ����� DrawSnakeTailOrSpace ������ �������� ������ ������
	void TailStep(); // ����� TailStep �������� �� �������� ������ ������
	void ChangeOfHeadPosition(); // ����� ChangeOfHeadPosition �������� ���������� ������ ������
	void EatingFruits(); // ����� EatingFruits ��������� ������� �������� �������
	void HeadToTailCheck();     // ����� HeadToTailCheck ��������� ������������ ������ � �������
	void MeetingWithBorders(); // ����� MeetingWithBorders ��������� ������������ ������ � ��������� ����

	bool DrawVerticalBorders(int, int); // ����� DrawVerticalBorders ������ ������������ ������� ����
	bool DrawHeadOfSnake(int, int); // ����� DrawHeadOfSnake ������ ������ ������
	bool DrawFruits(int, int);     // ����� DrawFruits ������ ������
	bool CheckTailAndFruitCoincidence();     // ����� CheckTailAndFruitCoincidence ��������� ���������� ��������� ������ � �������
};
