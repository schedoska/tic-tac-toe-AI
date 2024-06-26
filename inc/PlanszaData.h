#pragma once
#include <iostream>

enum class Cell { KOLKO = 1, KRZYZYK = 2, NIC = 0 };

class PlanszaData
{
	Cell** tablica;
	int Size;

public:
	PlanszaData(int Size = 3);
	Cell get(int x, int y);
	void place(int x, int y, Cell cellType);
	void setNIC();
	void clear();
	int getSize();
	void create(int Size);

	~PlanszaData();
	PlanszaData(PlanszaData const& org);
	PlanszaData& operator=(const PlanszaData& org);
};

std::ostream& operator<< (std::ostream& stream, const Cell cell);
