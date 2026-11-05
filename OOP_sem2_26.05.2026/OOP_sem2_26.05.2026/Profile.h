#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::endl;
class Profile
{
private:
	string username;
public:
	Profile(const string& username);
	const string& getUsername() const;
	void setUsername(const string& un);

};

