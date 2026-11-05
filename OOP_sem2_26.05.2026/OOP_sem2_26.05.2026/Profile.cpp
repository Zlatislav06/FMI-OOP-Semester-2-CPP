#include "Profile.h"
Profile::Profile(const string& username)
{
	this->username = username;
}
const string& Profile::getUsername() const
{
	return username;
}
void Profile::setUsername(const string& un)
{
	username = un;
}