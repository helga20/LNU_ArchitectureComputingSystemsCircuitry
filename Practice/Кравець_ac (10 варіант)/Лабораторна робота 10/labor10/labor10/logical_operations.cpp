#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	__int8 arr[8] = { 219,219,219,219,219,219,219,219 };
	__int8 counter = 0;
	__int16 b = 32;
	__asm
	{
			xor eax, eax // обнулення регістра
			xor bl, bl // обнулення регістра
			xor bh, bh // обнулення регістра

			mov al, arr[0] 
			shl eax, 8 // побітовий зсув вліво 
			mov al, arr[1]
			shl eax, 8 // побітовий зсув вліво 
			mov al, arr[2]
			shl eax, 8 // побітовий зсув вліво 
			mov al, arr[3]
		skippingOnes:
				dec bx // зменшення лічильника 
				shl eax, 1 // побітовий зсув вліво 
				jc skippingOnes // перехід
				cmp bx, 0 // порівняння лічильника з 0
				jle secondLoop //перехід
			_next :
				xor bl, bl // обнулення регістра
				xor bh, bh // обнулення регістра
				dec bx // зменшення лічильника 
				shl eax, 1 // побітовий зсув вліво 
				jc ifFirstOne // перехід
				cmp bx, 0 // порівняння лічильника з 0
				jle secondLoop // перехід
				jnc _next // перехід
			ifFirstOne :
				mov bh, bl 
				mov bl, 1 
				dec bx // зменшення лічильника 
				shl eax, 1  // побітовий зсув вліво 
				jc ifSecondOne // перехід
				cmp bx, 0 // порівняння лічильника з 0
				jle secondLoop // перехід
				jnc _next // перехід
			ifSecondOne :
				mov bh, bl
				mov bl, 1
				dec bx
				shl eax, 1
				jc skippingOnes
				cmp bx, 0
				jle secondLoop
				jnc incCounter
			incCounter :
				inc counter // якщо парне, збільшуємо лічильник
				jmp _next
			secondLoop :
				mov bx, 32
				mov al, arr[4]
				shl eax, 8
				mov al, arr[5]
				shl eax, 8
				mov al, arr[6]
				shl eax, 8
				mov al, arr[7]
			zeroingLast:
					xor edx, edx
					mov edx, 1
					not edx
					and eax, edx // накладання маски
					cmp bl, bh
					jne skippingOnes_second
				firstIterAfterRefill :
					dec bx
					shl eax, 1
					jnc incCounter_second
				skippingOnes_second :
					dec bx
					shl eax, 1
					jc skippingOnes_second
					cmp bx, 0
					jle _end
				_next_second :
					xor bl, bl
					xor bh, bh
					dec bx
					shl eax, 1
					jc ifFirstOne_second
					cmp bx, 0
					jle _end
					jnc _next_second
				ifFirstOne_second :
					mov bh, bl
					mov bl, 1
					dec bx
					shl eax, 1
					jc ifSecondOne_second
					cmp bx, 0
					jle _end
					jnc _next_second
			ifSecondOne_second :
				mov bh, bl
				mov bl, 1
				dec bx
				shl eax, 1
				jc skippingOnes_second
				cmp bx, 0
				jle _end
				jnc incCounter_second
			incCounter_second :
				inc counter
				jmp _next_second
			_end :
	}
	cout << "Pairs of ones, surrounded by zeros: " << int(counter) << endl;
	system("pause");
	return 0;
}

