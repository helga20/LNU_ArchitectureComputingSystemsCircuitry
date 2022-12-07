#include <iostream>
using namespace std;
char FORMAT[] = "%s %s %s %s %s\n";
char DESIGN[] = "Design";
char BY[] = "by";
char OLHA[] = "Olha";
char KRAVETS[] = "Kravets";
char YEAR[] = "2021";
void main()
{	__asm 
	{	// початок асемблерного коду
		mov eax, offset YEAR // заносимо в регістр масив YEAR
		push eax // заносимо значення регістра eax у консоль
		mov eax, offset KRAVETS // заносимо в регістр масив KRAVETS
		push eax // заносимо значення регістра eax у консоль
		mov eax, offset OLHA // заносимо в регістр масив OLHA
		push eax // заносимо значення регістра eax у консоль
		mov eax, offset BY // заносимо в регістр масив BY
		push eax // заносимо значення регістра eax у консоль
		mov eax, offset DESIGN // заносимо в регістр масив DESIGN
		push eax // заносимо значення регістра eax у консоль
		mov eax, offset FORMAT // заносимо в регістр масив FORMAT
		push eax // заносимо значення регістра eax у консоль
		mov edi, printf // заносимо значення стеку у регістр edi
		call edi // викликаємо edi для виведення на консоль
		// Очищення стеку для коректного завершення процедури main
		pop ebx // викинули FORMAT зі стеку
		pop ebx // викинули DESIGN зі стеку
		pop ebx // викинули BY зі стеку
		pop ebx // викинули OLHA зі стеку
		pop ebx // викинули KRAVETS зі стеку
		pop ebx // викинули YEAR зі стеку
	}	// кінець асемблерного коду
	system("pause");}