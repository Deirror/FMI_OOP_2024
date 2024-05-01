#include <iostream>
#include <fstream>
#define MAX_LEN 65
#pragma warning (disable : 4996)
//Desiish zad1 W3
size_t getCountOfSymbolInFile(std::ifstream& ifs, char specialSymbol)
{
	size_t result = 0;
	char symbol;

	while (true)
	{
		ifs.get(symbol);

		if (specialSymbol == symbol)
			result++;

		if (ifs.eof())
			break;
	}

	ifs.clear();
	ifs.seekg(0);

	return result;
}

void free(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void saveMatrixToFile(const char* fileName,const int** matrix, int rows, int cols)
{
	if (!matrix || !fileName)
		return;

	std::ofstream ofs(fileName);

	if (!ofs.is_open())
		return;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			ofs << matrix[i][j];

			if (j != cols - 1)
			{
				ofs << ',';
			}
			else
			{
				if(i != rows - 1)
				ofs << '|';
			}
		}
	}

	ofs.close();
}

void readMatrix(std::ifstream& ifs, int** matrix, int rows, int cols)
{
	if (!matrix)
		return;

	int row = 0;
	int col = 0;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			ifs >> matrix[row][col];
			ifs.ignore();
		}
    }

	ifs.close();
}

void readMatrixes(const char* fileName1, const char* fileName2)
{
	if (!fileName1 || !fileName2)
		return;

	std::ifstream ifs1(fileName1);

	if (!ifs1.is_open())
		return;

	std::ifstream ifs2(fileName2);

	if (!ifs2.is_open())
		return;

	size_t rows1 = getCountOfSymbolInFile(ifs1, '|');
	int counterOfCommas = getCountOfSymbolInFile(ifs1, ',');
	size_t cols1 = counterOfCommas - rows1*(counterOfCommas / (rows1++ + 1)) + 1;

	size_t rows2 = getCountOfSymbolInFile(ifs2, '|');
	counterOfCommas = getCountOfSymbolInFile(ifs2, ',');
	size_t cols2 = counterOfCommas - rows2 * (counterOfCommas / (rows2++ + 1)) + 1;

	if (cols1 != rows2)
		return;

	int** matrix1 = new int*[rows1] {};
	int** matrix2 = new int*[rows2] {};

	for (int i = 0; i < rows1; i++)
	{
		matrix1[i] = new int[cols1];
	}
	for (int i = 0; i < rows2; i++)
	{
		matrix2[i] = new int[cols2];
	}

	readMatrix(ifs1, matrix1, rows1, cols1);
	readMatrix(ifs2, matrix2, rows2, cols2);

	int** multipliedMatrix = new int*[rows1] {};

	for (int i = 0; i < rows1; i++)
	{
		multipliedMatrix[i] = new int[cols2] {};
	}

	int resField = 0;

	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			for (int t = 0; t < rows2; t++)
			{
				resField += matrix1[i][t] * matrix2[t][j];
			}
			
			multipliedMatrix[i][j] = resField;

			resField = 0;
		}
	}

	saveMatrixToFile("res.txt",(const int**)multipliedMatrix, rows1, cols2);

	free(matrix1, rows1);
	free(matrix2, rows2);
	free(multipliedMatrix, rows1);
}

int main()
{
	readMatrixes("m1.txt", "m2.txt");

	return 0;
}