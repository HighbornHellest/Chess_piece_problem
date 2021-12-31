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




bool solver::solve_pawn(int position, int orientation)
{
	switch (orientation)
	{
	case 1: //north p-w-1 && p+w+1
	{
		char a; char b;
		a = m_table->m_table.at(position - width - 1);
		b = m_table->m_table.at(position - width + 1);

		return quick_space(a,b);
		break;
	}
	case 2: //east p-w+1 && p+w+1
	{
		char a; char b;
		a = m_table->m_table.at(position - width + 1);
		b = m_table->m_table.at(position - width + 1);
		
		return quick_space(a, b);

		break;
	}
	case 3: //south
	{
		char a; char b;
		a = m_table->m_table.at(position + width - 1);
		b = m_table->m_table.at(position + width + 1);
		return quick_space(a,b);

		break;
	}
	case 4: //west
	{
		char a; char b;
		a = m_table->m_table.at(position - width - 1);
		b = m_table->m_table.at(position + width - 1);
		return quick_space(a, b);
		break;
	}
	case 5: //all
	{
		char a; char b;
		//north side
		a = m_table->m_table.at(position - width - 1);
		b = m_table->m_table.at(position - width + 1);
		bool s = quick_space(a, b);
		//south side
		a = m_table->m_table.at(position + width - 1);
		b = m_table->m_table.at(position + width + 1);
		bool n = quick_space(a,b);

		if (a==TRUE && b == TRUE)
		{
			return  TRUE;
		}
		else
		{
			return FALSE;
		}
		

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

inline bool solver::quick_space(int a, int b)
{

	if (a = !SPACE && b != SPACE)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}