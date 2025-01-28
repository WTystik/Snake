#include <iostream>
#include <ctime>
#include <windows.h> //��� ����, ��� �� ���������� ������� ���� � ���������
#include <conio.h> // consel input ��� ������������ ����, ��� ����� ������������
#include "Snake.h"

int main()
{
	Game game;// �������� ������� ������ Game
	while (!game.gameOver) // ���� ���� �� ���������
	{
		game.Draw(); // ��������� �������� ����
		game.Input(); // ��������� ����������������� �����
		game.Logic(); // ���������� ������ ����
		Sleep(500); // �������� ����� ��������� �����������
	}
	std::cout << "Game Over!" << std::endl; // ����� ��������� �� ��������� ����
	std::cout << "Your score: " << game.score << std::endl; // ����� ����� ������
	return 0;
}