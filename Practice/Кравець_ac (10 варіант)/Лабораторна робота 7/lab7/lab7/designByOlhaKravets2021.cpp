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
	{	// ������� ������������ ����
		mov eax, offset YEAR // �������� � ������ ����� YEAR
		push eax // �������� �������� ������� eax � �������
		mov eax, offset KRAVETS // �������� � ������ ����� KRAVETS
		push eax // �������� �������� ������� eax � �������
		mov eax, offset OLHA // �������� � ������ ����� OLHA
		push eax // �������� �������� ������� eax � �������
		mov eax, offset BY // �������� � ������ ����� BY
		push eax // �������� �������� ������� eax � �������
		mov eax, offset DESIGN // �������� � ������ ����� DESIGN
		push eax // �������� �������� ������� eax � �������
		mov eax, offset FORMAT // �������� � ������ ����� FORMAT
		push eax // �������� �������� ������� eax � �������
		mov edi, printf // �������� �������� ����� � ������ edi
		call edi // ��������� edi ��� ��������� �� �������
		// �������� ����� ��� ���������� ���������� ��������� main
		pop ebx // �������� FORMAT � �����
		pop ebx // �������� DESIGN � �����
		pop ebx // �������� BY � �����
		pop ebx // �������� OLHA � �����
		pop ebx // �������� KRAVETS � �����
		pop ebx // �������� YEAR � �����
	}	// ����� ������������ ����
	system("pause");}