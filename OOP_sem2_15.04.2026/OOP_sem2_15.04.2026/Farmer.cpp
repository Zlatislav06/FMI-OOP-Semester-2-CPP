#include "Farmer.h"
void free(char* n, Plot** p,int size)
{
	delete[] n;
	for (int i = 0; i < size; i++)
	{
		delete[] p[i];
	}
	delete[] p;
}
Farmer::Farmer(Farmer& other)
{
	free(name, plots, plotSize);
	nameSize = other.nameSize;
	name = new char[nameSize];
	for (int i = 0; i <nameSize; i++)
	{
		name[i] = other.name[i];
	}

}
Farmer& Farmer::operator=(const Farmer& F)
{

}
Farmer::~Farmer()
{

}
Farmer::Farmer(Farmer&& other)
{

}
Farmer& Farmer::operator=(const Farmer&& F)
{

}
Farmer::Farmer(char* ns, size_t n, Plot** p, size_t ps)
{

}
void Farmer::addPlot(Plot* plot)
{

}
void Farmer::printField()
{

}