#include <iostream>		// Стандартный ввод, вывод
#include <fstream>		// Файловый ввод, вывод
#include <string>		// Класс для работы со строками
#include "User.h"		// Класс для работы с пользователями

bool FileIsExist(const std::string& filename);	// Проверка файла на существование

int main()
{
	std::ofstream fout;		// Объект для записи в файл
	std::ifstream fin;		// Объект для чтения файлов

	int choice;				// Выбор режима (1 - регистрация, 2 - вход в систему)
	std::cout << "1. Registration in the system\n2. Login to the system\n3. Quit\n";
	std::cout << "Enter your choice: ";

	while (std::cin >> choice)
	{
		std::cin.get();		// Считывание символа новой строки
		User test;			// Создание пользователя
		std::cin >> test;	// Ввод данных пользователя

		switch (choice)
		{
			case 1:
			{
				fout.open(test.FileName() + ".txt");	// Создание файла
				fout << test;							// Вывод данных в файл
				std::cout << "Successful registration!";// Успешная регистрация!
				break;
				fout.close();
			}
			case 2:
			{
				if (FileIsExist(test.FileName() + ".txt"))		// Если файл(учётная запись) существует
				{
					fin.open(test.FileName() + ".txt");

					for (int i = 0; i < 10; i++)	// Отбрасывание ненужной строки ("Username: ")
						fin.get();
					std::string CheckName;
					std::getline(fin, CheckName);	// Получение имени из файла

					for (int i = 0; i < 10; i++)	// Отбрасывание ненужной строки ("Password: ")
						fin.get();
					std::string CheckPass;
					std::getline(fin, CheckPass);	// Получение пароля из файла

					if (test.Check(CheckName, CheckPass))	// Сравнение данных в файле и в объекте
						std::cout << "You login to the system!\n";
					else
						std::cout << "Please, enter correct password!\n";

					fin.close();
				}
				else
					std::cout << "User with this name is not found!\n";
				break;
			}
			default:
			{
				std::cout << "Incorrect choice!\n";
				break;
			}
		}
		std::cout << "\n\nEnter your choice: ";
	}
	std::cout << "Good bye!";

	fout.close();	// Закрытие файла
	fin.close();

	return 0;
}

bool FileIsExist(const std::string& filename)
{
	std::ifstream file(filename);
	return file.is_open();
}