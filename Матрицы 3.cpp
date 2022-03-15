#include <iostream>
#include <ctime>
#include <string>

void fill_lines_and_columns(int* nRef)
{
	std::cin >> *nRef;
	while (std::cin.fail()) 
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Введите значение повторно:";
		std::cin >> *nRef;
	}
}

void malloxMatrix(double**& a, int* line_A, int* column_A)
{
	a = new double* [*line_A];
	for (int i = 0; i < *line_A; i++)//Ввожу элементы первой матрицы
	{
		a[i] = new double[*column_A];
	}
}

void fillMatrixA(double**& a, int* line_A, int* column_A)
{
	for (int i = 0; i < *line_A; i++)//Ввожу элементы первой матрицы
	{
		for (int j = 0; j < *column_A; j++)
		{
			std::cout << "a[" << i << "][" << j << "]= ";
			std::cin >> a[i][j];
		}
	}
}

void fillMatrixRand(double**& a, int* line_A, int* column_A)
{
	for (int i = 0; i < *line_A; i++)//Ввожу элементы первой матрицы
	{
		for (int j = 0; j < *column_A; j++)
		{
			std::cout << "a[" << i << "][" << j << "]= ";
			a[i][j] = rand();
			std::cout << a[i][j] << std::endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int line_A;		//строка 1-ой матрицы
	int line_B;		//строка 2-ой матрицы
	int column_A;	//столбец 1-ой матрицы
	int column_B;	//столбец 2-ой матрицы
	double** a{}, ** b, ** c;

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

	std::cout << "Вы хотите ввести элементы массива вручную или попробовать ввод рандомных числа?\nВручную - 1\nВвод рандомных чисел - 2" << std::endl;
	int qestionsOfFill;
	std::cin >> qestionsOfFill;
	if (qestionsOfFill == 1)
	{
		std::cout << "Введите элементы матрицы" << std::endl;
		fillMatrixA(a, &line_A, &column_A);
	}
	else if (qestionsOfFill == 2)
	{
		std::cout << "Вводятся рандомные значения элементов матрицы" << std::endl;
		fillMatrixRand(a, &line_A, &column_A);
	}
	else
	{
		while (qestionsOfFill != 1 && qestionsOfFill != 2)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Введите значение повторно:";
			std::cin >> qestionsOfFill;
		}
	}
	malloxMatrix(b, &line_B, &column_B);


	std::cout << "Вы хотите ввести элементы массива вручную или попробовать ввод рандомных числа?\nВручную - 1\nВвод рандомных чисел - 2" << std::endl;
	int qestionsOfFill_B;
	std::cin >> qestionsOfFill_B;
	if (qestionsOfFill_B == 1)
	{
		std::cout << "Введите элементы матрицы" << std::endl;
		fillMatrixA(b, &line_B, &column_B);
	}
	if (qestionsOfFill_B == 2)
	{
		std::cout << "Вводятся рандомные значения элементов матрицы" << std::endl;
		fillMatrixRand(b, &line_B, &column_B);
	}
	else
	{
		while (qestionsOfFill_B != 1 && qestionsOfFill_B != 2)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Введите значение повторно:";
			std::cin >> qestionsOfFill_B;
		}
	}
	malloxMatrix(c, &line_A, &column_B);

	for (int i = 0; i < line_A; i++) // вычисляю элементы
	{
		for (int j = 0; j < column_B; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < column_A; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 0; i < line_A; i++)// вывожу итоговую матрицу
	{
		for (int j = 0; j < column_B; j++)
		{
			std::cout << c[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
