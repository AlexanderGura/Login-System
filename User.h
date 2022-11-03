// User.h -- ���������� ������ User

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <fstream>
#include <string>

class User
{
private:
	std::string name;		// ��� ������������ � �������
	std::string password;	// ������ ������������ � �������
public:
	User();		// ����������� �� ���������
	User(std::string& nick, std::string& pass);	// ����������� � ��������-�����������
	~User();	// ���������� �� ���������

	std::string FileName() const { return name; };	// ���������� �������� ����� ������������

	bool Check(std::string& CheckName, std::string& CheckPass) const;

	// ���������� �������� ������� ��� ������ �������
	friend std::ostream& operator<<(std::ostream& os, const User& us);

	// ���������� �������� ���������� ��� ������ ������ � ������
	friend std::istream& operator>>(std::istream& is, User& us);
};

#endif