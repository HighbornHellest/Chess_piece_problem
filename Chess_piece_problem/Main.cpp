#include "Headers.h"
#include "Table.h"
#include "solver.h"
//very importatnt every adress starts from 0!!!

void solve(std::tuple<int, int> start_pos = { 0,0 }, std::tuple<int, int> size = { 8,8 })
{
	Table *table = new ::Table(std::get<0>(size), std::get<1>(size));
	//sor, bal oldalt || row
	int a = std::get<0>(start_pos);
	//oszlop, fent || column
	int b = std::get<1>(start_pos);


	table->output(table->m_table, std::get<0>(size));
}
	


int main()
{
	solve({ 0,0 }, {5,4});

	
	

	return 0;
}
