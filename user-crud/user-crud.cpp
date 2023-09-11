
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>

#include "User.h"
#include "user-function.h"

using namespace std;

int main()
{
	bool running = true;

	cout << "\t\t\t____________________________________________________________________" << endl;
	cout << "\t\t\t_______________Welcome to my User CRUD application__________________" << endl;
	cout << "\t\t\t____________________________________________________________________" << endl;

	while (running)
	{
		int c;

		cout << "Navigation Menu: " << endl;
		cout << "\t| Press 1 to VIEW ALL users         |" << endl;
		cout << "\t| Press 2 to ADD a new user         |" << endl;
		cout << "\t| Press 3 to UPATE a user           |" << endl;
		cout << "\t| Press 4 to DELETE a user          |" << endl;
		cout << "\t| Press 5 to DELETE ALL a users     |" << endl;
		cout << "\t| Press 6 to SEARCH for a user      |" << endl;
		cout << "\t| Press 0 to EXIT				   |" << endl;
		cout << "Choose youre option: (1-6) ";
		cin >> c;

		switch (c) {
		case 1:
			view_all_users();
			break;
		case 2:
			write_user();
			break;
		case 3:
			update_user();
			break;
		case 4:
			delete_user();
			break;
		case 5:
			delete_all_users();
			break;
		case 6:
			search_for_user();
			break;
		case 0:
			cout << "Press any key to close the application" << endl;
			running = false;
			break;
		default:
			cout << "Plase chose one of the options: " << endl;
			main();
		}
	}
}

