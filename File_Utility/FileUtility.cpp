#pragma once
#include <fstream>
#include <iostream>
//#include "User_Auth.cpp"
//#include "Accounts_All\User.cpp"
//#include "Planets_All\Planets.cpp"
//#include "Stations\Stations.cpp"
#include "../Accounts_All/User.cpp"
#include "../Planets_All/Planets.cpp"
#include "../Stations/Stations.cpp"

using namespace std;
const char USER[] = "Accounts_All\\Accounts.dat"; // The location for all saved accounts
const char PLANET[] = "Planets_All\\Planets.dat"; // The location for all saved planets


class FileUtility {

private:
	ofstream fout;
	ifstream fin;

	int count = 0;

public:

	void OpenDatatoLogin(string filename) // This seeks to create a temporary file of the account entered every login
	{
		fout.open(filename, ios::out | ios::app | ios::binary | ios::trunc);
		if (!fout)
		{
			cerr << "File failed to Open!" << endl;
			system("pause");
		}
	}
	void OpenDatatoFile(string filename) //Opens the file for additions or changes
	{
		fout.open(filename, ios::out | ios::app | ios::binary);
		if (!fout)
		{
			cerr << "File Failed to Open!" << endl;
			system("pause");

		}

	}

	void OpenDatafromFile(string filename) // Opening file for either extraction or reading
	{
		fin.open(filename, ios::in | ios::out | ios::binary);
		if (!fout)
		{
			cerr << "File Failed to Open!" << endl;
			system("pause");
		}
		fin.seekg(0, ios::beg);
	}

	void WriteDataToFile_User(User user) //Writing data to a specific file that was given from another method 
	{
		fout.write(reinterpret_cast<char*>(&user), sizeof(User)); // for saving to void WriteDataToFile
	}

	void ReadDataFromFile_User(User user) // This extracts the specific information of each user
	{
		while (1)
		{
			fin.read(reinterpret_cast<char*>(&user), sizeof(User));
			if (fin.eof()) { break; }
			user.displayUser();
			cout << endl;
		}


	}

	void ReadDataFromFile_User_Basic(User user) // This extracts all information except the password of users
	{
		while (1)
		{
			fin.read(reinterpret_cast<char*>(&user), sizeof(User));
			if (fin.eof()) { break; }
			user.displayUser_Basic();
			cout << endl;
		}
	}


	void UpdateUser(User user, string username) // This Updates the inputted account name 
	{
		count = 0;
		fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&user), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (user.getUsername() != username)
			{
				WriteDataToFile_User(user);
			}
			else
			{
				user.getUser();
				WriteDataToFile_User(user);
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Account not found" << endl;

		}
	}

	void DeleteUser(User user, string username)// This Deletes the inputted account name
	{
		count = 0;
		while (fin.read(reinterpret_cast<char*>(&user), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (user.getUsername() != username)
			{
				WriteDataToFile_User(user);
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t Account Not found " << endl;

		}
		else
		{
			cout << "\t\t\t User Deleted " << endl;
		}

	}

	void SearchUser(User user, string username) // This searches and display a specific account
	{
		count = 0;
		while (fin.read(reinterpret_cast<char*>(&user), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (user.getUsername() == username)
			{
				user.displayUser();
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t Account Not found " << endl;

		}

	}

	void WriteDataToFile_Planet(Planets planet) // This will write the given information for Planets
	{
		fout.write(reinterpret_cast<char*>(&planet), sizeof(Planets));

	}

	void UpdatePlanet(Planets planet, string planet_name) // This will Update a specific Planet information
	{
		fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&planet), sizeof(Planets)))
		{
			if (fin.eof()) { break; }
			if (planet.getName() != planet_name)
			{
				fout.write(reinterpret_cast<char*>(&planet), sizeof(Planets));

			}
			else
			{
				planet.getPlanet();
				fout.write(reinterpret_cast<char*>(&planet), sizeof(Planets));
			}
		}
	}

	void ReadDataFromFile_Planet(Planets planet) // This will Read and Display all Planets and its informations
	{
		count = 0;
		while (1)
		{
			fin.read(reinterpret_cast<char*>(&planet), sizeof(Planets));
			if (fin.eof()) { break; }
			planet.displayPlanets();
			count++;
		}

	}

	void DeletePlanet(Planets planet, string planet_name)// This will Delete the inputted Planet
	{
		count = 0;
		while (fin.read(reinterpret_cast<char*>(&planet), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (planet.getName() != planet_name)
			{
				WriteDataToFile_Planet(planet);
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t Account Not found " << endl;

		}
		else
		{
			cout << "\t\t\t User Deleted " << endl;
		}
		/*fin.seekg(0, ios::beg);
		while (fin.read(reinterpret_cast<char*>(&planet), sizeof(Planets)))
		{
			if (fin.eof()) { break; }
			if (planet.getName() != planet_name)
			{
				fout.write(reinterpret_cast<char*>(&planet), sizeof(Planets));
			}
		}*/
	}

	void SearchPlanet(Planets planet, string planet_name) // This will Search and Display a Planet and its information
	{
		count = 0;
		while (fin.read(reinterpret_cast<char*>(&planet), sizeof(User)))
		{
			if (fin.eof()) { break; }
			if (planet.getName() == planet_name)
			{
				planet.displayPlanets();
			}
			else
			{
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\t\t\t Account Not found " << endl;

		}

	}

	/*void ModifyUser(User user)
	{
		

	}*/

	void RenameRemoveUser() //This will create a temp file that will update the current Accounts file with new information
	{
		int res = 0;
		if (remove(USER) != 0)
		{
			cout << "Failed to remove file!" << endl;
		}

		res = rename("Accounts_All\\temp.dat", USER);
		if (res == 0)
		{
			cout << "File Updated!" << endl;
		}
		else
		{
			cout << "Failed to rename file" << endl;
		}
	}

	void RenameRemovePlanet() // This will create a temp file that will update the current Planets file with new information
	{
		int removeStatus = 0;
		if (remove(PLANET) == 0)
		{
			//cout << "Failed to remove!" << endl;
			cout << "Success remove!" << endl;
		}
		else
		{
			cout << "Failed to remove!!!" << endl;
		}

		int renameStatus;
		renameStatus = rename("Planets_All\\temp.dat", PLANET);
		if (renameStatus == 0)
		{
			cout << "Success renamed!" << endl;
		}
		else
		{
			cout << "Failed to rename!" << endl;
		}
	}

	void CloseDatatoFile() //Closes the toFile that was opened
	{
		fout.close();
	}

	void CloseDataFromFile() //Closes the FromFile that was opened
	{
		fin.close();
	}
};