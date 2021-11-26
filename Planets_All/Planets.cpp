#include <iostream>
#include "../Galaxies/Galaxies.cpp"
#include <iomanip>
#include <string>

using namespace std;
#ifndef PLANETS_CPP
#define PLANETS_CPP


class Planets : public Galaxies
{
private:
	char name_Planets[20];
	double age_Planets;
	double radius_Planets;
	double size_Planets;

public:
	//Default Constructor
	Planets() : name_Planets("Unknown"), age_Planets(0.00), radius_Planets(0.00) {}

	//Overloaded Constructor
	Planets(char name[], double age, double radius)
	{
		memcpy(name_Planets, name, 20);
		this->age_Planets = age;
		this->radius_Planets = radius;
		this->size_Planets = (4 / 3) * 3.14 * radius * radius;
	}

	string getName() const
	{
		return name_Planets;
	}

	double getSize() const
	{
		return size_Planets;
	}

	void setRadius(double radius)
	{
		this->radius_Planets = radius;
		this->size_Planets = (4 / 3) * 3.14 * radius * radius;
	}

	void getPlanet()
	{
		system("cls");
		cout << "Please Fulfill the following: " << endl;
		cout << "Name of Planet : " << endl;
		cin >> name_Planets;
		cout << "Age of Planet (In millions) : " << endl;
		cin >> age_Planets;
		cout << "Radius of the Planet(in Km):  " << endl;
		cin >> radius_Planets;
		size_Planets = (4 / 3) * 3.14 * radius_Planets * radius_Planets;
	}

	void displayPlanets()
	{

		int Dist = 25;
		cout << "\t\t\t================================" << endl;
		cout << setw(Dist) << "Name" << setw(Dist) << "Age (Millions)" << setw(Dist) << "Radius (Km)" << setw(Dist) << "Size (Km^2)" << endl;
		cout << setw(Dist) << name_Planets << setw(Dist) << age_Planets << setw(Dist) << radius_Planets << setw(Dist) << fixed << size_Planets << endl;
	}
};

#endif // !PLANETS_CPP