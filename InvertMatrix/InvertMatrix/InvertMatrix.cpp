
#include <fstream>
#include <iostream>
#include <optional>

using namespace std;
constexpr int ROWS = 3;
constexpr int COLS = 3;
typedef double matrixType[ROWS][COLS];

optional<string> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count"
				  << endl;
		std::cout << "Usage: InvertMatrix.exe <path to matrix file>"
				  << endl;
		return nullopt;
	}

	return argv[1];
}

void PrintMatrix(matrixType& matrix)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

double CalcDet(matrixType& matrix)
{
	return (matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] + matrix[2][0] * matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[1][2] * matrix[2][1] * matrix[0][0] - matrix[2][2] * matrix[0][1] * matrix[1][0]);
}

//int Invert(matrixType& matrix)
//{
//	double Det = CalcDet(matrix);
//	return 1;
//}

int ReadMatrix(string& path, matrixType& matrix)
{
	ifstream input;

	input.open(path);
	if (!input.is_open())
	{
		cout << "Failed to open file"
			 << endl;
		return 0;
	}
	
	string holder;
	for (int i = 0; i < ROWS; i++)
	{
		input >> holder;
		istringstream iss(holder);
		vector<string> tokens;
		copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter<vector<string>>(tokens));
		for (int j = 0; j < COLS; j++)
		{
			
		}
	}

	if (input.bad())
	{
		cout << "Failed to read data from input file"
			 << endl;
		return 0;
	}

	return 1;
}

int main(int argc, char* argv[])
{
	matrixType matrix;

	//Получение аргумента
	string path = ParseArgs(argc, argv).value();
	//Чтение матрицы
	ReadMatrix(path, matrix);
	//Печать матрицы
	PrintMatrix(matrix);

	return 1;
}