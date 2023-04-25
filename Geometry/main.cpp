#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;

string multistring(string str, int times)
{
	string result;
	while (times > 0)
	{
		result += str;
		times--;
	}
	return result;
}
void figure0()
{
	int rows, stars_count;
	cout << "0. Введите количество * в ряду: "; cin >> stars_count;
	cout << "Введите количество рядов: "; cin >> rows;
	for (int i = 0; i < rows; i++)
	{
		cout << multistring("*", stars_count) << endl;
	}
}
void figure1()
{
	int rows;
	cout << "1. Введите количество рядов: "; cin >> rows;
	for (int i = 1; i <= rows; i++)
	{
		cout << multistring("*", i) << multistring(" ", rows - i) << endl;
	}
}
void figure2()
{
	int rows;
	cout << "2. Введите количество рядов: "; cin >> rows;
	for (int i = 0; i < rows; i++)
	{
		cout << multistring("*", rows - i) << multistring(" ", i) << endl;
	}
}
void figure3()
{
	int rows;
	cout << "3. Введите количество рядов: "; cin >> rows;
	for (int i = 0; i < rows; i++)
	{
		cout << multistring(" ", i) << multistring("*", rows - i) << endl;
	}
}
void figure4()
{
	int rows;
	cout << "4. Введите количество рядов: "; cin >> rows;
	for (int i = 1; i <= rows; i++)
	{
		cout << multistring(" ", rows - i) << multistring("*", i) << endl;
	}
}
void figure5()
{
	int length;
	cout << "5. Введите длину одной грани ромба: "; cin >> length;
	//Верхняя половина
	for (int i = 1; i <= length; i++)
	{
		cout << multistring(" ", length - i) << "/" << multistring(" ", (i - 1) * 2);
		cout << "\\" << multistring(" ", length - i) << endl;
	}
	//Нижняя половина
	for (int i = 0; i < length; i++)
	{
		cout << multistring(" ", i) << "\\" << multistring(" ", (length - i - 1) * 2);
		cout << "/" << multistring(" ", i) << endl;
	}
}
void figure6_v1()
{
	int rows, symbols;
	cout << "6. Введите количество символов в ряду: "; cin >> symbols;
	cout << "Введите количество рядов: "; cin >> rows;
	for (int i = 0; i < rows; i++)
	{
		if (i % 2 == 0)				//Проверка на четность строки, четные с плюса, нечетные с минуса
		{
			cout << multistring("+-", (symbols + 1) / 2);
			if (symbols % 2 != 0)	//Проверка если нечетное количество символов в строке, то
			{						//нужно удалить один символ из последней пары
				cout << "\b ";
			}
			cout << endl;
		}
		else
		{
			cout << multistring("-+", (symbols + 1) / 2);
			if (symbols % 2 != 0)	//То же самое для нечетных строк
			{
				cout << "\b ";
			}
			cout << endl;
		}
	}
}
void figure6_v2()
{
	int rows, symbols;
	cout << "6. Введите количество символов в ряду: "; cin >> symbols;
	cout << "Введите количество рядов: "; cin >> rows;
	std::vector<std::vector<char>> vector2D(rows, std::vector<char>(symbols));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < symbols; j++)
		{
			if ((i + j) % 2 == 0)	//Проверка на четность текущей позиции курсора
			{
				vector2D[i][j] = '+';
				cout << vector2D[i][j];
			}
			else
			{
				vector2D[i][j] = '-';
				cout << vector2D[i][j];
			}
		}
		cout << endl;
	}
}

void main()
{
	setlocale(LC_ALL, "");

	figure0();
	figure1();
	figure2();
	figure3();
	figure4();
	figure5();
	figure6_v2();

	figure6_v1();
}