// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <windows.h>
#include <iostream> 
#include <string>

using namespace std;

//bool OPEN();
//bool LIST();
//bool REMOVE();
int main()
{
	setlocale(LC_ALL, "rus");
	while (true)
	{
		string ss;
		int s;
		cout << "�������:\n";
		cout << "1 - ��� �������� �������\n";
		cout << "2 - ��� ������ ������ �������� \n";
		cout << "3 - ��� ���������� �������\n";
		cout << "4 - ���� �� �����������" << endl;
		cin >> s;
		system("cls");
		switch(s)
		{
		case 1: break; //OPEN();
		case 2:  break; //LIST();
		case 3: cin >> ss; break; // REMOVE();
		case 4: system("shutdown /s"); exit(0); break;
		default:exit(0);
		}
		cout << endl;
	}
    return 0;
}

