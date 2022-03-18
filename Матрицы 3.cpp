#include <iostream>
#include <ctime>

void proverka(int* x)
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cout << "Введите значение повторно:";
	std::cin >> *x;
}

void fill_lines_and_columns(int* nRef)
{
	std::cin >> *nRef;
	while (std::cin.fail())
	{
		proverka(*&nRef);
	}
}

void malloxMatrix(double**& matrix, int* line, int* column)
{
	matrix = new double* [*line];
	for (int i = 0; i < *line; i++)//Ввожу элементы первой матрицы
	{
		matrix[i] = new double[*column];
	}
}

void fillMatrix(double**& matrix, int* line, int* column)
{
	for (int i = 0; i < *line; i++)
	{
		for (int j = 0; j < *column; j++)
		{
			std::cout << "[" << i << "][" << j << "]= ";
			std::cin >> matrix[i][j];
		}
	}
}

void fillMatrixRand(double**& matrix, int* line, int* column)
{
	for (int i = 0; i < *line; i++)
	{
		for (int j = 0; j < *column; j++)
		{
			std::cout << "[" << i << "][" << j << "]= ";
			matrix[i][j] = rand();
			std::cout << matrix[i][j] << std::endl;
		}
	}
}

void fillOrRand(int* questions)
{
	std::cout << "Вы хотите ввести элементы массива вручную или попробовать ввод рандомных числа?\nВручную - 1\nВвод рандомных чисел - 2" << std::endl;
	std::cin >> *questions;
	while (*questions != 1 && *questions != 2)
	{
		proverka(*&questions);
	}
}

void multiplicationOfMatrix(double**& c, int *line_A, int *column_B, int * column_A, double **&a, double **&b)
{
	for (int i = 0; i < *line_A; i++) // вычисляю элементы
	{
		for (int j = 0; j < *column_B; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < *column_A; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void printOfMatrix(double**& c, int* line_A, int* column_B)
{
	for (int i = 0; i < *line_A; i++)// вывожу итоговую матрицу
	{
		for (int j = 0; j < *column_B; j++)
		{
			std::cout << c[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int line_A;		//строка 1-ой матрицы
	int line_B;		//строка 2-ой матрицы
	int column_A;	//столбец 1-ой матрицы
	int column_B;	//столбец 2-ой матрицы
	double** a, ** b, ** c;
	int questions;

	do
	{
		std::cout << "Введите количество элементов в строке 1-ой матрицы" << std::endl;
		fill_lines_and_columns(&line_A);
		std::cout << "Введите количество элементов в столбце 1-ой матрицы" << std::endl;
		fill_lines_and_columns(&column_A);
		std::cout << "Введите количество элементов в строке 2-ой матрицы" << std::endl;
		fill_lines_and_columns(&line_B);
		std::cout << "Введите количество элементов в столбце 2-ой матрицы" << std::endl;
		fill_lines_and_columns(&column_B);
	} while (column_A != line_B);

	malloxMatrix(a, &line_A, &column_A);
	fillOrRand(&questions);
	if (questions == 1)
	{
		std::cout << "Введите элементы матрицы" << std::endl;
		fillMatrix(a, &line_A, &column_A);
	}
	else if (questions == 2)
	{
		std::cout << "Вводятся рандомные значения элементов матрицы" << std::endl;
		fillMatrixRand(a, &line_A, &column_A);
	}

	malloxMatrix(b, &line_B, &column_B);
	fillOrRand(&questions);
	if (questions == 1)
	{
		std::cout << "Введите элементы матрицы" << std::endl;
		fillMatrix(b, &line_B, &column_B);
	}
	else if (questions == 2)
	{
		std::cout << "Вводятся рандомные значения элементов матрицы" << std::endl;
		fillMatrixRand(b, &line_B, &column_B);
	}

	malloxMatrix(c, &line_A, &column_B);
	multiplicationOfMatrix(c, &line_A, &column_B, &column_A, a, b);
	printOfMatrix(c, &line_A, &column_B);

	return 0;
}
