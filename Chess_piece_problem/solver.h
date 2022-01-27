#pragma once
#include "Table.h"
#include "Headers.h"


class solver
{

public:
	Table *m_table;
	int height;
	int width;


	solver( Table *table)
		:m_table(table)
	{
		height=table->m_num_col;
	}
	//width, lenght
	solver(int a, int b, std::list<ledger> led)
	{
		m_table = new Table(a, b);
		height = b;
		width = a;
	}	

	solver(std::tuple<int, int> size, std::list<ledger> led, int piece = QUEEN)
	{
		int a = std::get<0>(size);
		int b = std::get<1>(size);
		m_table = new Table(a, b);
		height = b;
		width = a;

		for (auto le : led)
		{
			m_table->m_table[le.pos] = 'Q';
			//std::cout << "WHAT THE ACTUAL:" << le.pos << std::endl;
		}
		//m_table->output(m_table->m_table, 6);
		//std::cout << "creating a solver " << std::endl;
	
	}

	~solver()
	{
		delete m_table;
		//std::cout << "deleting a solver " << std::endl;
	};

	bool solve_rook(int);
	bool solve_bishop(int);
	bool solve_pawn(int,int);
	bool solve_queen(int);

	inline bool quick_space(int,int);


	   	
};

