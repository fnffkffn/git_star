#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include <stdlib.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224

void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show) {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void setcolor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

int x = 30, y = 7;

void main(void) {

	CursorView(0); GotoXY(x, y); setcolor(6, 0); printf("★");

	while (1) {
		if (_kbhit()) {
			int nkey = _getche();
			if (nkey == ARROW) {
				int color = rand() % 15 + 1; // 랜덤 색상
				setcolor(color, 0); // 색상 설정
				nkey = _getch();
				switch (nkey) {
				case UP:
					system("cls");  GotoXY(x, --y); printf("★"); break;
				case LEFT:
					system("cls");  GotoXY(x = x - 2, y); printf("★"); break;
				case RIGHT:
					system("cls");  GotoXY(x = x + 2, y); printf("★"); break;
				case DOWN:
					system("cls");  GotoXY(x, ++y); printf("★"); break;
				}
			}
		}
	}


}