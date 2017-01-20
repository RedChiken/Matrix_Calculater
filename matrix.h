#pragma once
#include <iostream>
using namespace std;

class Matrix {
public:
	Matrix(const int cSize, const int rSize);
	Matrix(const Matrix &src);
	~Matrix();
	void setValue(int x, int y, int value) const;
	void setColumnValue(int x, int *column) const;
	void setRowValue(int y, int *row) const;
	void resize(int rSize);
	void printValue() const;

	const Matrix operator-() const;
	Matrix& operator++();
	Matrix operator++(int x);	
	Matrix& operator--();
	Matrix operator--(int x);
	Matrix& operator=(Matrix& mat);
	Matrix& operator+=(int x);
	Matrix& operator+=(Matrix mat);
	Matrix& operator-=(int x);
	Matrix& operator-=(Matrix mat);
	Matrix& operator*=(int x);
	Matrix& operator*=(Matrix mat);

	friend Matrix& operator+(Matrix& matrix, int i);
	friend Matrix& operator+(Matrix& matrix, Matrix mat);
	friend Matrix& operator-(Matrix& matrix, int i);
	friend Matrix& operator-(Matrix& matrix, Matrix mat);
	friend Matrix& operator*(Matrix& matrix, int i);
	friend Matrix& operator*(Matrix& matrix, Matrix mat);
	friend bool operator >(const Matrix& left, const Matrix& right);
	friend bool operator <(const Matrix& left, const Matrix& right);
	friend bool operator >=(const Matrix& left, const Matrix& right);
	friend bool operator <=(const Matrix& left, const Matrix& right);
	friend bool operator ==(const Matrix& left, const Matrix& right);
	friend bool operator !=(const Matrix& left, const Matrix& right);
	friend ostream& operator<<(ostream& ostr, const Matrix& src);
	friend istream& operator >> (istream& istr, Matrix& src);
private:
	volatile int columnSize, rowSize;
	int **matrix;
};

Matrix& operator+(Matrix& matrix, int i);
Matrix& operator+(Matrix& matrix, Matrix mat);
Matrix& operator-(Matrix& matrix, int i);
Matrix& operator-(Matrix& matrix, Matrix mat);
Matrix& operator*(Matrix& matrix, int i);
Matrix& operator*(Matrix& matrix, Matrix mat);
bool operator >(const Matrix& left, const Matrix& right);
bool operator <(const Matrix& left, const Matrix& right);
bool operator >=(const Matrix& left, const Matrix& right);
bool operator <=(const Matrix& left, const Matrix& right);
bool operator ==(const Matrix& left, const Matrix& right);
bool operator !=(const Matrix& left, const Matrix& right);
ostream& operator<<(ostream& ostr, const Matrix& src);
istream& operator >> (istream& istr, Matrix& src);