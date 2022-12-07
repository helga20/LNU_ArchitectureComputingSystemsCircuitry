#include <iostream>
using namespace std;
int a, b, c, d, x;
int values[5]; // масив для збереження у(х)
void main()
{
	a = -6; b = 4; c = 8; d = 2;
	__asm {
			mov eax, offset values
			push eax // заштовхуємо у стек адресу початку масиву
			mov cx, 5 // кількість проходів циклу 
		start: // початок циклу
			mov ax, 3 // для обчислення x = 3 - сх 
			sub ax, cx // отримуємо поточне значення х
			cwde // розширюємо ax до eax
			mov ebx, eax // записуємо x в ebx
			mov eax, a // стала а
			cmp ebx, 1 // порівнюємо х з одиницею
			jl less_ // якщо х менше 1, переходимо до мітки less_
			je equals // якщо х дорівнює 1, переходимо до equals
			// якщо х > 1:
			imul eax // a^2
			sub eax, ebx // a^2-x
			cdq // розширюємо a^2-x до четвірного слова
			mov ebx, c // стала c
			idiv ebx // (a^2-x)/c
			jmp result // переходимо до мітки result
		less_ :
			mov edx, 2
			imul edx // a*2
			imul ebx // a*2*x
			add eax, 5 // a*2*x+5
			jmp result // переходимо до мітки result
		equals :
			mov	ebx, b // стала b
			sub eax, ebx // a-b
			cdq // розширюємо a-b до четвірного слова
			mov ebx, d // стала d
			idiv ebx // (a-b)/d
			jmp result // переходимо до мітки result
		result :
			pop ebx // виштовхуємо зі стеку адресу масиву
			mov[ebx], eax // записуємо результат за поточною адресою
			add ebx, 4 // зсуваємо вказівник масиву
			push ebx // заштовхуємо в стек нову адресу
			loop start // кінець циклу
	}
	for (int i = 0; i < 5; i++) {
		cout << values[i] << endl;
	}
	system("pause");
	return;
}