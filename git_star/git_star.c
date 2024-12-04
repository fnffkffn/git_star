#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224

#define DIAG_UP_LEFT 113   // Q 키
#define DIAG_UP_RIGHT 101  // E 키
#define DIAG_DOWN_LEFT 122 // Z 키
#define DIAG_DOWN_RIGHT 99 // C 키

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
				nkey = _getch();
				switch (nkey) {
				case UP:
					if (y > 0) y--;
					break;
				case LEFT:
					if (x > 0) x -= 2;
					break;
				case RIGHT:
					if (x < 78) x += 2;
					break;
				case DOWN:
					if (y < 24) y++;
					break;
				
				}
			}
			else {
				switch (nkey) {
				case DIAG_UP_LEFT:
					if (x > 0 && y > 0) { x -= 2; y--; }
					break;
				case DIAG_UP_RIGHT:
					if (x < 78 && y > 0) { x += 2; y--; }
					break;

				}

			}
		}
	}


}