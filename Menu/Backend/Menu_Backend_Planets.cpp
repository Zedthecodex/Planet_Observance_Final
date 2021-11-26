#pragma once
#include <iostream>
#include <vector>
//#include "Planets.cpp"
//#include "Stations.cpp"
//#include "FileUtility.cpp"
#include "../../Planets_All/Planets.cpp"
#include "../../Stations/Stations.cpp"
#include "../../File_Utility/FileUtility.cpp"
#include <fstream>


class Menu_Backend_Planets : public Planets, Stations
{
private:

	FileUtility FileIO;
	Planets planet;

public:
	char name[20];
	double age;
	double radius;
	double size;
	//char age[10];
	//char radius[10];
	//string size;

	void viewPlanets() // Backend for Viewing Planets
	{
		system("cls");
		cout << "\t\t==================================Displaying Planets===================================" << endl;

		FileIO.OpenDatafromFile(PLANET);

		FileIO.ReadDataFromFile_Planet(planet);

		FileIO.CloseDataFromFile();


		cout << "\t\t=============================================================================================" << endl;


		/*Planets planet;

		ifstream fin;
		fin.open((PLANET), ios::in | ios::binary);

		while (fin.read((char*)&planet, sizeof(Planets))) {

			if (fin.eof())
			{
				break;
			}
			planet.displayPlanets();
		}*/

	}


	void AddPlanet() //Backend for Adding Planets
	{
		system("cls");
		cout << "\t\t==================================Planets Creation===================================" << endl;

		planet.getPlanet();

		FileIO.OpenDatatoFile(PLANET);
		FileIO.WriteDataToFile_Planet(planet);
		FileIO.CloseDatatoFile();

		FileIO.OpenDatatoFile("Planets_All\\Planets\\" + planet.getName() + "_Planet.dat");
		FileIO.WriteDataToFile_Planet(planet);
		FileIO.CloseDatatoFile();


		cout << "\t\t=============================================================================================" << endl;


		/*cout << "Name of Planet :" << endl;
		cin >> name;
		cout << "age of Planet : " << endl;
		cin >> age;
		cout << "radius of Planet :" << endl;
		cin >> radius;*/

		//size = (4 / 3) * 3.14 * radius * radius;

		/*Planets planet(name, age, radius);
		fstream fout;

		fout.open(PLANET, ios::out | ios::app | ios::binary);
		fout.write((char*)&planet, sizeof(Planets));
		fout.close();

		fout.open(("Planets_All\\Planets\\" + planet.getName() + "_planet.dat"), ios::out | ios::app | ios::binary);
		fout.write((char*)&planet, sizeof(Planets));
		fout.close();*/

	}

	void updatePlanet(string name) // Backend for updating Planets
	{

		system("cls");
		cout << "\t\t==================================Update Planet===================================" << endl;

		FileIO.OpenDatatoFile("Planets_All\\temp.dat");
		FileIO.OpenDatafromFile(PLANET);
		FileIO.UpdatePlanet(planet, name);
		FileIO.CloseDataFromFile();
		FileIO.CloseDatatoFile();
		FileIO.RenameRemovePlanet();

		cout << "\t\t=============================================================================================" << endl;

		/*fstream fio;
		Planets planet;

		fio.open(PLANET, ios::in | ios::out | ios::binary);
		if (!fio)
		{
			cerr << "File failed to open";
			exit(1);
		}
		while (fio.read((char*)&planet, sizeof(Planets)))
		{
			if (planet.getName() == name)
			{
				planet.getPlanet();
				int position = (-1) * static_cast<int>(sizeof(Planets));
				fio.seekp(position, ios::cur);
				fio.write((char*)&planet, sizeof(Planets));
				cout << "Planet updated" << endl;
				break;
			}
		}
		fio.close();

		fio.open(("Planets_All\\Planets\\" + planet.getName() + "_planet.dat"), ios::out | ios::app | ios::binary);
		if (!fio)
		{
			cerr << "File failed to open";
			exit(1);
		}
		while (fio.read((char*)&planet, sizeof(Planets)))
		{
			if (planet.getName() == name)
			{
				planet.getPlanet();
				int position = (-1) * static_cast<int>(sizeof(Planets));
				fio.seekp(position, ios::cur);
				fio.write((char*)&planet, sizeof(Planets));
				cout << "Planet updated" << endl;
				break;
			}
		}*/

	}

	void SearchPlanet(string name) //Backend for Planet searching
	{
		system("cls");
		cout << "\t\t==================================Search Planet=============================================" << endl;

		FileIO.OpenDatafromFile("Planets_All\\Planets\\" + planet.getName() + "_Planet.dat");
		FileIO.SearchPlanet(planet, name);
		FileIO.CloseDataFromFile();

		cout << "\t\t=============================================================================================" << endl;

	}

	void DeletePlanet(string name) //Backend for Deleting Planets
	{
		system("cls");
		cout << "\t\t==================================Delete Planet=============================================" << endl;

		FileIO.OpenDatatoFile("Planets_All\\temp.dat");
		FileIO.OpenDatafromFile(PLANET);
		FileIO.DeletePlanet(planet, name);
		FileIO.CloseDataFromFile();
		FileIO.CloseDatatoFile();
		FileIO.RenameRemovePlanet();

		cout << "\t\t=============================================================================================" << endl;


	}
};