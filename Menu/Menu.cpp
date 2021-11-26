#include <iostream>
#include <vector>
//#include "Menu_Backend_User.cpp"
//#include "Menu_Backend_Planets.cpp"
//#include "Menu_Front_Planets.cpp"
//#include "Menu_Front_User.cpp"
#include "Frontend/Menu_Front_Planets.cpp"
#include "Frontend/Menu_Front_User.cpp"

using namespace std;

class Menu :public Menu_User, Menu_Planets
{
private:
	int Choice = 0;
	int Privilege = 0;
	char username[20];
public:


	void login_Menu() // The Starting Login Menu
	{
		system("cls");
		cout << "\t\t\t==========Login==========" << endl;
		cout << "\n\n" << "\t\t\t1).Login " << endl;
		cout << "\t\t\t2).Exit " << endl;
		cout << "\n\n\t\t\t=========================" << endl;
		cin >> Choice;
		switch (Choice)
		{
		case 1:

			Privilege = login_Menu_Back();  // This is used to check for admin or user privileges
			//cout << "You are in!" << endl;
			main_Menu(Privilege);

			break;

		case 2:
			cout << "Exiting....." << endl;
			exit(0);
			break;

		default:
			system("cls");
			cout << "Please choose between the choices given" << endl;
			system("pause");
			login_Menu();
			break;
		}

	}

	void main_Menu(int& Privilege) // The Main menu that moves to either Classifier account , or Navigator account ( updates coming soon...)
	{
		cout << "You are now in the menu" << endl;
		if (Privilege == 2)
		{
			cout << "This is a classifier privileged account " << endl;
			system("pause");
			main_Menu_Classifier();
		}
		else if (Privilege == 1)
		{
			system("pause");
			cout << "This is a basic User account" << endl;
			main_Menu_Basic();
		}
	}

	void main_Menu_Classifier() // The Main Classifier Menu
	{
		system("cls");
		cout << "\t\t\t==========Classifier Account==========" << endl;
		cout << "\n\n\t\t\t 1).Manage Users" << endl;
		cout << "\t\t\t 2).Manage Planets" << endl;
		cout << "\t\t\t 3).Modify Profile" << endl;
		cout << "\t\t\t 4).Sign Out and Exit" << endl;
		cout << "\n\n\t\t\t======================================" << endl;
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			menu_User_Manager();
			break;

		case 2:
			menu_Planets_Manager();
			break;

		case 3:

			Modify_Profile();
			
			main_Menu_Classifier();
			break;

		case 4:

			remove("Login\\temp.dat");

			login_Menu();

			break;

		default:
			main_Menu_Classifier();
			break;

		}

	}

	void menu_User_Manager() // The Menu for Managing Users
	{
		system("cls");
		cout << "\t\t=========================User Management=========================" << endl;
		cout << "\n\n\t\t\t 1).View Users" << endl;
		cout << "\t\t\t 2).Add Users" << endl;
		cout << "\t\t\t 3).Update Users" << endl;
		cout << "\t\t\t 4).Search User" << endl;
		cout << "\t\t\t 5).Delete User" << endl;
		cout << "\t\t\t 6).Go back " << endl;
		cout << "\n\n\t\t=================================================================" << endl;
		cin >> Choice;

		switch (Choice)
		{
		case 1:

			Display_Classifier();

			menu_User_Manager();
			break;

		case 2:

			Add_Classifier();

			menu_User_Manager();
			break;

		case 3:

			Update_Classifier();

			menu_User_Manager();
			break;

		case 4:

			Search_Classifier();

			menu_User_Manager();
			break;

		case 5:

			Delete_Clasifier();

			menu_User_Manager();
			break;

		case 6:

			main_Menu_Classifier();
			break;

		}


	}

	void menu_Planets_Manager() // The Menu For Planets Management
	{
		system("cls");
		cout << "\t\t=========================Planets Management=========================" << endl;
		cout << "\n\n\t\t\t 1).View Planets" << endl;
		cout << "\t\t\t 2).Add Planets" << endl;
		cout << "\t\t\t 3).Update Planet" << endl;
		cout << "\t\t\t 4).Search Planet" << endl;
		cout << "\t\t\t 5).Delete Planet" << endl;
		cout << "\t\t\t 6).Go back " << endl;
		cout << "\n\n\t\t=================================================================" << endl;
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			Display_planet();

			menu_Planets_Manager();
			break;
		case 2:
			AddPlanet();

			menu_Planets_Manager();
			break;
		case 3:
			Update_Planet();

			menu_Planets_Manager();
			break;
		case 4:
			Search_Planet();

			menu_Planets_Manager();
			break;
		case 5:
			Delete_Planet();

			menu_Planets_Manager();
			break;
		case 6:
			main_Menu_Classifier();
			break;

		default:
			menu_Planets_Manager();
			break;
		}

	}
	void main_Menu_Basic() // The Menu for the Navigator, Guests or any form of basic Accounts
	{
		system("cls");
		cout << "\t\t\t==========Navigator Account==========" << endl;
		cout << "\n\n\t\t\t 1).View Users" << endl;
		cout << "\t\t\t 2).View Planets" << endl;
		cout << "\t\t\t 3).Modify Profile" << endl;
		cout << "\t\t\t 4).Sign Out and Exit" << endl;
		cout << "\n\n\t\t\t======================================" << endl;
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			viewUser_basic();

			system("pause");

			main_Menu_Basic();
			break;

		case 2:
			displayPlanets();

			system("pause");

			main_Menu_Basic();
			break;

		case 3:

			Modify_Profile();

			system("pause");

			main_Menu_Basic();
			break;

		case 4:

			login_Menu();

			break;
		}


	}

};