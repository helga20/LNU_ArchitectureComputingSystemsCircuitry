#include <iostream>
using namespace std;
int main()
{	
	int a, x_begin, x_end;
	cout << "Enter the beginning of the interval: ";	cin >> x_begin;
	cout << "Enter the end of the interval: ";	cin >> x_end;
	cout << "Enter a: ";	cin >> a;
	int y, y1, y2;
	for (int x = x_begin; x <= x_end; ++x)
	{	_asm	{ // початок асемблерного коду
			start :
				mov ebx, x // заносимо в регістр x 
				cmp ebx, a // порівнюємо х і а
				jg x_greater_a // якщо x > 0, переходимо до мітки x_greater_a
			x_less_equal_a : 
				mov eax, a  // заносимо в регістр a 
				sub eax, 7 // a-7
				mov y1, eax // заносимо значення a-7 в y1
				jmp next_y // переходимо до мітки next_y
			x_greater_a :
				cmp ebx, 0 // порівнюємо х і 0
				jge after_checking  // якщо x ≥ 0, переходимо до мітки x_greater_a 
			x_less_0 :
				neg ebx // |х|
			after_checking :
				add ebx, a // |х|+а 
				mov y1, ebx // заносимо значення |х|+а в y1
			next_y :
				cmp a, 3 // порівнюємо а і 3
				jg a_agreater_3 // якщо а > 3, переходимо до мітки a_agreater_3
			alesserEq3 :
				mov y2, 11 // заносимо 11 в y2
				jmp result // переходимо до мітки result
			a_agreater_3 :
				mov eax, a // заносимо в регістр a 
				imul eax, 3 // 3*a
				mov y2, eax // заносимо значення 3*a в y1 
			result :
				mov eax, y1 // заносимо в регістр y1
				sub eax, y2 // y1-y2
				mov y, eax // заносимо значення y1-y2 в y
		}	// кінець асемблерного коду
		cout << "y(" << x << ") = " << y << endl;
	}
	system("pause");
	return 0;
}

