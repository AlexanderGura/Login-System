// User.cpp -- ����������� ������� ������ User

#include "User.h"

User::User()
{
	name = password = "No data";	// ��� ������!
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
	os << "Username: " << us.name << "\n"		// ����� �����
		<< "Password: " << us.password << "\n";	// ����� ������
	return os;
}

std::istream& operator>>(std::istream& is, User& us)
{
	std::string nick, pass;		// ��������� ������ ��� �������� ����� � ������

	std::cout << "Username: ";
	getline(is, nick);			// ���� �����
	us.name = nick;

	std::cout << "Password: ";
	getline(is, pass);			// ���� ������
	us.password = pass;

	return is;
}
