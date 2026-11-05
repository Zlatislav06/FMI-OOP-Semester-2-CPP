#pragma once
#include "plot.h"

void free(char* n,Plot** p);
class Farmer
{
private:
	char* name = nullptr;
	size_t nameSize;
	Plot** plots = nullptr;
	size_t plotSize;
public:
	Farmer(Farmer& other);
	Farmer& operator=(const Farmer& F);
	~Farmer();
	Farmer(Farmer&& other);
	Farmer& operator=(const Farmer&& F);
	Farmer(char* ns,size_t n, Plot** p,size_t ps);
	void addPlot(Plot* plot);
	void printField();
};

