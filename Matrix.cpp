#include "matrix.h"
#include <iostream>

Matrix::Matrix(const int x, const int y):columnSize(x), rowSize(y) {
	matrix = new int*[columnSize];
	for (int i = 0; i < columnSize; i++) {
		matrix[i] = new int[rowSize];
		for (int j = 0; j < rowSize; j++) {
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix & src) : columnSize(src.columnSize), rowSize(src.rowSize)
{
	this->matrix = new int*[columnSize];
	for (int i = 0; i < columnSize; i++) {
		this->matrix[i] = new int[rowSize];
		for (int j = 0; j < rowSize; j++) {
			this->matrix[i][j] = src.matrix[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < columnSize; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::setValue(int column, int row, int value) const{
	this->matrix[column][row] = value;
}

void Matrix::setColumnValue(int x, int *column) const {
	for (int i = 0; i < columnSize; i++) {
		matrix[i][x] = column[i];
	}
}

void Matrix::setRowValue(int y, int *row) const {
	for (int i = 0; i < rowSize; i++) {
		matrix[y][i] = row[i];
	}
}

void Matrix::resize(int rSize)
{
	this->rowSize = rSize;
	for (int i = 0; i < columnSize; i++) {
		delete this->matrix[i];
		matrix[i] = new int[this->rowSize];
		for (int j = 0; j < rowSize; j++) {
			this->matrix[i][j] = 0;
		}
	}
}

void Matrix::printValue() const {
	for (int i = 0; i < columnSize; i++) {
		for (int j = 0; j < rowSize; j++) {
			std::cout << matrix[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

const Matrix Matrix::operator-() const
{
	for (int i = 0; i < this->columnSize; i++) {
		for (int j = 0; j < this->rowSize; j++) {
			this->matrix[i][j] *= -1;
		}
	}
	return *this;
}

Matrix & Matrix::operator++()
{
	for (int i = 0; i < this->columnSize; i++) {
		for (int j = 0; j < this->rowSize; j++) {
			this->matrix[i][j]++;
		}
	}
	return (*this);
}

Matrix Matrix::operator++(int)
{
	Matrix oldMatrix(*this);
	++(*this);
	return oldMatrix;
}

Matrix& Matrix::operator--()
{
	for (int i = 0; i < this->columnSize; i++) {
		for (int j = 0; j < this->rowSize; j++) {
			this->matrix[i][j]--;
		}
	}
	return (*this);
}

Matrix Matrix::operator--(int)
{
	Matrix oldMatrix(*this);
	--(*this);
	return oldMatrix;
}

Matrix& Matrix::operator=(Matrix &)
{
	Matrix *newObj = new Matrix(this->columnSize, this->rowSize);
	for (int i = 0; i < columnSize; i++) {
		for (int j = 0; j < rowSize; j++) {
			newObj->setValue(i, j, this->matrix[i][j]);
		}
	}
	return *newObj;
}

Matrix& Matrix::operator+=(int x)
{
	for (auto i = 0; i < this->columnSize; i++) {
		for (auto j = 0; j < this->rowSize; j++) {
			this->matrix[i][j] += x;
		}
	}
	return (*this);
}

Matrix& Matrix::operator+=(Matrix mat)
{
	for (auto i = 0; i < this->columnSize; i++) {
		for (auto j = 0; j < this->rowSize; j++) {
			this->matrix[i][j] += mat.matrix[i][j];
		}
	}
	return (*this);
}

Matrix& Matrix::operator-=(int x)
{
	(*this) += (-1 * x);
	return (*this);
}

Matrix& Matrix::operator-=(Matrix mat)
{
	(*this) += (mat * -1);
	return (*this);
}

Matrix & Matrix::operator*=(int x)
{
	for (auto i = 0; i < this->columnSize; i++) {
		for (auto j = 0; j < this->rowSize; j++) {
			this->matrix[i][j] *= x;
		}
	}
	return (*this);
}

Matrix & Matrix::operator*=(Matrix mat)
{
	Matrix old(*this);
	this->resize(mat.rowSize);
	for (auto i = 0; i < this->columnSize; i++) {
		for (auto j = 0; j < mat.rowSize; j++) {
			int temp = 0;
			for (auto k = 0; k < mat.columnSize; k++) {
				temp += (old.matrix[i][k] * mat.matrix[k][j]);
			}
			this->setValue(i, j, temp);
		}
	}
	return (*this);
}

Matrix& operator+(Matrix & mat, const int x)
{
	Matrix *newmat = new Matrix(mat);
	*newmat += x;
	return (*newmat);
}

Matrix& operator+(Matrix & mat1, Matrix mat2)
{
	Matrix *mat = new Matrix(mat1);
	*mat += mat2;
	return (*mat);
}

Matrix& operator-(Matrix & matr, int i)
{
	Matrix *mat = new Matrix(matr);
	*mat += (-1 * i);
	return (*mat);
}

Matrix& operator-(Matrix & matr, Matrix mat2)
{
	Matrix *mat = new Matrix(matr);
	*mat += (mat2 * -1);
	return (*mat);
}

Matrix & operator*(Matrix & mat, int x)
{
	Matrix *nMat = new Matrix(mat);
	(*nMat) *= x;
	return (*nMat);
}

Matrix & operator*(Matrix & matrix, Matrix mat)
{
	Matrix *nMat = new Matrix(matrix);
	(*nMat) *= mat;
	return (*nMat);
}

bool operator>(const Matrix & left, const Matrix & right)
{
	return false;
}

bool operator<(const Matrix & left, const Matrix & right)
{
	return false;
}

bool operator>=(const Matrix & left, const Matrix & right)
{
	return false;
}

bool operator<=(const Matrix & left, const Matrix & right)
{
	return false;
}

bool operator==(const Matrix & left, const Matrix & right)
{
	return false;
}

bool operator!=(const Matrix & left, const Matrix & right)
{
	return false;
}

ostream & operator<<(ostream & ostr, const Matrix & src)
{
	// TODO: insert return statement here
	return ostr;
}

istream & operator >> (istream & istr, Matrix & src)
{
	// TODO: insert return statement here
	return istr;
}
