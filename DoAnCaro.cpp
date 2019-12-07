#include"DoAnCaro.h"
#include"View.h"
#include"Model.h"
#include"Control.h"
#include<stdio.h>
#include<conio.h>
#include <Windows.h>

extern struct _POINT { int x, y, c; };// x : diaphragm degree  , y : bounce degree , c : flag
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern bool _TURN; // player 1 = true ; player 2 = false
extern int _COMMAND;//Value input from user
extern int _X, _Y;//Current position of cursor

int	main()
{
	FixConsoleWindow();
	ResetData();
	StartGame();
	bool ValidEnter = true;

	while (1)
	{
		int _COMMAND = toupper(_getch());
		if (_COMMAND == 27)
		{
			EndGame();
			return 0;
		}	
		else
		{
			if (_COMMAND == 'A')	MoveLeft();
			else if (_COMMAND == 'D')	MoveRight();
			else if (_COMMAND == 'W')	MoveUp();
			else if (_COMMAND == 'S')	MoveDown();
			else if (_COMMAND == 13)
			{
				switch (CheckBoard(_X, _Y))
				{
				case -1: printf("X"); break;
				case  1: printf("Y"); break;
				case  0: ValidEnter = false;
				}

				if (ValidEnter == true)
					switch (ProcessFinish(TestBoard()))
					{
					case -1:case 1:case 0:
						if (AskContinue() != 'Y')
						{
							EndGame();
							return 0;
						}
						else
							StartGame();
					}
			}
			ValidEnter = true;
		}

	}
}
