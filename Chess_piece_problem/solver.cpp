#include "solver.h"

/*
explanation for pawn:
on the table the pawn can hit front-left & front-right. Front is determined by orientation
p is the position of the pawn (in 1d space)
w is the with of the board
+-1 is the left and the right functions.
orientation can be determined 5 ways. the 4 normal & all.
this function returns false, if it's a valid position for a supposed new pawn, or true if it's a good place.
*/

bool solver::solve_pawn(int orientation)
{
	switch (orientation)
	{
	case 1: //north p-w-1 && p+w+1
	{
		break;
	}
	case 2: //east
	{
		break;
	}
	case 3: //south
	{
		break;
	}
	case 4: //west
	{
		break;
	}
	case 5: //all
	{
		break;
	}
	default:
	{
		return FALSE;
		break;
	}};
	return FALSE;
};

void solver::solve_rook()
{};

void solver::solve_bishop()
{};

void solver::solve_queen()
{};