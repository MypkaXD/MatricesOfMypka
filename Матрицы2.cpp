#include <iostream>
#include <string>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "rus");
fill_lines_and_columns:
	int line_A; //строка 1-ой матрицы
	int line_B; //строка 2-ой матрицы
	int column_A;	//столбец 1-ой матрицы
	int column_B;	//столбец 2-ой матрицы

	double** a, ** b, ** c;

	std::cout << "Введите количество элементов в строке 1-ой матрицы" << std::endl;
	std::cin >> line_A;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите значение повторно:";
		std::cin >> line_A;
	}

	std::cout << "Введите количество элементов в столбце 1-ой матрицы" << std::endl;
	std::cin >> column_A;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите значение повторно:";
		std::cin >> column_A;
	}

	std::cout << "Введите количество элементов в строке 2-ой матрицы" << std::endl;
	std::cin >> line_B;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите значение повторно:";
		std::cin >> line_B;
	}

	std::cout << "Введите количество элементов в столбце 2-ой матрицы" << std::endl;
	std::cin >> column_B;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите значение повторно:";
		std::cin >> column_B;
	}

	if (column_A != line_B) //проверка на правило умножения матриц
	{
		std::cout << "Умножение невозможно, так как число элементов в столбце 1-ой матрице не равно числу элементов в строке 2-ой матрицы\nПопробуйте ввести данные заново" << std::endl;
		goto fill_lines_and_columns;
	}

	a = new double* [line_A];
	
	std::cout << "Вы хотите ввести элементы 1-ого массива вручную или попробовать ввод рандомных числа?\nВ ручную - 1\nВвод рандомных чисел - 2" << std::endl;
	int qestionsOfFill_1;
	std::cin >> qestionsOfFill_1;
	while (qestionsOfFill_1 != 1 && qestionsOfFill_1 != 2) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите значение повторно:";
		std::cin >> qestionsOfFill_1;
	}
	if (qestionsOfFill_1 == 1)
	{
		std::cout << "Введите элементы первой матрицы" << std::endl;

		for (int i = 0; i < line_A; i++)//Ввожу элементы первой матрицы
		{
			a[i] = new double[column_A];

			for (int j = 0; j < column_A; j++)
			{
				std::cout << "a[" << i << "][" << j << "]= ";
				std::cin >> a[i][j];
			}
		}
	}
	if (qestionsOfFill_1 == 2)
	{
		unsigned int start_time_rand_fill_1 = clock();
		std::cout << "Вводятся рандомные значения элементов первой матрицы" << std::endl;

		for (int i = 0; i < line_A; i++)
		{
			a[i] = new double[column_A];

			for (int j = 0; j < column_A; j++)
			{
				std::cout << "a[" << i << "][" << j << "]= ";
				a[i][j] = rand();
				std::cout << a[i][j] << std::endl;
			}
		}
		unsigned int end_time_rand_fill_1 = clock();
		unsigned int search_time_rand_fill_1 = end_time_rand_fill_1 - start_time_rand_fill_1;
	}

	b = new double* [line_B];

	std::cout << "Вы хотите ввести элементы 2-ого массива вручную или попробовать ввод рандомных числа?\nВ ручную - 1\nВвод рандомных чисел - 2" << std::endl;
	int qestionsOfFill_2;
	std::cin >> qestionsOfFill_2;
	while (qestionsOfFill_2 != 1 && qestionsOfFill_2 != 2) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите значение повторно:";
		std::cin >> qestionsOfFill_2;
	}
	if (qestionsOfFill_2 == 1)
	{
		std::cout << "Введите элементы второй матрицы" << std::endl;

		for (int i = 0; i < line_B; i++)
		{
			b[i] = new double[column_B];

			for (int j = 0; j < column_B; j++)
			{
				std::cout << "b[" << i << "][" << j << "]= ";
				std::cin >> b[i][j];
			}
		}
	}
	if (qestionsOfFill_2 == 2)
	{
		unsigned int start_time_rand_fill_2 = clock();
		std::cout << "Вводятся рандомные значения элементов второй матрицы" << std::endl;

		for (int i = 0; i < line_B; i++)
		{
			b[i] = new double[column_B];

			for (int j = 0; j < column_B; j++)
			{
				std::cout << "b[" << i << "][" << j << "]= ";
				b[i][j] = rand();
				std::cout << b[i][j] << std::endl;
			}
		}
		unsigned int end_time_rand_fill_2 = clock();
		unsigned int search_time_rand_fill_2 = end_time_rand_fill_2 - start_time_rand_fill_2;
	}
	double start_time = clock();
	c = new double* [line_A];// итоговая матрица

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

	double end_time = clock();
	double search_time = (end_time - start_time);
	std::cout << "Время выполнения программы = " << search_time / 1000 << "sec" << std::endl;

	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}