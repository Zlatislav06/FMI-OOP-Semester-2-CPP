#pragma once
#include "city.h"
enum Color
{
	RED,
	BLUE,
	GREEN,
	BROUWN
};
class Person
{
private:
	City birthplace;
	int age;
	Color eyeColor;
public:
	Person(char* n, long p, int a, Color e);
};