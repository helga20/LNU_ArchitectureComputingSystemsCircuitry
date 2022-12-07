#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
const int n = 5;
float d, c, b, g, z;
const float twenty = 20;
const float two = 2;
const float one = 1;
float a[n];
float res[n];
void calculateASM()
{
	__asm
	{		
			// заповнення регістрів
			lea esi, a // адреса початку масиву a
			lea edi, res // адреса початку масиву res
			mov ecx, n // розмір масиву
			finit // ініціалізація співпроцесора

			fld two // значення 2 в стек співпроцесора
			fmul b // 2 * b
			fld twenty // значення 20 в стек співпроцесора
			fmul c // 20 * c		
			fsub // 2 * b - 20 * c
			fstp g

			iteration : // початок циклу
			fld one // значення 1 в стек співпроцесора
			fld[esi] // значення a[i] в стек співпроцесора
			fadd d // d + a[i]
			fpatan// arctg(d + a[i])
			fdiv c // 1 / c
			fadd one // (1 / c) * arctg(d + a[i]) + 1
			fstp z 
			fld g
			fdiv z // (2 * b - 20 * c) / ((1 / c) * arctg(d + a[i]) + 1)

			fstp[edi] // запис значення виразу в масив res
			// перехід до наступних елементів масивів
			add esi, 4
			add edi, 4
			loop iteration // кінець циклу
	}
}
void enteringData()
{
	cout << " Введіть b : ";
	cin >> b;
	cout << " Введіть с (c > d):" << endl;
	cin >> c;
	cout << " Введіть d (d < c):" << endl;
	cin >> d;
	if (c <= d)
	{
		swap(d, c);
	}
	cout << "\nc = " << c << "\nd = " << d << "\n";
	for (int i = 0; i < n; ++i)
	{
		cout << " a[" << i << "] = ";
		cin >> a[i];
	}
}
void printRes(const char* sym)
{
	cout << " Обчислено в " << sym << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << " результат: [" << i + 1 << "] = " << res[i] << endl;
	}
}
void calculateCpp()
{
	for (int i = 0; i < n; i++)
	{
		res[i] = (2 * b - 20 * c) / ((1 / c) * atan(d + a[i]) + 1);
	}
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	enteringData();
	calculateASM();
	printRes("ASM");
	calculateCpp();
	printRes("C++");
	cout << "\n";
	system("pause");
}