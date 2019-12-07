#include"Control.h"
#include"View.h"
#include"Model.h"
#include"DoAnCaro.h"
#include <stdlib.h>
#include <stdio.h>
extern struct _POINT { int x, y, c; };// x : diaphragm degree  , y : bounce degree , c : flag
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN; // player 1 = true ; player 2 = false
extern int _COMMAND;//Value input from user
extern int _X, _Y;//Current position of cursor

void StartGame()
{
	system("cls");
	ResetData();
	PlayerPlaying();
	DrawBoard(BOARD_SIZE);
}


void EndGame()
{
	system("cls");
	GarbageCollect();
	//Save game before exit
}

void MoveRight()
{
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x - 4)
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
}

void MoveLeft()
{
	if (_X > _A[0][0].x)
	{
		_X -= 4;
		GotoXY(_X, _Y);
	}
}

void MoveDown()
{
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y - 2)
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}

void MoveUp()
{
	if (_Y > _A[0][0].y)
	{
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}