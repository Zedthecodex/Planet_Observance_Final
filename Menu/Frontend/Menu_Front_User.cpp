#pragma once

#include <iostream>
#include "../Backend/Menu_Backend_User.cpp"
using namespace std;


class Menu_User :public Menu_Backend_User
{
private:
	char username[20];

public:

	void Display_Classifier() // Front - End Display For Viewing Users (Full authenthication)
	{
		system("cls");


		viewUser();

		system("pause");;
	}

	void Add_Classifier() // Front - End Display for Adding Users
	{


		addUser();

		system("pause");
	}

	void Update_Classifier() // Front - End Display For Updating specific User
	{
		system("cls");

		viewUser();

		cout << "Enter username to update : " << endl;
		cin >> username;

		updateUser(username);

		system("pause");
	}

	void Search_Classifier() // Front - End Display For Searching Specific User
	{
		system("cls");

		cout << "Please enter a username to search : " << endl;
		cin >> username;

		searchUser(username);

		system("pause");
	}

	void Modify_Profile() // // Front - End Display For Modifying Profile
	{
		system("cls");

	/*	cout << "Please enter your username : " << endl;
		cin >> username;*/

		ModifyProfile();

		system("pause");
	}

	void Delete_Clasifier() // Front - End Display For User Deletion
	{
		system("cls");


		viewUser();

		cout << "Enter username to delete : " << endl;
		cin >> username;

		deleteUser(username);

		system("pause");
	}

	void Display_Navigator() // Front - End Display For Viewing Users(Basic~ No Password)
	{
		system("cls");

		viewUser_basic();

		system("pause");
	}




};