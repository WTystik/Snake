#include <iostream>
#include <ctime>
#include <windows.h> //для того, что бы обновления консоли было с задержкой
#include <conio.h> // consel input для отслеживания того, что нажал пользователь
#include "Game.h"

int main()
{
	Game game;// Создание объекта класса Game
	while (!game.gameOver) // Пока игра не завершена
	{
		game.Draw(); // Отрисовка игрового поля
		game.Input(); // Обработка пользовательского ввода
		game.Logic(); // Обновление логики игры
		Sleep(100); // Задержка перед следующим обновлением
	}
	std::cout << "Game Over!" << std::endl; // Вывод сообщения об окончании игры
	std::cout << "Your score: " << game.score << std::endl; // Вывод счета игрока
	return 0;
}
