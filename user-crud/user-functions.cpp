#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>

#include "user-function.h"
#include "User.h"

using namespace std;

void write_user() {
	system("cls");

	int c;
	cout << "Press 1 ADD a user" << endl;
	cout << "Press 0 to GOT BACK" << endl;
	cout << "Choose youre option:  ";
	cin >> c;

	switch (c) {
	case 1: {
		User user;
		user.create_user();

		ofstream file;
		file.open("users.dat", ios::binary | ios::app);
		file.write((char*)&user, sizeof(user));
		file.close();

		system("cls");
		cout << "User has been added" << endl;
		break;
	}
	case 0:
		system("cls");
		break;
	default:
		system("cls");
		cout << "Please chose one of the given options" << endl;
		delete_user();
		break;
	}
}
void view_all_users() {
	system("cls");

	ifstream file;
	file.open("users.dat", ios::binary);

	User user;

	while (file.read((char*)&user, sizeof(user)))
	{
		user.get_data();
	}

	file.close();
}
void search_for_user() {
	system("cls");

	int suc = 0;
	char name[50];
	cout << "Search for user: ";
	cin >> name;

	User user;
	ifstream inFile;
	inFile.open("users.dat", ios::binary);

	while (inFile.read((char*)&user, sizeof(user)))
	{
		if (strcmp(user.get_name(), name) == 0) {
			cout << "USER FOUND: " << user.get_name() << endl;
			suc = 1;
		}
	}
	inFile.close();

	if (suc == 0) {
		system("cls");
		cout << "User NOT FOUD" << endl;
	}
}
void delete_all_users() {
	system("cls");

	int c;
	cout << "Press 1 DELETE ALL usres" << endl;
	cout << "Press 0 to GOT BACK" << endl;
	cout << "Choose youre option:  ";
	cin >> c;

	switch (c) {
	case 1: {
		remove("users.dat");
		ofstream newFile("users.dat", ios::binary);

		system("cls");
		cout << "All users successfuly deleted" << endl;
		break;
	}
	case 0:
		system("cls");
		break;
	default:
		system("cls");
		cout << "Please chose one of the given options" << endl;
		delete_user();
		break;
	}
}
void delete_user_by_id() {
	int suc = 0;
	int id;

	cout << "Enter user id to delete: ";
	cin >> id;

	ifstream inFile;
	ofstream outFile;

	inFile.open("users.dat", ios::binary);
	outFile.open("temp.dat", ios::binary);

	User user;

	while (inFile.read((char*)&user, sizeof(user)))
	{
		if (user.get_id() != id) {
			outFile.write((char*)&user, sizeof(user));
		}
		else {
			suc = 1;
		}
	}
	inFile.close();
	outFile.close();

	remove("users.dat");
	rename("temp.dat", "users.dat");

	switch (suc) {
	case 1:
		system("cls");
		cout << "User ussessfuly deleted" << endl;
		break;
	case 0:
		system("cls");
		cout << "User NOT FOUND" << endl;
		break;
	}
};
void delete_user() {
	system("cls");

	int c;
	cout << "Press 1 to delete by ID" << endl;
	cout << "Press 0 to GOT BACK" << endl;
	cout << "Choose youre option:  ";
	cin >> c;

	switch (c)
	{
	case 1:
		delete_user_by_id();
		break;
	case 0:
		system("cls");
		break;
	default:
		system("cls");
		cout << "Please chose one of the given options" << endl;
		delete_user();
		break;
	}
}
void update_user() {
    system("cls");
    view_all_users();

    int id;
    int success = 0;
    cout << "What is the ID of the user you want to update: ";
    cin >> id;

    fstream inFile;
    inFile.open("users.dat", ios::binary);

    if (!inFile.is_open()) {
        cout << "Error opening file." << endl;
        return; // Exit the function
    }

    User user;

    while (inFile.read((char*)&user, sizeof(user))) {
        cout << "User ID from file: " << user.get_id() << endl;
        cout << "ID you entered: " << id << endl;
        if (user.get_id() == id) {
            success = 1;
            cout << "Enter new user info: " << endl;
            user.create_user();

            int pos = -1 * sizeof(user);
            inFile.seekp(pos, ios::cur);

            inFile.write((char*)&user, sizeof(user));
            break; // Exit the loop once the user is updated
        }
    }

    if (!success) {
        cout << "No user with ID " << id << " found." << endl;
    }

    inFile.close(); // Close the file when done
}
