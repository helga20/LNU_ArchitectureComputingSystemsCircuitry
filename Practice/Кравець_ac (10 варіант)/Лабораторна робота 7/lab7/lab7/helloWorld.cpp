//#include <iostream>
//using namespace std;
//char FORMAT[] = "%s %s\n";
//char HELLO[] = "Hello";
//char WORLD[] = "world";
//void main() {
//	__asm {
//		// початок асемблерного коду
//		mov eax, offset WORLD
//		push eax
//		mov eax, offset HELLO
//		push eax
//		mov eax, offset FORMAT
//		push eax
//		mov edi, printf
//		call edi
//		// Очищення стеку для коректного завершення процедури main
//		pop ebx
//		pop ebx
//		pop ebx
//	}
//	// кінець асемблерного коду
//	system("pause");
//}
