#pragma once
#include "Headers.h"
//this implementation should allow for variable run or compile time size changes.

class Table
{
public:


	///wiretes something in 1d position
	inline auto place(int a);
	inline auto dimensons();
	inline void hashMe();
	inline void toString();

	void output(std::vector<char> m_table, int col);

	///copy constructor
	Table(const Table &t2)
		/*: m_table(t2.m_table),
		m_num_row(t2.m_num_row),
		m_num_col(t2.m_num_col),
		m_hash(t2.m_hash),
		m_string(t2.m_string)*/
	{
		m_table = t2.m_table;
		m_num_col = t2.m_num_col;
		m_num_row = t2.m_num_row;
		m_hash = t2.m_hash;
		m_string = t2.m_string;
	};
	
	///default constructor for size 	//width, lenght
	Table(int a, int b)
	{
		m_num_col = a;
		m_num_row = b;
		for (int i = 0; i < a*b; ++i)
		{
			this->m_table.push_back(' ');
		}

	};

	~Table(){};

	inline auto outString()
	{
		return this->m_string;
	}
	
	std::vector<char> m_table;
	int m_num_col;
	int m_num_row;
private:
	//the table itself
	
	
	
	//hash for comperator
	int m_hash;
	//outstring substring for comperator
	std::string m_string;


};

