#include <iostream>
using namespace std;
void main()
{
	int number, product = 1;
	cout << "Enter number: ";
	cin >> number;
	__asm
	{	// ������� ������������ ����
		mov eax, 0 // �������� � ������ 0
		mov ebx, 0 // �������� � ������ 0
		mov edx, 0 // �������� � ������ 0
		mov eax, number // �������� � ������ number
		mov ebx, 10 // �������� � ������ 10
		div ebx // ���������� ������ number �� 10
		mov number, 0 // �������� � ����� number 0
		mov number, eax // �������� � ����� number �������� ������� EAX  
		mov eax, 0 // �������� � ������ 0
		mov eax, product // �������� � ������ product
		mul edx // ���������� �������� 
		mov product, 0 // �������� � ����� product 0
		mov product, eax // �������� � ����� product �������� ������� EAX  // ���������� 4 ����
		
		mov eax, 0
		mov ebx, 0
		mov edx, 0
		mov eax, number
		mov ebx, 10
		div ebx
		mov number, 0
		mov number, eax
		mov eax, 0
		mov eax, product
		mul edx
		mov product, 0
		mov product, eax

		mov eax, 0
		mov ebx, 0
		mov edx, 0
		mov eax, number
		mov ebx, 10
		div ebx
		mov number, 0
		mov number, eax
		mov eax, 0
		mov eax, product
		mul edx
		mov product, 0
		mov product, eax

		mov eax, 0
		mov ebx, 0
		mov edx, 0
		mov eax, number
		mov ebx, 10
		div ebx
		mov number, 0
		mov number, eax
		mov eax, 0
		mov eax, product
		mul edx
		mov product, 0
		mov product, eax
	}	// ����� ������������ ����
	cout << "The product of numbers: " << product << endl;
}

