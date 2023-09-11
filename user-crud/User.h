#ifndef USER_H
#define USER_H

class User {
private:
	int id;
	char name[50];
public:
	void create_user();
	void get_data();
	int get_id();
	const char* get_name();
};

#endif