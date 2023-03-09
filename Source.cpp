#include "FazzyNumber.h"
#include <Windows.h>

void Compare(FazzyNumber a, FazzyNumber b)
{
	if (a == b)
	{
		std::cout << a << " = " << b << std::endl;
	}
	else
	{
		std::cout << a << " != " << b << std::endl;
	}
}

FazzyNumber Operation(FazzyNumber a, FazzyNumber b)
{
	FazzyNumber result;
	bool menu = true;
	while (menu)
	{
		char choice;
		std::cout << "Выберите арифметическую операцию: + - * / ";
		std::cin >> choice;
		switch (choice)
		{
		case '+':
			result = a + b;
			menu = false;
			break;
		case '-':
			result = a - b;
			menu = false;
			break;
		case '*':
			result = a * b;
			menu = false;
			break;
		case '/':
			result = a / b;
			menu = false;
			break;
		default:
			std::cout << "Неверный ввод! " << std::endl;
			menu = true;
			break;
		}
	}
	return result;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	bool flag = true;
	while (flag)
	{
		bool menu = true;
		while (menu)
		{
			FazzyNumber a, b, result;
			char choice;
			std::cout << "Выберите действие с нечеткими числами: 1 - сравнить на равность, 2 - арифметическая операция ";
			std::cin >> choice;
			std::cout << "Введите два нечетких числа в формате \"e1 x e2\" " << std::endl;
			std::cout << "1: "; std::cin >> a;
			std::cout << "2: "; std::cin >> b;
			switch (choice)
			{
			case '1':
				Compare(a, b);
				menu = false;
				break;
			case '2':
				result = Operation(a, b);
				std::cout << "Результат: " << result << std::endl;
				menu = false;
				break;
			default:
				std::cout << "Неверный ввод! " << std::endl;
				menu = true;
				break;
			}
		}

		char choice;
		bool label = true;
		while (label)
		{
			std::cout << "Желаете начать заново или выйти? 1 - заново, 2 - выйти ";
			std::cin >> choice;
			switch (choice)
			{
			default:
				std::cout << "Неверный ввод!" << std::endl;
				label = true;
				break;
			case '1':
				flag = true;
				label = false;
				break;
			case '2':
				flag = false;
				label = false;
				break;
			}
		}
	}
}
