#include <iostream>
#include <string>
using namespace std;

#ifndef GALAXIES_CPP
#define GALAXIES_CPP



class Galaxies {
private:
	char name_field[20];
	double age_field;
	double radius_field;
	//double size_field;

public:
	//Default Constructor
	Galaxies() : name_field("Unknown"), age_field(0.00), radius_field(0.00) {}

	//Overloaded Constructor

	Galaxies(char name[], double age, double radius)
	{
		memcpy(this->name_field, name, 20);
		this->age_field = age;
		this->radius_field = radius;

	}

	//Accessor Functions

	string getName() const
	{
		return name_field;
	}

	double getage() const
	{
		return age_field;
	}

	double getRadius() const
	{
		return radius_field;
	}

	void setName(char name[])
	{
		memcpy(this->name_field, name, 20);

	}

	void setAge(double age)
	{
		this->age_field = age;
	}

	void setRadius(double radius)
	{
		this->radius_field = radius;
	}
};
#endif // !GALAXIES_CPP