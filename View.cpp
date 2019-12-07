#include"Control.h"
#include"View.h"
#include"Model.h"
#include"DoAnCaro.h"
#include<Windows.h>
#include<stdio.h>
#include<conio.h>

extern struct _POINT { int x, y, c; };// x : diaphragm degree  , y : bounce degree , c : flag
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN; // player 1 = true ; player 2 = false
extern int _COMMAND;//Value input from user
extern int _X, _Y;//Current position of cursor


void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawBoard(int pSize)
{
	for (int i = 0; i < pSize; i++)
		for (int j = 0; j < pSize; j++)
		{
			GotoXY(LEFT + 4 * i,TOP + 2 * j);
			if (i != 0 && j != 0 && i != pSize - 1 && j != pSize - 1)
				printf(".");
			else
				printf("_");
		}
	GotoXY(_A[0][0].x, _A[0][0].y);
}
void PlayerPlaying()
{
	GotoXY(0, 0);
	if (_TURN == true)
		printf("Player's Playing : X");
	else
		printf("Player's Playing : Y");
}

int ProcessFinish(int pWhoWin)
{
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
	switch (pWhoWin)
	{
		case -1:  printf("Nguoi choi 1 thang"); break;
		case 1: printf("Nguoi choi 2 thang"); break;
		case 0:  printf("Nguoi choi 1 va 2 hoa"); break;
		case 2:  _TURN = !_TURN; //Change the player if nothing happens
	}
	PlayerPlaying();
	GotoXY(_X, _Y);
	return pWhoWin;
}

int AskContinue()
{
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 4);
	printf("Nhan Y/N de tiep tuc hoac dung: ");
	return toupper(_getch());
}