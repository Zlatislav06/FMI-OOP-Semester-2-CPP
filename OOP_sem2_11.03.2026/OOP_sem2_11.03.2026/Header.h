#pragma once
#include <iostream>
using namespace std;
class UserAccount
{
	string username;
	int id;
	int age;
public:
	UserAccount();
	UserAccount(string u,int i,int a);
	static int CountOfUsers();
	~UserAccount();
	UserAccount(UserAccount& A);
	UserAccount& operator=(const UserAccount&);


};