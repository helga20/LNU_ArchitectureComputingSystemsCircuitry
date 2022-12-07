#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
const int n = 3; // ������� ������� ����� �
const float neg4 = -4;
int sym;
float d;
float x[n]; // �������� �����
float res[n]; // �������� ������
void calculateASM()
{
	__asm
	{ // ���������� �������
		lea esi, x // ������ ������� ������ �
		lea edi, res // ������ ������� ������ res
		mov ecx, n // ����� ������
		finit // ����������� ������������

		iteration : // ������� �����

			fld[esi] // �������� � � ���� ������������
			fadd d // x + d
			fsincos // sin(x+d) i cos(x+d) � ����
			fmul // sin(x+d)*cos(x+d)
			fld neg4 // -4 � ����
			fdiv // sin(x+d)cos(x+d)/(-4)
			fstp[edi] // ����� �������� ������ � �����
			// ������� �� ��������� �������� ������
			add esi, 4
			add edi, 4

			loop iteration // ����� �����
	}
}
void enteringData()
{
	cout << " ������ d : ";
	cin >> d;
	cout << " ������ x[i] :" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << " x[" << i << "] = ";
		cin >> x[i];
	}
}
void printRes()
{
	cout << " ��������� � " << sym << endl;
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