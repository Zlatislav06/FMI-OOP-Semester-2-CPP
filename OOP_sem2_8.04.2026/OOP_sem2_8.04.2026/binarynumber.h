#pragma once
#include <iostream>
#include <compare>
#include <cstring>
using std::string;
using std::cout;
using std::cin;
using std::endl;
class BinaryNumber
{
private:
	int* number = nullptr;
	size_t size;
public:
	BinaryNumber();
	BinaryNumber(int n);
	int* getNumber();
	size_t getSize();
	void setNumber(int* n);
	void setSize(size_t s);
	BinaryNumber(const BinaryNumber& B);
	BinaryNumber& operator=(const BinaryNumber& B);
	BinaryNumber(BinaryNumber&& other);
	void moveFrom(BinaryNumber&& B);
	BinaryNumber& operator=(BinaryNumber&& B);
	BinaryNumber& operator+=(const BinaryNumber& B);
	BinaryNumber operator+(const BinaryNumber& B);
	std::strong_ordering operator<=>(const BinaryNumber& B) const;
	~BinaryNumber();
};



