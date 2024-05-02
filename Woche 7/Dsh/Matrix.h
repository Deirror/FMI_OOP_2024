#pragma once

class Matrix
{
private:
	int** matrix = nullptr;

	size_t rows = 0;

	size_t cols = 0;

	mutable bool isZeroMatrix = false;

public:
	Matrix();
	Matrix(size_t _rows, size_t _cols);
	Matrix(size_t _rows, size_t _cols, const int** _matrix);

	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);//with Matrix
	Matrix& operator*=(int scalar);//with scalar

	const int* operator[](size_t index) const;
	int* operator[](size_t index);

	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
	operator bool() const;
	void setMatrix(size_t _rows, size_t _cols,const int** _matrix = nullptr);

private:
	void free();
	void copyFrom(const Matrix& other);

};

bool operator!=(const Matrix& lhs, const Matrix& rhs);

Matrix operator*(const Matrix& obj, int scalar);
Matrix operator*(int scalar, const Matrix& obj);

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);

