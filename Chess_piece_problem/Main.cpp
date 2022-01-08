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

	
	table->m_table[0] = ROOK; // putting in a random rook for testing purposes
	bool retval = sol->solve_rook(7); //solv for a theoretical rook, to test hit detection
	
	/*eg the 0 / 7 config should return 1 or true, as 0 is on the 1. col & 7 is in the last one & are not in the same row*/

	table->output(table->m_table, std::get<0>(size));

	std::cout <<"retval: " << retval << std::endl;
	
}
	


int main()
{
	solve({ 0,0 }, {4,6}); //00 would be starting pistion that's not used atm, and the second set if numbers are the size

	
	

	return 0;
}
