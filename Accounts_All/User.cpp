#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;





class User {
private:
	char User_name[20];
	char User_pass[20];
	char User_role[15];
	char User_race[15];

public:
	//Default Constructor
	User() : User_name("Unknown"), User_pass("Unknown"), User_role("Unknown"), User_race("Unknown") {}

	//Overloaded Constructor

	User(char username[], char password[], char role[], char race[])
	{
		memcpy(this->User_name, username, 20);
		memcpy(this->User_pass, password, 20);
		memcpy(this->User_role, role, 15);
		memcpy(this->User_race, race, 15);

	}

	//Accessor Functions
	string getUsername() const
	{
		return User_name;
	}

	string getPassword() const
	{
		return User_pass;
	}

	string getRole() const
	{
		return User_role;
	}

	string getRace() const
	{
		return User_race;
	}

	void setUsername(char username[])
	{
		memcpy(this->User_name, username, 20);
	}

	void setPassword(char password[])
	{
		memcpy(this->User_pass, password, 20);
	}

	void setRole(char role[])
	{
		memcpy(this->User_role, role, 15);
	}

	void setRace(char race[])
	{
		memcpy(this->User_race, race, 15);
	}

	void getUser()
	{
		cout << "Please enter a username : ";
		cin >> User_name;
		cout << "Please enter a password :  ";
		cin >> User_pass;
		cout << "Please enter a role : ";
		cin >> User_role;
		cout << "Please enter a race : ";
		cin >> User_race;

	}
	void displayUser()
	{
		int Dist = 25;

		cout << setw(Dist) << "Username" << setw(Dist) << "Password" << setw(Dist) << "Role" << setw(Dist) << "Race" << endl;
		cout << setw(Dist) << User_name << setw(Dist) << User_pass << setw(Dist) << User_role << setw(Dist) << User_race << endl;
		cout << "\t\t===========================================================================================" << endl;
	}

	void displayUser_Basic()
	{
		int Dist = 25;

		cout << setw(Dist) << "Username" << setw(Dist) << "Password" << setw(Dist) << "Role" << setw(Dist) << "Race" << endl;
		cout << setw(Dist) << User_name << setw(Dist) << "     " << setw(Dist) << User_role << setw(Dist) << User_race << endl;
		cout << "\t\t===========================================================================================" << endl;
	}

};

