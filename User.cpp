// User.cpp -- определение методов класса User

#include "User.h"

User::User()
{
	name = password = "No data";	// Нет данных!
}

User::User(std::string& nick, std::string& pass)
{
	name = nick;
	password = pass;
}

User::~User() {}

bool User::Check(std::string& CheckName, std::string& CheckPass) const
{
	return (name == CheckName && password == CheckPass);
}

std::ostream& operator<<(std::ostream& os, const User& us)
{
	os << "Username: " << us.name << "\n"		// Вывод имени
		<< "Password: " << us.password << "\n";	// Вывод пароля
	return os;
}

std::istream& operator>>(std::istream& is, User& us)
{
	std::string nick, pass;		// Временные строки для хранения имени и пароля

	std::cout << "Username: ";
	getline(is, nick);			// Ввод имени
	us.name = nick;

	std::cout << "Password: ";
	getline(is, pass);			// Ввод пароля
	us.password = pass;

	return is;
}
