//#include <iostream>
//using namespace std;
//void main()
//{	int year, leap;
//	cin >> year;
//	__asm
//{       // ������� ������������ ����
//			mov ebx, 0 // �������� � ������ 0
//			mov ecx, 400 //�������� � ������ 400
//			mov eax, year //�������� � ������ year
//			cdq // ���������� �������� ������� EAX �� EAX:EDX
//			div ecx // ���������� ������ year �� 400 
//			test edx, edx // �������� EDX �� ������ ��� �����
//			jz is_leap // ���������� �� is_leap, ���� ���� ������ � ������������ ���������
//			mov eax, year // � ������ EAX �������� �������� year
//			cdq // ���������� �������� ������� EAX �� EAX:EDX
//			mov ecx, 4 // �������� � ������ 4
//			div ecx // ���������� ������ year �� 4 
//			test edx, edx // �������� EDX �� ������ ��� �����
//			jz maybe_leap // ���������� �� is_leap, ���� ���� ������ � ������������ ���������
//			jmp result // ���������� �� ���� result
//		is_leap : // ���� is_leap
//			mov ebx, 1 // �������� � ������ E�X 0
//			jmp result // ���������� �� ���� result
//		maybe_leap : //���� maybe_leap
//			mov eax, year // �������� � ������ EAX �������� ����� year
//			cdq // ���������� �������� ������� EAX �� EAX:EDX
//			mov ecx, 100 //�������� � ������ ��� 100
//			div ecx // ���������� ������ year �� 100 
//			test edx, edx // �������� EDX �� ������ ��� ����� 
//			jz result // ���������� �� ���� result
//			jmp is_leap // ������� �� ���� is_leap
//		result : // ���� result
//			mov leap, ebx // �������� � ����� leap �������� ������� E�X  
//	} // ����� ������������ ����
//	if (leap > 0) { cout << "Yes" << endl; }
//	else { cout << "No" << endl; }
//	system("pause");
//}
//
//
