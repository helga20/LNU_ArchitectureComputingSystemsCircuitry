#include <iostream>
using namespace std;
void main()
{
	int number, product = 1;
	cout << "Enter number: ";
	cin >> number;
	__asm
	{	// початок асемблерного коду
		mov eax, 0 // заносимо в регістр 0
		mov ebx, 0 // заносимо в регістр 0
		mov edx, 0 // заносимо в регістр 0
		mov eax, number // заносимо в регістр number
		mov ebx, 10 // заносимо в регістр 10
		div ebx // беззнакове ділення number на 10
		mov number, 0 // заносимо в змінну number 0
		mov number, eax // заносимо в змінну number значення регістра EAX  
		mov eax, 0 // заносимо в регістр 0
		mov eax, product // заносимо в регістр product
		mul edx // беззнакове множення 
		mov product, 0 // заносимо в змінну product 0
		mov product, eax // заносимо в змінну product значення регістра EAX  // повторюємо 4 рази
		
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
	}	// кінець асемблерного коду
	cout << "The product of numbers: " << product << endl;
}

