#include "Matrix.h"

Matrix::Matrix() : rows(2), cols(2)
{
	setMatrix(rows,cols);
}

Matrix::Matrix(size_t _rows, size_t _cols) : rows(_rows), cols(_cols)
{
	setMatrix(rows,cols);
}

Matrix::Matrix(size_t _rows, size_t _cols, const int ** _matrix) : rows(_rows), cols(_cols)
{
	setMatrix(rows, cols, _matrix);
}

Matrix::Matrix(const Matrix & other)
{
	copyFrom(other);
}

Matrix & Matrix::operator=(const Matrix & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Matrix & Matrix::operator+=(const Matrix & other)
{
	Matrix* emptyMatrix = nullptr;

	if (rows != other.rows || cols != other.cols)
		return *emptyMatrix;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] += other.matrix[i][j];
		}
	}

	if (this)
		isZeroMatrix = true;

	return *this;
}

Matrix & Matrix::operator-=(const Matrix & other)
{
	Matrix* emptyMatrix = nullptr;

	if (rows != other.rows || cols != other.cols)
		return *emptyMatrix;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] -= other.matrix[i][j];
		}
	}

	if (this)
		isZeroMatrix = true;

	return *this;
}

Matrix & Matrix::operator*=(const Matrix & other)
{
	Matrix* emptyMatrix = nullptr;

	if (cols != other.rows || cols != other.cols)
		return *emptyMatrix;

	Matrix helpMatrix = *this;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int t = 0; t < rows; t++)
			{
				helpMatrix[i][j] += matrix[i][t] * other.matrix[t][j];
			}
		}
	}

	if (helpMatrix)
		isZeroMatrix = true;

	return (*this = helpMatrix);
}

Matrix & Matrix::operator*=(int scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] *= scalar;
		}
	}

	if (this)
		isZeroMatrix = true;

	return *this;
}

const int * Matrix::operator[](size_t index) const
{
	if (index >= rows)
		return nullptr;

	return matrix[index];
}

int * Matrix::operator[](size_t index)
{
	if (index >= rows)
		return nullptr;

	return matrix[index];
}

Matrix::operator bool() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j])
				return false;
		}
	}

	return true;
}

void Matrix::setMatrix(size_t _rows, size_t _cols, const int ** _matrix)
{
	if (!rows || !cols)
		return;

	delete[] matrix;

	if (_rows != rows)
		rows = _rows;

	if (_cols != cols)
		cols = _cols;

	matrix = new int*[rows] {};

	if (!_matrix)
	{
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols] {};
		}

		isZeroMatrix = true;
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols] {};
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = _matrix[i][j];
			}
		}

		if(this)
			isZeroMatrix = true;
	}
}

void Matrix::free()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void Matrix::copyFrom(const Matrix & other)
{
	rows = other.rows;

	cols = other.cols;

	setMatrix(rows, cols, (const int**)other.matrix);
}

bool operator==(const Matrix & lhs, const Matrix & rhs)
{
	if (lhs.rows != rhs.rows || lhs.cols != rhs.cols)
		return false;

	for (int i = 0; i < lhs.rows; i++)
	{
		for (int j = 0; j < lhs.cols; j++)
		{
			if (lhs.matrix[i][j] != rhs.matrix[i][j])
				return false;
		}
	}

	return true;
}

bool operator!=(const Matrix & lhs, const Matrix & rhs)
{
	return !(lhs == rhs);
}

Matrix operator*(const Matrix & obj, int scalar)
{
	Matrix result(obj);

	result *= scalar;

	return result;
}

Matrix operator*(int scalar, const Matrix & obj)
{
	return (obj * scalar);
}

Matrix operator+(const Matrix & lhs, const Matrix & rhs)
{
	Matrix result = lhs;

	Matrix* resMatrix = &(result += rhs);

	if (!resMatrix)
		return {};

	return result;
}

Matrix operator-(const Matrix & lhs, const Matrix & rhs)
{
	Matrix result = lhs;

	Matrix* resMatrix = &(result -= rhs);

	if (!resMatrix)
		return {};

	return result;
}

Matrix operator*(const Matrix & lhs, const Matrix & rhs)
{
	Matrix result = lhs;

	Matrix* resMatrix = &(result *= rhs);

	if (!resMatrix)
		return {};

	return result;
}
