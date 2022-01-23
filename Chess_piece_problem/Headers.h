#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <list>
#include <array>
#include <cstdlib>
#include <chrono>

#define TRUE 1
#define FALSE 0
#define QUEEN 81
#define ROOK 82 //bástya
#define BISHOP 66 //futó
#define PAWN 80 //paraszt
#define SPACE 32 //szóköz (üres)
#define KNIGHT 75 //ló


//orientations
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4
#define ALL 5


struct ledger
{
	int pos;
	int col;
	int row;

	ledger(int a, int b, int c)
	{
		pos = a;
		col = b;
		row = c;
	}


};