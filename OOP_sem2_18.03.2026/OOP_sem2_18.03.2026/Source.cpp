#include <iostream>
#include "Header.h"
#include "city.h"
#include "Person.h"
#include "mystring.h"
using std::cout;
using std::endl;
#define printel cout<<data[i][j]<<" ";
#define print cout<<endl;
const int SIZE = 10;
//zad1

int Min(int a,int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
void free(int** data,int size)
{

	for (int i = 0; i < size; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}
Matrix::Matrix()
{
		data =new int*[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			data[i] = new int[SIZE];
		}
		row = SIZE;
		column = SIZE;
}
Matrix::Matrix(int _r,int _c,int* arr)
{
		row = _r;
		column = _c;
		data = new int* [column];
		int index = 0;
		for (int i = 0; i < column; i++)
		{
			data[i] = new int[row];
		}
		for (int i = 0; i < column; i++)
		{
			for (int j = 0; j < row; j++)
			{
				
				data[i][j] = arr[i + j+index];

			}
			index += row-1;
		}
}
Matrix::Matrix(const Matrix& m)
{
		row = m.row;
		column = m.column;
		data = new int* [column];
		for (int i = 0; i < column; i++)
		{
			data[i] = new int[row];
		}
		for (int i = 0; i < m.column; i++)
		{
			for (int j = 0; j <  m.row; j++)
			{
				data[i][j] = m.data[i][j];
			}
		}
}
Matrix& Matrix::operator =(const Matrix& m)
{
	if (this != &m)
	{
		free(data, column);
		row = m.row;
		column = m.column;
		data = new int* [column];
		for (int i = 0; i < column; i++)
		{
			data[i] = new int[row];
		}
		for (int i = 0; i < m.column; i++)
		{
			for (int j = 0; j < m.row; j++)
			{
				data[i][j] = m.data[i][j];
			}
		}
	}
	return *this;
}
void Matrix::setValue(int _r, int _c, int val)
{
		data[_r][_c] = val;
}
void Matrix::printMatrix()
{
		for (int i = 0; i < column; i++)
		{
			for (int j = 0; j < row; j++)
			{
				printel;
			}
			print;
		}
}
Matrix::~Matrix()
{
	
	free(data, column);
}
//zad2
City::City()
{
	name=nullptr;
	population = 0;
}
City::City(char* n, long p)
{
	int size = 0;
	while (n[size] != '\0')
	{
		size++;
	}
	name = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		name[i] = n[i];
	}
	population = p;
}
City::City(const City& C)
{
	int size = 0;
	while (C.name[size] != '\0')
	{
		size++;
	}
	delete[] name;
	name = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		name[i] = C.name[i];
	}
	
	population = C.population;
}
City& City::operator=(const City& C)
{
	int size = 0;
	while (C.name[size] != '\0')
	{
		size++;
	}
	delete[] name;
	name = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		name[i] = C.name[i];
	}
	
	population = C.population;
	return *this;
}
City::~City()
{
	delete[] name;
}
Person::Person(char* n, long p, int a, Color e)
{
	City c1 = { n,p };
	birthplace = c1;
	age = a;
	eyeColor = e;

}
//zad3

int main()
{
	int a[] = { 1,2,3,4,5,6 };
	int b[] = { 1,2,3,4,5,6,7,8 };
	char c[] = "fpwfwpf";
	Matrix m1 = { 3,2,a };
	Matrix m2 = { 4,2,b };
	m1 = m2;
	m1.printMatrix();
	Person p1 = { c,123231,5,RED };
	Person p2= { c,123231,5,GREEN };
	p1={ p2 };
	return 0;
}