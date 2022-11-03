// User.h -- объявление класса User

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <fstream>
#include <string>

class User
{
private:
	std::string name;		// Имя пользователя в системе
	std::string password;	// Пароль пользователя в системе
public:
	User();		// Конструктор по умолчанию
	User(std::string& nick, std::string& pass);	// Конструктор с строками-аргументами
	~User();	// Деструктор по умолчанию

	std::string FileName() const { return name; };	// Возвращает название файла пользователя

	bool Check(std::string& CheckName, std::string& CheckPass) const;

	// Перегрузка операции вставки для вывода объекта
	friend std::ostream& operator<<(std::ostream& os, const User& us);

	// Перегрузка операции извлечения для записи данных в объект
	friend std::istream& operator>>(std::istream& is, User& us);
};

#endif