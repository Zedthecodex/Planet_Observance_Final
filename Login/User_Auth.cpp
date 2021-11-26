#pragma once

#include <iostream>
#include "../Accounts_All/User.cpp"
#include <fstream>
#include "../File_Utility/FileUtility.cpp"



using namespace std;

class User_auth 
{
private:
	User user;
	FileUtility FileIO;
	int Privilege = 0;


public:
	

	void checkVector(User& user_login) // A Checking of Authentication on Whether the Inputted Login Credentials is correct and giving Privileges
	{
		
		User user;
		ofstream fout;

		ifstream fin;

		/*	fout.open(("Accounts\\" + user_login.getUsername() + "_Acc.dat"), ios::out | ios::app | ios::binary);
			fout.write("");
			fout.close();*/

		fin.open(("Accounts\\" + user_login.getUsername() + "_Acc.dat"), ios::in | ios::binary);
		
		if (!fin)
		{
			cerr << "That Username does not exist" << endl;
			exit(1);
		}

		while (fin.read((char*)&user, sizeof(user)))
		{
			//cout << user.getUsername() << endl;

			if (user_login.getPassword() == user.getPassword())
			{
				if (user.getRole() == "Classifier")
				{
					setPrivilege(2);
					//cout << "You are in!" << endl;
					cout << "You are in as a classifier " << endl;

				}
				else
				{
					setPrivilege(1);
					cout << "You are in as a basic User" << endl;
				}
			}
			else if (user_login.getPassword() != user.getPassword())
			{
				cout << "Password doesn't match the preset. Please try again" << endl;
			}

		
		}
		// This Part Creates the temp file needed for Profile Modification (Not usable yet)
		FileIO.OpenDatatoFile("Login\\temp.dat");
		FileIO.WriteDataToFile_User(user_login);
		FileIO.CloseDatatoFile();
		//
	}
	int getPrivilege() // Getting Privileges
	{
		return Privilege;
	}

	void setPrivilege(int privilege)
	{
		this->Privilege = privilege;
	}

};






