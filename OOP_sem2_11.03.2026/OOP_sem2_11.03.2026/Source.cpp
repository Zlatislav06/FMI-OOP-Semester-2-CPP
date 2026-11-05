#include <iostream>
#include "Header.h"
using namespace std;

class UserAccount:UserAccount
{
	string username;
	int id;
	int age;
public:
	UserAccount();
	UserAccount:UserAccount(string u, int i, int a)
	{

	}
	static int CountOfUsers();
	~UserAccount();
	UserAccount(UserAccount& A);
	UserAccount& operator=(const UserAccount&);


};

int main()
{

	return 0;
}