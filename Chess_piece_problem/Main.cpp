#include "Headers.h"
#include "Table.h"
#include "solver.h"
//very importatnt every adress starts from 0!!!

void solve(std::tuple<int, int> start_pos = { 0,0 }, std::tuple<int, int> size = { 0,0 })
{
	Table *table = new ::Table(std::get<0>(size), std::get<1>(size));
	solver *sol = new solver( table);
	//sor, bal oldalt || row
	int a = std::get<0>(start_pos);
	//oszlop, fent || column
	int b = std::get<1>(start_pos);

	int sp = 0;

	
	table->m_table[0] = ROOK;
	bool retval = sol->solve_rook(8);
	

	table->output(table->m_table, std::get<0>(size));

	std::cout <<"retval: " << retval << std::endl;
	
}
	


int main()
{
	solve({ 0,0 }, {4,6});

	
	

	return 0;
}
