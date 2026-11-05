#pragma once
class Matrix
{
private:
	int** data = nullptr;
	int row;
	int column;
public:

	Matrix();
	Matrix(int _r, int _c, int* arr);
	Matrix(const Matrix& m);
	Matrix& operator =(const Matrix& m);
	void setValue(int _r, int _c, int val);
	void printMatrix();
	~Matrix();

};