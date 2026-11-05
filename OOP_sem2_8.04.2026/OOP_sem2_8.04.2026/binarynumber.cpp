#include "binarynumber.h"
const int SIZE = 10;
void free(int* number)
{
	delete[] number;
	number = nullptr;
}
int* ReSize(int* number, size_t size, size_t new_size)
{
	if (size >= new_size)
	{
		return number;
	}
	else
	{
		
		int* newNumber = new int[new_size];
		for (int i = 0; i < size; i++)
		{
			newNumber[i] = number[i];
		}
		free(number);
		return newNumber;
	}
}
int Change(BinaryNumber& a,BinaryNumber& b)
{
	if (a.getSize() == b.getSize())
	{
	}
}
int min(size_t a, size_t b)
{
	if (a <b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
BinaryNumber::BinaryNumber()
{
	number = new int[SIZE];
	size = 0;
}
void BinaryNumber::setNumber(int* n)
{
	number = n;
}
void BinaryNumber::setSize(size_t s)
{
	if (s < 0)
	{
		cout << "It's imposible size to be less then zero! Size will be zero!";
		size = 0;
	}
	else
	{
		size = s;
	}
}
BinaryNumber::BinaryNumber(int n)
{
	setSize(n);
	number = new int[size];
	
}
int* BinaryNumber::getNumber()
{
	return number;
}
size_t BinaryNumber::getSize()
{
	return size;
}

BinaryNumber::BinaryNumber(const BinaryNumber& B)
{
	
		free(number);
		size = B.size;
		number = new int[size];
		for (int i = 0; i < size; i++)
		{
			number[i] = B.number[i];
		}

	
}
BinaryNumber& BinaryNumber::operator=(const BinaryNumber& B)
{
	if (this != &B)
	{
		free(number);
		size = B.size;
		number = new int[size];
		for (int i = 0; i < size; i++)
		{
			number[i] = B.number[i];
		}

	}
	return *this;
}
void BinaryNumber::moveFrom(BinaryNumber&& B)
{
	number = B.number;
	B.number = nullptr;
	size = B.size;
	B.size = 0;
}
BinaryNumber::BinaryNumber(BinaryNumber&& other)
{
	moveFrom(std::move(other));
}
BinaryNumber& BinaryNumber::operator=(BinaryNumber&& B)
{
	if (this != &B)
	{
		free(number);
		moveFrom(std::move(B));
	}
	return *this;
}
BinaryNumber& BinaryNumber::operator+=(const BinaryNumber& B)
{
	int minSize = min(size, B.size);
	int ostatak = 0;
	for (int i = 0; i < minSize; i++)
	{
		int n = number[i] + B.number[i];
		if (n == 2)
		{
			number[i] = ostatak;
			ostatak = 1;
			
		}
		else if(n == 1)
		{
			if (n + ostatak)
			{

			}
		}
	}
	
}
BinaryNumber BinaryNumber::operator+(const BinaryNumber& B)
{

}
std::strong_ordering BinaryNumber::operator<=>(const BinaryNumber& B) const
{

}
BinaryNumber::~BinaryNumber()
{

}