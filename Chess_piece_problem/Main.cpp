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

	//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//table->m_table[0] = ROOK; // putting in a random rook for testing purposes

	//table->m_table[5] = ROOK;
	bool retval = sol->solve_bishop(0); //solv for a theoretical rook, to test hit detection
	//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

	/*eg the 0 / 7 config should return 1 or true, as 0 is on the 1. col & 7 is in the last one & are not in the same row*/

	table->output(table->m_table, std::get<0>(size));

	std::cout <<"retval: " << retval << std::endl;
	
}
	


int main()
{
	solve({ 0,0 }, {4,6}); //00 would be starting pistion that's not used atm, and the second set if numbers are the size

	
	

	return 0;
}
