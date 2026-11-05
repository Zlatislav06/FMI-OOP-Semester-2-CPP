#pragma once
class MyString
{
private:
	char* data;
	size_t length;
	size_t capacity;
public:
	MyString();
	MyString(const MyString& M);
	MyString& operator=(const MyString& M);
	MyString(char* d);
	size_t getLenght();
	void clear();
	char* setAt(size_t index,char ch);
	int find(char ch);
	void toUpper();
	void toLower();
	void erase(size_t index);
	void append(char* str);
	~MyString();
};