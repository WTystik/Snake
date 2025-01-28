#include <iostream>
#include <ctime>
#include <windows.h> //��� ����, ��� �� ���������� ������� ���� � ���������
#include <conio.h> // consel input ��� ������������ ����, ��� ����� ������������
#include "Game.h"

int main()
{
	Game game;// �������� ������� ������ Game
	while (!game.gameOver) // ���� ���� �� ���������
	{
		game.Draw(); // ��������� �������� ����
		game.Input(); // ��������� ����������������� �����
		game.Logic(); // ���������� ������ ����
		Sleep(100); // �������� ����� ��������� �����������
	}
	std::cout << "Game Over!" << std::endl; // ����� ��������� �� ��������� ����
	std::cout << "Your score: " << game.score << std::endl; // ����� ����� ������
	return 0;
}
