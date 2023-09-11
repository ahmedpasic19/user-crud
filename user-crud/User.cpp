#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;

void User::create_user() {
	cout << "Input usr name: ";
	cin >> name;
	id = rand();
}
void User::get_data() {
	cout << id << " " << name << endl;
}
int User::get_id() {
	return id;
}
const char* User::get_name() {
	return name;
}