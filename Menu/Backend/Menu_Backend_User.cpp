#pragma once
#include <iostream>
//#include "User_Auth.cpp"
//#include "FileUtility.cpp"

#include "../../Login/User_Auth.cpp"
#include "../../File_Utility/FileUtility.cpp"
using namespace std;


class Menu_Backend_User :public User_auth
{
private:
	//User user;
	FileUtility FileIO;
public:
	char Username[20];
	char Password[20];
	char role[15];
	char race[15];
	double size;
	int Privilege;

	int login_Menu_Back()// Back - End For Login and Authentication
	{
		system("cls");
		cout << "\t\t\t==========Login==========" << endl;
		cout << "Username : " << endl;
		cin >> Username;
		cout << "Password : " << endl;
		cin >> Password;
		cout << "Role : " << endl;
		cin >> role;
		cout << "Race : " << endl;
		cin >> race;

		User user1(Username, Password, role, race);
		User_auth user_auth1;

		user_auth1.checkVector(user1);
		/*cout << user_auth1.getPrivilege() << endl;
		setPrivilege(user_auth1.getPrivilege());*/
		FileIO.OpenDatatoFile("Login\\temp.dat");
		FileIO.WriteDataToFile_User(user1);
		FileIO.CloseDatatoFile();

		return user_auth1.getPrivilege();

	}



	void addUser() //Back-End for Adding Accounts
	{
		system("cls");
		cout << "\t\t==================================Account Creation============================================" << endl;

		User user;

		user.getUser();

		FileIO.OpenDatatoFile(USER);
		FileIO.WriteDataToFile_User(user);
		FileIO.CloseDatatoFile();

		FileIO.OpenDatatoFile("Accounts\\" + user.getUsername() + "_Acc.dat");
		FileIO.WriteDataToFile_User(user);
		FileIO.CloseDatatoFile();

		cout << "\t\t=============================================================================================" << endl;


	}

	void viewUser() // Back-End  For Viewing Users
	{
		system("cls");
		cout << "\t\t==================================Display User=============================================" << endl;
		User user;


		FileIO.OpenDatafromFile(USER);
		//FileIO.ReadDataFromFile_User(user);
		FileIO.ReadDataFromFile_User(user);
		FileIO.CloseDataFromFile();

		cout << "\t\t===========================================================================================" << endl;

	}

	void viewUser_basic() //Back-End For Basic User Viewing ( No password Display)
	{
		system("cls");
		cout << "\t\t==================================Display User=============================================" << endl;
		User user;


		FileIO.OpenDatafromFile(USER);
		FileIO.ReadDataFromFile_User_Basic(user);
		FileIO.CloseDataFromFile();

		cout << "\t\t===========================================================================================" << endl;
	}

	void updateUser(string name) // Back-End For Updating User
	{
		system("cls");
		cout << "\t\t==================================Update User=============================================" << endl;
		User user;


		FileIO.OpenDatatoFile("Accounts_All\\temp.dat");
		FileIO.OpenDatafromFile(USER);
		FileIO.UpdateUser(user, name);
		FileIO.CloseDataFromFile();
		FileIO.CloseDatatoFile();
		FileIO.RenameRemoveUser();

		cout << "\t\t===========================================================================================" << endl;


	}


	void searchUser(string name) // Back-End for Searching User
	{
		system("cls");
		cout << "\t\t==================================Search User=============================================" << endl;
		User user;



		FileIO.OpenDatafromFile(USER);
		FileIO.SearchUser(user, name);
		FileIO.CloseDataFromFile();

		cout << "\t\t==========================================================================================" << endl;

	}

	void deleteUser(string name) // Back-End for User Deletion
	{
		system("cls");
		cout << "\t\t==================================Delete User=============================================" << endl;
		User user;


		FileIO.OpenDatatoFile("Accounts_All\\temp.dat");
		FileIO.OpenDatafromFile(USER);
		FileIO.DeleteUser(user, name);
		FileIO.CloseDataFromFile();
		FileIO.CloseDatatoFile();
		FileIO.RenameRemoveUser();

		cout << "\t\t==========================================================================================" << endl;

	}

	void ModifyProfile() // Back-End For Modifying Profiles ( only your account)
	{
		User user_owner;
		User user;

		FileIO.OpenDatafromFile("Login\\temp.dat");
		FileIO.ReadDataFromFile_User(user_owner);
		FileIO.CloseDataFromFile();
		cout << "This is your account, press any key to modify." << endl;
		string name = user_owner.getUsername();
		cout << name << endl;
		system("pause");

		updateUser(name);

	}

	//void RenameUser()
	//{
	//	int removeStatus = 0;
	//	if (remove(USER) != 0)
	//	{
	//		//cerr << "Failed to remove the file! " << endl;

	//	}
	//	removeStatus = rename("temp.dat", USER);
	//	if (removeStatus == 0)
	//	{
	//		cout << "Deletion Succeeded" << endl;
	//	}
	//	else
	//	{
	//		cout << "Deletion Failed " << endl;
	//	}

	//}



	//int getPrivilege()
	//{
	//	return Privilege;
	//}
	//void setPrivilege(int privilege)
	//{
	//	this->Privilege = privilege;
	//}
};