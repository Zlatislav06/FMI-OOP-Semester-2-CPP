#include <iostream>
#include "plot.h"
using std::cout;
int Plot::br = 0;
Plot::Plot()
{
	br++;
	id = br;
	width = 50;
	height = 50;
	cropType = NOTHING;
}
Plot::Plot(double w, double h, Crop c)
{
	br++;
	id = br;
	setWidth(w);
	setHeight(h);
	cropType = c;
}
int Plot::getId()
{
	return id;
}
double Plot::getWidth()
{
	return width;
}
double Plot::getHeight()
{
	return height;
}
Crop Plot::getCropType()
{
	return cropType;
}
void Plot::setWidth(double w)
{
	if (w <= 0)
	{
		cout << "Width must be more then zero!";
	}
	else
	{
		width = w;
	}
	
}
void Plot::setHeight(double h)
{
	if (h <= 0)
	{
		cout << "Height must be more then zero!";
	}
	else
	{
		height = h;
	}
}
void Plot::sow(Crop c)
{
	if (cropType == NOTHING)
	{
		cropType = c;
	}
	else
	{
		cout << "There is already a crop in this place.";
	}
	
}
void Plot::reap()
{
	cropType = NOTHING;
}