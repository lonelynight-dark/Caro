#include"Control.h"
#include"View.h"
#include"Model.h"
#include"DoAnCaro.h"
#include <stdlib.h>

extern struct _POINT { int x, y, c; };// x : diaphragm degree  , y : bounce degree , c : flag
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN; // player 1 = true ; player 2 = false
extern int _COMMAND;//Value input from user
extern int _X, _Y;//Current position of cursor

void ResetData()
{	
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_A[i][j].x = 4 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;
			_A[i][j].c = 0; // 0 if not marked . -1 if taken by player 1. 1 if taken by player 2
		}
	 _TURN = true; _COMMAND = -1; // Set Default Player and Default Key
	_X = _A[0][0].x; _Y = _A[0][0].y; // Set Default Coordinate
}

void GarbageCollect()
{
	//Clean resource if declared cursor variables
}

int CheckFullBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c != 0)	return 0;
		}
	return 1;
}

int CheckStateWin()
{
	int flag = (_TURN == true) ? (-1) : 1;
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		if (_A[i][j].c == flag)
		{
			//Ngang
			int count = 0;
			for (int k = j; k < BOARD_SIZE && (k - j) < LINE; k++)
			{
				if (_A[i][k].c == flag)
					count++;
			}
			if (count == LINE)	return 1;
			
			//Doc
			count = 0;
			for (int k = i; k < BOARD_SIZE && (k - i) < LINE; k++)
			{
				if (_A[k][j].c == flag)
					count++;
			}
			if (count == LINE)	return 1;
			//Cheo phai
			count = 0;
			for (int k = 0; ((i + k) < BOARD_SIZE) && (j + k) < BOARD_SIZE && k < LINE; k++)
			{
				if (_A[i + k][j + k].c == flag)
					count++;
			}	
			if (count == LINE)	return 1;
			//Cheo trai
			count = 0;
			for (int k = 0; (i + k) < BOARD_SIZE && (j - k)>= 0 && k < LINE; k++)
			{
				if (_A[i + k][j - k].c == flag)
					count++;
			}
			if (count == LINE)	return 1;

		}
	
	return 0;
}

int TestBoard()
{
	if (CheckFullBoard() == 1) return 0;
	else if (CheckStateWin() == 1)
			return ((_TURN == true) ? -1 : 1);
	else
		return 2;
}

int CheckBoard(int pX, int pY)
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0)
			{
				if (_TURN == true)	_A[i][j].c = -1;
				else _A[i][j].c = 1;
				return _A[i][j].c;
			}
	return 0;
}

