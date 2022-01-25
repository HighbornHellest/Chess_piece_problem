#include "Headers.h"
#include "Table.h"
#include "solver.h"
//very importatnt every adress starts from 0!!!
enum PICE { queen, rook, bishop };



void solve_for_queen(std::list<ledger> led, std::tuple<int, int> size, int depth = 0)
{
	solver *sol = new solver(size, led);
	int size_a = std::get<0>(size), size_b = std::get<1>(size);
	
	std::cout << "ledger: ";
	for (auto le : led)
	{
		std::cout << le.pos <<" ";
	}
	std::cout<<std::endl;
	int start_pos = depth * size_a;


	if(depth < 8)
	{
		for (int i = start_pos; i < start_pos+size_a; ++i)
		{
			bool a = sol->solve_queen(i);
			std::list<ledger> tled = led;
			std::cout << a << std::endl;
			if (a)
			{
				sol->m_table->m_table[i] = QUEEN;
				tled = led;
				tled.push_back({ i,0,0 });
				
				sol->m_table->output(sol->m_table->m_table,size_a);
				std::cout << "size_A" << size_a << std::endl;
				std::cout << "size_b" << size_b << std::endl;
				solve_for_queen(tled, {size_a, size_b}, depth + 1);
			}
			sol->m_table->m_table[i] = SPACE;
		}
	}

};

void solve(std::tuple<int, int> start_pos, std::tuple<int, int> size, PICE piece = queen)
{
	/*// || column
	int a = std::get<0>(start_pos);
	// || row
	int b = std::get<1>(start_pos);

	int size_a = std::get<0>(size);
	int size_b = std::get<1>(size);
	
	int pos = 0;

	if(b == 0)
		pos += a;
	else
		pos = (b - 1)* size_a +(a-1);

	std::cout << pos << std::endl;

	std::list <ledger> led;

	switch (piece)
	{
	case 0:
	{
		solve_for_queen(led, {size_a, size_b});
		break;
	}
	case 1:
	{
		break;
	}
	case 2:
	{
		break;
	}

	default:
		break;
	}*/

	
	std::list<ledger> led = { {27,0,0} };
	solver *solv = new solver(size,led);
	
	int a = 20;
	bool b = solv->solve_bishop(a);

	std::cout <<"b: "<< b << std::endl;
	solv->m_table->m_table[a] = 'b';
	solv->m_table->output(solv->m_table->m_table, solv->m_table->m_num_col);

	


	
}



void solve_for_rook() {};
void solve_for_bishop() {};

	


int main()
{


	solve({ 0,0 }, {6,5}, queen ); //00 would be starting pistion that's not used atm, and the second set if numbers are the size



	return 0;
}
