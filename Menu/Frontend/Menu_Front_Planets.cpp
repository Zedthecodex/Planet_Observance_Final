#pragma once
#include <iostream>
#include "../Backend/Menu_Backend_Planets.cpp"
using namespace std;

class Menu_Planets : public Menu_Backend_Planets
{
private:
	char Planet_name[20];

public:

	void Add_Planet() // Front - End Display for Adding Planets
	{
		system("cls");

		AddPlanet();

		system("pause");
	}

	void Display_planet() //// Front - End Display for Viewing Planets
	{
		system("cls");

		viewPlanets();

		system("pause");

	}

	void Update_Planet() // // Front - End Display For Updating Planets
	{
		system("cls");

		viewPlanets();

		cout << "Please enter the name of the Planet needed Updating : ";
		cin >> Planet_name;
		updatePlanet(Planet_name);

		system("pause");
	}

	void Search_Planet() // Front - End Display For Searching Planets
	{
		system("cls");

		cout << "Please enter the name of Planet you are trying to find : ";
		cin >> Planet_name;
		SearchPlanet(Planet_name);

		system("pause");
	}

	void Delete_Planet() // Front - End Display For Planet Deletion
	{
		system("cls");

		viewPlanets();

		cout << "Please enter the name of the Planet you want deleted : ";
		cin >> Planet_name;
		DeletePlanet(Planet_name);

		system("pause");
	}
};