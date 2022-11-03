#include <iostream>		// ����������� ����, �����
#include <fstream>		// �������� ����, �����
#include <string>		// ����� ��� ������ �� ��������
#include "User.h"		// ����� ��� ������ � ��������������

bool FileIsExist(const std::string& filename);	// �������� ����� �� �������������

int main()
{
	std::ofstream fout;		// ������ ��� ������ � ����
	std::ifstream fin;		// ������ ��� ������ ������

	int choice;				// ����� ������ (1 - �����������, 2 - ���� � �������)
	std::cout << "1. Registration in the system\n2. Login to the system\n3. Quit\n";
	std::cout << "Enter your choice: ";

	while (std::cin >> choice)
	{
		std::cin.get();		// ���������� ������� ����� ������
		User test;			// �������� ������������
		std::cin >> test;	// ���� ������ ������������

		switch (choice)
		{
			case 1:
			{
				fout.open(test.FileName() + ".txt");	// �������� �����
				fout << test;							// ����� ������ � ����
				std::cout << "Successful registration!";// �������� �����������!
				break;
				fout.close();
			}
			case 2:
			{
				if (FileIsExist(test.FileName() + ".txt"))		// ���� ����(������� ������) ����������
				{
					fin.open(test.FileName() + ".txt");

					for (int i = 0; i < 10; i++)	// ������������ �������� ������ ("Username: ")
						fin.get();
					std::string CheckName;
					std::getline(fin, CheckName);	// ��������� ����� �� �����

					for (int i = 0; i < 10; i++)	// ������������ �������� ������ ("Password: ")
						fin.get();
					std::string CheckPass;
					std::getline(fin, CheckPass);	// ��������� ������ �� �����

					if (test.Check(CheckName, CheckPass))	// ��������� ������ � ����� � � �������
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

	fout.close();	// �������� �����
	fin.close();

	return 0;
}

bool FileIsExist(const std::string& filename)
{
	std::ifstream file(filename);
	return file.is_open();
}