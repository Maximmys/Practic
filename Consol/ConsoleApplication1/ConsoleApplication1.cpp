// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <TlHelp32.h>
using namespace std;


void OPEN()
{
	wstring s;
	wcout << "Введите имя процесса, который следует запустить: ";
	wcin >> s;
	LPCWSTR Path = s.c_str();
	ShellExecute(NULL,L"open", Path, NULL, NULL, SW_SHOWNORMAL);
}
void LIST()
{
	HANDLE CONST hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	PROCESSENTRY32 peProcessEntry;
	TCHAR szBuff[1024];
	DWORD dwTemp;
	HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return;
	}
	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &peProcessEntry);
	do {
		wsprintf(szBuff, L" %08X %s \r\n", peProcessEntry.th32ProcessID, peProcessEntry.szExeFile);
		WriteConsole(hStdOut, szBuff, lstrlen(szBuff), &dwTemp, NULL);
	} while (Process32Next(hSnapshot, &peProcessEntry));

	CloseHandle(hSnapshot);
}
void REMOVE()
{
	wstring s;
	wcout << "Введите имя процесса, который следует остановить: ";
	wcin >> s;
	HANDLE Target = NULL;
	PROCESSENTRY32 Pc = { sizeof(PROCESSENTRY32) };
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	if (Process32First(hSnapshot, &Pc)) {
		do {
			if (!wcscmp(Pc.szExeFile, s.c_str())) {
				Target = OpenProcess(PROCESS_ALL_ACCESS, TRUE, Pc.th32ProcessID);
			}
		} while (Process32Next(hSnapshot, &Pc));
		TerminateProcess(Target, 0);
		CloseHandle(Target);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	while (true)
	{
		string ss;
		int s;
		cout << "Введите цифру и нажмите Энтер:\n";
		cout << "1 - для создания процесса\n";
		cout << "2 - для вывода списка процессов \n";
		cout << "3 - для завершения процесса\n";
		cout << "4 - если вы гуманитарий\n";
		cout << "5 - для выхода из программы" << endl;
		cin >> s;
		switch(s)
		{
		case 1: OPEN(); break;
		case 2: LIST(); break;
		case 3: REMOVE(); break;
		case 4: system("shutdown /s"); exit(0); break;
		case 5: exit(0);
		default: cout << "Неправильно набранный номер. Выход из программы..." << endl; exit(0);
		}
		cout << endl;
	}
    return 0;
}

