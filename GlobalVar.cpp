#pragma once
#include "DoAnCaro.h"

struct _POINT { int x, y, c; };// x : diaphragm degree  , y : bounce degree , c : flag
_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN; // player 1 = true ; player 2 = false
int _COMMAND;//Value input from user
int _X, _Y;//Current position of cursor