#pragma once
#include "Table.h"
#include "Headers.h"


class solver
{

private:
	Table *m_table;
	int width;

public:
	solver( Table *table)
		:m_table(table)
	{
		width=table->m_num_col;
	}
	//width, lenght
	solver(int a, int b)
	{
		m_table = new Table(a, b);
		width = b;
	}	
	~solver()
	{
		delete m_table;
	};

	bool solve_rook(int);
	bool solve_bishop(int);
	bool solve_pawn(int,int);
	bool solve_queen(int);

	inline bool quick_space(int,int);


	   	
};

