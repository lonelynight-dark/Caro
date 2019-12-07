//#pragma once
#ifndef View
#define View


extern bool _TURN; // player 1 = true ; player 2 = false
extern int _COMMAND;//Value input from user
extern int _X, _Y;//Current position of cursor


void FixConsoleWindow();
void GotoXY(int x, int y);
void DrawBoard(int pSize);
int ProcessFinish(int pWhoWin);
int AskContinue();
void PlayerPlaying();

#endif