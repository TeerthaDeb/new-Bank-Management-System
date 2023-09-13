#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

void gxy(short col, short row)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {col, row};
	SetConsoleCursorPosition(h, position);
}