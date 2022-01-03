#include "solver.h"

/*
explanation for pawn:
on the table the pawn can hit front-left & front-right. Front is determined by orientation
p is the position of the pawn (in 1d space)
w is the with of the board
+-1 is the left and the right functions.
orientation can be determined 5 ways. the 4 normal & all.
this function returns false, if it isn't a valid position for a supposed new pawn,
or true if it's a valid place, meaning it'll hit nothing (or used backward if nothign hits it )


example:
(p11)( )  (p12) ( )  ( )  ( )  ( )
( )  [P]  [ ]   [ ]  [ ]  [ ]  ( )
(p13)[ ]  [p14] [ ]  [ ]  [ ]  ( )
( )  [ ]  [ ]   [ ]  [ ]  [ ]  ( )
( )  [ ]  [ ]   [ ]  [ ]  [ ]  ( )
( )  ( )  ( )   ( )  ( )  ( )  ( )

// the () represent non existent spaces, like those that are outside of the array, OR
if addressed would go to next/previous line. EG p13 could be reffered to as at(5).

*/

/*
TODO:
make corners safe
make edges safe
*/


//cases are where the hypothethical pawns are facing
bool solver::solve_pawn(int position, int orientation)
{
	switch (orientation)
	{
	case 1: //north p-w-1 && p+w+1
	{
		char a; char b;
		int p11 = position - width - 1;
		int p12 = position - width + 1;
		if (p11 >= 0 && p12 >=0) //if not outside of vector
		{
			a = m_table->m_table.at(p11);
			b = m_table->m_table.at(p12);
		}

		return quick_space(a,b);
		break;
	}
	case 2: //east p-w+1 && p+w+1 //need to check p12, p14
	{
		char a; char b;
		int p12= position - width + 1, p14= position + width + 1;
		if (position+1 % width == 0 ) //top right corner
		{
			return TRUE; //so if position == than i'm garanteed to be at the top right corner
			//taking east facing orientation into account, p14 is guaranteed to be "out of bounds" and should be not cindered either
			//therefore the place is safe to be taken.
			//coincidentally, this can be generalised for pawn, if we're at the edge lol
		}
		else if(p12 < 0)//this is the top edge. should disregard p11.
		{
			a = m_table->m_table.at(p14); 
			b = a;
		}
		else if(p14 > m_table->m_table.size()) //normally you'd have to offset this, by one, but not needed in this context
		{
			a = m_table->m_table.at(p12);
			b = a;
		}
		else //this is actaully anywhere
		{
			a = m_table->m_table.at(p12);
			b = m_table->m_table.at(p14);
		}
		return quick_space(a, b);

		break;
	}
	case 3: //south p13=p+w-1 & p14=p+w+1
	{
		char a; char b;
		int p13 = position + width - 1, p14 = position + width + 1;

		//bottom rows, second one is one above the bottom right
		if (p13 > m_table->m_table.size() || p14 > m_table->m_table.size())
		{
			return true;
		}
		else if (position % width == width-1) //right side //only p3
		{
			a = b = p13;
		}
		else if (position % width == 0)//left side //only p4
		{
			a = b = p14;
		}
		else //anywhere else
		{
			a = p13;
			b = p14;
		}
		return quick_space(a,b);

		break;
	}
	case 4: //west p11=p-w-1 && p13=p+w-1
	{
		char a; char b;
		int p11 = position - width - 1, p13 = position + w - 1;

		if (p11 < 0) //top row
		{
			if (position = 0)
			{
				return true;
			}
			else
			{
				a = b = p13;
			}
		}
		if (position % width == 0)//left side row
		{
			return true;
		}
		if(p13 > m_table->m_table.size())//top side
		{
			a = b = p11;
		}
		return quick_space(a, b);
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