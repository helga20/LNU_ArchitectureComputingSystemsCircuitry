//#include <iostream>
//using namespace std;
//void main()
//{	int year, leap;
//	cin >> year;
//	__asm
//{       // початок асемблерного коду
//			mov ebx, 0 // заносимо в регістр 0
//			mov ecx, 400 //заносимо в регістр 400
//			mov eax, year //заносимо в регістр year
//			cdq // розширюємо значення регістра EAX ДО EAX:EDX
//			div ecx // беззнакове ділення year на 400 
//			test edx, edx // перевірка EDX на остачу при діленні
//			jz is_leap // переходимо до is_leap, якщо немає остачі в попередньому результаті
//			mov eax, year // в регістр EAX заносимо значення year
//			cdq // розширюємо значення регістра EAX ДО EAX:EDX
//			mov ecx, 4 // заносимо в регістр 4
//			div ecx // беззнакове ділення year на 4 
//			test edx, edx // перевірка EDX на остачу при діленні
//			jz maybe_leap // переходимо до is_leap, якщо немає остачі в попередньому результаті
//			jmp result // переходимо до мітки result
//		is_leap : // мітка is_leap
//			mov ebx, 1 // заносимо в регістр EВX 0
//			jmp result // переходимо до мітки result
//		maybe_leap : //мітка maybe_leap
//			mov eax, year // заносимо в регістр EAX значення змінної year
//			cdq // розширюємо значення регістра EAX ДО EAX:EDX
//			mov ecx, 100 //заносимо в регістр ЕСХ 100
//			div ecx // беззнакове ділення year на 100 
//			test edx, edx // перевірка EDX на остачу при діленні 
//			jz result // переходимо до мітки result
//			jmp is_leap // перехід до мітки is_leap
//		result : // мітка result
//			mov leap, ebx // заносимо в змінну leap значення регістра EВX  
//	} // кінець асемблерного коду
//	if (leap > 0) { cout << "Yes" << endl; }
//	else { cout << "No" << endl; }
//	system("pause");
//}
//
//
