#pragma once
#include "../Galaxies/Galaxies.cpp"

using namespace std;

class Stations : public Galaxies
{
private:
	char name_Stations[20];
	double age_Stations;
	double radius_Stations;
	double size_Stations;

public:

	//Default Constructor
	Stations() :name_Stations("Unknown"), age_Stations(0.00), radius_Stations(0.00) {}

	//Overloaded Constructor
	Stations(char name[], double age, double radius)
	{
		memcpy(this->name_Stations, name, 20);
		this->age_Stations = age;
		this->radius_Stations = radius;
		this->size_Stations = (4 / 3) * 3.14 * radius * radius;

	}

	double getSize()const
	{
		return size_Stations;
	}

	void setRadius(double radius)
	{
		this->radius_Stations = radius;
		this->size_Stations = (4 / 3) * 3.14 * radius * radius;
	}
};