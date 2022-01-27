#include "Headers.h"
#include "Table.h"
#include "solver.h"
//very importatnt every adress starts from 0!!!
enum PICE { queen, rook, bishop };

namespace outT
{
	int output = 0;
}

void solve_for_queen(std::list<ledger> led, std::tuple<int, int> size, int depth = 0)
{
	
	//making size multiple use
	int size_a = std::get<0>(size), size_b = std::get<1>(size); 


	int start_pos = depth * size_a;//where to start 1 iteration



	//creating a new solver for each iteration
	solver *sol = new solver(size, led);

	if (start_pos >= size_a * size_b) //checking if we're finished
	{
		std::cout << "start pos: " << start_pos << std::endl;
		if (depth == size_b)
		{

			sol->m_table->output(sol->m_table->m_table, size_a);
			outT::output++;
			std::cout << "output: " << outT::output << std::endl;
			return;

		}
		
	}

	//checking on the depth counter, if we're "too" deep

		for (int i = start_pos; i < start_pos + size_a; ++i) //row iteration for depth
		{

			bool a = sol->solve_queen(i); //checking if we can place down a queen to give loacation
			
			if (a)
			{
				std::list<ledger> tled = led;
				sol->m_table->m_table[i] = QUEEN;
				tled = led;
				tled.push_back({ i,0,0 });
				solve_for_queen(tled, { size_a, size_b }, depth + 1);
			}
			sol->m_table->m_table[i] = SPACE;

		}

	delete sol;
};

void solve(std::tuple<int, int> start_pos, std::tuple<int, int> size, PICE piece = queen)
{
	
	int a = std::get<0>(start_pos);// || column
	int b = std::get<1>(start_pos);// || row
	int size_a = std::get<0>(size);
	int size_b = std::get<1>(size);
	
	//calculating starting position
	int pos = 0; 
	if(b == 0)
		pos += a;
	else
		pos = (b - 1)* size_a +(a-1);

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
	}

	
	/*std::list<ledger> led = { {0,0,0} };
	solver *solv = new solver(size,led);
	
	//8 is edge case
	int a = 7;
	bool b = solv->solve_bishop(a);


	std::cout <<"b: "<< b << std::endl;
	solv->m_table->m_table[a] = 'b';
	solv->m_table->output(solv->m_table->m_table, solv->m_table->m_num_col);*/

	


	
}


void solve_for_rook() {};
void solve_for_bishop() {};


int main()
{
	int a, b;
	std::cin >> a;
	std::cin >> b;

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	
	solve({ 0,0 }, { a,b }, queen); //00 would be starting pistion that's not used atm, and the second set if numbers are the size
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;


	return 0;
}
