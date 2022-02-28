#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus"); //русский язык в консоль
	
	int line_A; //строка 1-ой матрицы
	int line_B; //строка 2-ой матрицы
	int column_A;	//столбец 1-ой матрицы
	int column_B;	//столбец 2-ой матрицы

	double** a, ** b, ** c;

	std::cout << "Введите количество элементов в строке 1-ой матрицы" << std::endl;
	std::cin >> line_A;

	std::cout << "Введите количество элементов в столбце 1-ой матрицы" << std::endl;
	std::cin >> column_A;

	std::cout << "Введите количество элементов в строке 2-ой матрицы" << std::endl;
	std::cin >> line_B;

	std::cout << "Введите количество элементов в столбце 2-ой матрицы" << std::endl;
	std::cin >> column_B;

	if (column_A != line_B) //проверка на правило умножения матриц
	{
		std::cout << "Умножение невозможно, так как число элементов в столбце 1-ой матрице не равно числу элементов в строке 2-ой матрицы" << std::endl;
		return 0;
	}

	a = new double* [line_A*sizeof(double)];

	std::cout << "Введите элементы первой матрицы" << std::endl;

	for (int i = 0; i < line_A; i++)//Ввожу элементы первой матрицы
	{
		a[i] = new double[column_A*sizeof(double)];

		for (int j = 0; j < column_A; j++)
		{
			std::cout << "a[" << i << "][" << j << "]= ";
			std::cin >> a[i][j];
		}
	}

	std::cout << "/";
	int pass_1 = line_A*2+1;
	
	for (int i = 0; i < pass_1; i++)
	{
		std::cout << " ";
	}

	std::cout << "\\" << std::endl;
	
	for (int i = 0; i < line_A; i++)//Вывожу элементы 1-ой матрицы
	{
		std::cout << "| ";
		for (int j = 0; j < column_A; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << "|";
		std::cout << std::endl;
	}

	std::cout << "\\";

	for (int i = 0; i < pass_1; i++)
	{
		std::cout << " ";
	}

	std::cout << "/" << std::endl;

	b = new double* [line_B * sizeof(double)];

	std::cout << "Введите элементы первой матрицы" << std::endl;

	for (int i = 0; i < line_B; i++)//Ввожу элементы второй матрицы
	{
		b[i] = new double[column_B * sizeof(double)];

		for (int j = 0; j < column_B; j++)
		{
			std::cout << "b[" << i << "][" << j << "]= ";
			std::cin >> b[i][j];
		}
	}

	std::cout << "/";
	int pass_2 = line_B * 2 + 1;

	for (int i = 0; i < pass_2; i++)
	{
		std::cout << " ";
	}

	std::cout << "\\" << std::endl;

	for (int i = 0; i < line_B; i++)//Вывожу элементы 2-ой матрицы
	{
		std::cout << "| ";
		for (int j = 0; j < column_B; j++)
		{
			std::cout << b[i][j] << " ";
		}
		std::cout << "|";
		std::cout << std::endl;
	}

	std::cout << "\\";

	for (int i = 0; i < pass_2; i++)
	{
		std::cout << " ";
	}

	std::cout << "/" << std::endl;

	c = new double* [line_A * sizeof(double)];// итоговая матрица

	for (int i = 0; i < line_A; i++) // вычисляю элементы
	{
		c[i] = new double[column_B];
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