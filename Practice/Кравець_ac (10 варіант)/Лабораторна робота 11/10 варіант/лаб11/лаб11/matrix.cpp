#include <iostream>
using namespace std;
int main()
{
	int mm;
	cout << "Enter m: ";
	cin >> mm;
	const int m = mm;

	int nn;
	cout << "Enter n: ";
	cin >> nn;
	const int n = nn;

	//початкова матриц€ 
	cout << "Matrix: ";
	int** first = new int* [m];
	for (int i = 0; i < m; i++)
	{
		first[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			int m1;
			cin >> m1;
			first[i][j] = m1;
		}
	}

	// тимчасова матриц€ дл€ збер≥ганн€ матриц≥ до степенн€
	int** temp_pow = new int* [m];
	for (int i = 0; i < m; i++)
	{
		temp_pow[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			temp_pow[i][j] = 0;
		}
	}

	// матриц€ дл€ збер≥ганн€ матриц≥ до степенн€
	int** first_to_pow = new int* [m];
	for (int i = 0; i < m; i++)
	{
		first_to_pow[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			first_to_pow[i][j] = first[i][j];
		}
	}

	cout << "Numbers: ";
	int* vec = new int[n];
	for (int i = 0; i < n; i++)
	{
		int m1;
		cin >> m1;
		vec[i] = m1;
	}

	int** result = new int* [n];
	for (int i = 0; i < n; i++)
	{
		result[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				result[i][j] = vec[0] + first[i][j] * vec[1];
			}
			else
			{
				result[i][j] = first[i][j] * vec[1];
			}
		}
	}
	cout << endl;

	// матриц€, за допомогою €коњ отримаЇмо к≥нцеву матрицю
	cout << "Matrix operating:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << first[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Vector operating: {";
	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << ", ";
	}
	cout << "\b\b}" << endl;

	for (int k = 2; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				__asm
				{
						mov edx, temp_pow // edx = temp_pow
						mov esi, i
						imul esi, 4
						add edx, esi // edx = &temp_pow[i]
						mov edx, [edx]
						mov esi, j
						imul esi, 4
						add edx, esi // edx = &temp_pow[i][j]
						push edx // заштовхуЇмо в стек
						xor esi, esi // обнуленн€ л≥чильника
						mov ecx, n
					_start :
						mov eax, first_to_pow
						mov ebx, first
					powered_first_to_eax :
						mov edx, i
						mov eax, [eax + edx * 4] // eax = a[i]
						mov edx, esi
						mov eax, [eax + edx * 4] // eax = a[i][esi]
					first_to_ebx :
						mov edx, esi
						mov ebx, [ebx + edx * 4] // ebx = b[esi]
						mov edx, j
						mov ebx, [ebx + edx * 4] // ebx = b[esi][j]
					_end :
						pop edx // виштовхуЇмо з≥ стеку
						imul eax, ebx // eax = a[i][esi] * b[esi][j]
						add[edx], eax
						push edx // заштовхуЇмо в стек
						inc esi // зб≥льшуЇмо значенн€ операнда
						loop _start // к≥нець циклу
						pop edx // виштовхуЇмо з≥ стеку
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				__asm
				{
					mov edx, temp_pow // edx = temp_pow
					mov ecx, result // ecx = result
					mov eax, first_to_pow // eax = first_to_pow

					mov esi, i
					imul esi, 4

					add edx, esi // edx = &temp_pow[i]
					add eax, esi // eax = &first_to_pow[i]
					add ecx, esi // ecx = &result[i]

					mov edx, [edx]
					mov ecx, [ecx]
					mov eax, [eax]

					mov esi, j
					imul esi, 4

					add edx, esi
					add ecx, esi
					add eax, esi

					mov ebx, [edx]

					mov[eax], ebx
					mov esi, vec
					mov edi, k
					imul edi, 4
					add esi, edi
					mov esi, [esi]
					imul ebx, esi
					add[ecx], ebx
					mov[edx], 0
				}
			}
		}
	}

	// виведенн€ результату
	cout << "Result matrix:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (size_t i = 0; i < m; i++)
	{
		delete[] temp_pow[i];
		delete[] first_to_pow[i];
		delete[] first[i];
		delete[] result[i];
	}

	delete[] temp_pow;
	delete[] first_to_pow;
	delete[] first;
	delete[] result;
	delete vec;

	system("pause");
	return 0;
}




