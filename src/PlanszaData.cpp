#include "PlanszaData.h"

PlanszaData::PlanszaData(int Size)
	:Size(Size)
{
	tablica = new Cell * [Size];
	for (int x = 0; x < Size; x++)
	{
		tablica[x] = new Cell[Size];
	}
	setNIC();
}

Cell PlanszaData::get(int x, int y)
{
	if (x < 0 || x >= Size || y < 0 || y >= Size) return Cell::NIC;
	return tablica[y][x];
}

void PlanszaData::place(int x, int y, Cell cellType)
{
	if (x < 0 || x >= Size || y < 0 || y >= Size) return;
	tablica[y][x] = cellType;
}

void PlanszaData::setNIC()
{
	for (int x = 0; x < Size; x++)
	{
		for (int y = 0; y < Size; y++)
		{
			tablica[y][x] = Cell::NIC;
		}
	}
}

void PlanszaData::clear()
{
	for (int q = 0; q < Size; q++)
	{
		delete[] tablica[q];
	}
	delete[] tablica;
}

int PlanszaData::getSize()
{
	return Size;
}

void PlanszaData::create(int Size)
{
	clear();
	this->Size = Size;
	tablica = new Cell * [Size];
	for (int x = 0; x < Size; x++)
	{
		tablica[x] = new Cell[Size];
	}
	setNIC();
}

PlanszaData::~PlanszaData()
{
	clear();
}

PlanszaData::PlanszaData(PlanszaData const& org)
	:Size(org.Size)
{
	tablica = new Cell * [Size];
	for (int x = 0; x < Size; x++)
	{
		tablica[x] = new Cell[Size];
	}
	for (int x = 0; x < Size; x++)
	{
		for (int y = 0; y < Size; y++)
		{
			tablica[y][x] = org.tablica[y][x];
		}
	}
}

PlanszaData& PlanszaData::operator=(const PlanszaData& org)
{
	clear();
	Size = org.Size;
	tablica = new Cell * [Size];
	for (int x = 0; x < Size; x++)
	{
		tablica[x] = new Cell[Size];
	}
	for (int x = 0; x < Size; x++)
	{
		for (int y = 0; y < Size; y++)
		{
			tablica[y][x] = org.tablica[y][x];
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Cell cell)
{
	if (cell == Cell::NIC) stream << "NIC";
	else if (cell == Cell::KOLKO) stream << "KOLKO";
	else stream << "KRZYZYK";
	return stream;
}