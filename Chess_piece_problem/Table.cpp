#include "Table.h"
#include "solver.h"



inline auto Table::place(int a)
{
	m_table.at(a) = 'x';
};
void Table::hashMe()
{
	this->toString();
	this->m_hash= std::hash<std::string>{}(this->m_string);
};
///outputs the talbe in a string, unformatted
void Table::toString()
{
	for ( auto element : this->m_table)
	{
		this->m_string += element;
	}
}
///defines the dimensons of the table
inline auto Table::dimensons()
{
	return std::make_tuple(this->m_num_col, this->m_num_row);
};
///m_table is the lenght of the table, col is the number of columns
void Table::output(std::vector<char> m_table, int col)
{
	int i = 0;

	
	for (auto e : m_table)
	{

		if (i % (col) == 0)
		{

			if (i != 0)
				std::cout << std::endl;

		}
		std::cout <<"["<< e <<"]";
		++i;
	}
	std::cout << std::endl;
}


void Table::fileoutput( std::list<ledger> a)
{

}
