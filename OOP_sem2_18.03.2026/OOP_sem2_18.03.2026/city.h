#pragma once
class City
{
private:
	char* name=nullptr;
	long population;
public:
	City();
	City(char* n,long p);
	City(const City& C);
	City& operator=(const City& C);
	~City();
};