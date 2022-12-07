#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
const int n = 3; // кількість значень змінної х
const float neg4 = -4;
int sym;
float d;
float x[n]; // значення змінної
float res[n]; // значення виразу
void calculateASM()
{
	__asm
	{ // заповнення регістрів
		lea esi, x // адреса початку масиву х
		lea edi, res // адреса початку масиву res
		mov ecx, n // розмір масиву
		finit // ініціалізація співпроцесора

		iteration : // початок циклу

			fld[esi] // значення х в стек співпроцесора
			fadd d // x + d
			fsincos // sin(x+d) i cos(x+d) в стек
			fmul // sin(x+d)*cos(x+d)
			fld neg4 // -4 в стек
			fdiv // sin(x+d)cos(x+d)/(-4)
			fstp[edi] // запис значення виразу в масив
			// перехід до наступних елементів масивів
			add esi, 4
			add edi, 4

			loop iteration // кінець циклу
	}
}
void enteringData()
{
	cout << " Введіть d : ";
	cin >> d;
	cout << " Введіть x[i] :" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << " x[" << i << "] = ";
		cin >> x[i];
	}
}
void printRes()
{
	cout << " Обчислено в " << sym << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << " result: [" << i + 1 << "] = " << res[i] << endl;
	}
}
void calculateCpp()
{
	for (int i = 0; i < n; i++)
	{
		res[i] = -sin(2 * (d + x[i])) / 8;
	}
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	enteringData();
	calculateASM();
	sym = 1;
	printRes();
	sym = 2;
	calculateCpp();
	printRes();

	system("pause");
}