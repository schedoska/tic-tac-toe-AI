#include "WinCheck.h"
#include <iostream>

Cell WinCheck::checkRow(int Row)
{
	int Size = planszaData.getSize();
	int KolkoCount = 0;
	int Krzyzykcount = 0;
	Cell Poprzedni = Cell::NIC;

	for (int q = 0; q < Size; q++)
	{
		Cell Aktualny = planszaData.get(q, Row);
		if (Aktualny == Cell::NIC)
		{
			KolkoCount = 0;
			Krzyzykcount = 0;
		}
		else if(Aktualny == Cell::KOLKO)
		{
			if (Poprzedni != Cell::KOLKO) KolkoCount = 1;
			else KolkoCount++;
			Poprzedni = Aktualny;
		}
		else if(Aktualny == Cell::KRZYZYK)
		{
			if (Poprzedni != Cell::KRZYZYK) Krzyzykcount = 1;
			else Krzyzykcount++;
			Poprzedni = Aktualny;
		}
		if (KolkoCount == WinCondition) return Cell::KOLKO;
		if (Krzyzykcount == WinCondition) return Cell::KRZYZYK;
	}
	return Cell::NIC;
}

Cell WinCheck::checkColumn(int Column)
{
	int Size = planszaData.getSize();
	int KolkoCount = 0;
	int Krzyzykcount = 0;
	Cell Poprzedni = Cell::NIC;

	for (int q = 0; q < Size; q++)
	{
		Cell Aktualny = planszaData.get(Column, q);
		if (Aktualny == Cell::NIC)
		{
			KolkoCount = 0;
			Krzyzykcount = 0;
		}
		else if (Aktualny == Cell::KOLKO)
		{
			if (Poprzedni != Cell::KOLKO) KolkoCount = 1;
			else KolkoCount++;
			Poprzedni = Aktualny;
		}
		else if (Aktualny == Cell::KRZYZYK)
		{
			if (Poprzedni != Cell::KRZYZYK) Krzyzykcount = 1;
			else Krzyzykcount++;
			Poprzedni = Aktualny;
		}
		if (KolkoCount == WinCondition) return Cell::KOLKO;
		if (Krzyzykcount == WinCondition) return Cell::KRZYZYK;
	}
	return Cell::NIC;
}

Cell WinCheck::checkDiag(int TopLeft_X, int TopLeft_Y)
{
	int Size = planszaData.getSize() - max(TopLeft_X, TopLeft_Y);
	int KolkoCount = 0;
	int Krzyzykcount = 0;
	Cell Poprzedni = Cell::NIC;

	for (int q = 0; q < Size; q++)
	{
		Cell Aktualny = planszaData.get(TopLeft_X + q, TopLeft_Y + q);
		if (Aktualny == Cell::NIC)
		{
			KolkoCount = 0;
			Krzyzykcount = 0;
		}
		else if (Aktualny == Cell::KOLKO)
		{
			if (Poprzedni != Cell::KOLKO) KolkoCount = 1;
			else KolkoCount++;
			Poprzedni = Aktualny;
		}
		else if (Aktualny == Cell::KRZYZYK)
		{
			if (Poprzedni != Cell::KRZYZYK) Krzyzykcount = 1;
			else Krzyzykcount++;
			Poprzedni = Aktualny;
		}
		if (KolkoCount == WinCondition) return Cell::KOLKO;
		if (Krzyzykcount == WinCondition) return Cell::KRZYZYK;
	}
	return Cell::NIC;
}

Cell WinCheck::checkADiag(int TopRight_X, int TopRight_Y)
{
	int Size = planszaData.getSize() - max(planszaData.getSize() - 1 - TopRight_X, TopRight_Y);
	int KolkoCount = 0;
	int Krzyzykcount = 0;
	Cell Poprzedni = Cell::NIC;

	for (int q = 0; q < Size; q++)
	{
		Cell Aktualny = planszaData.get(TopRight_X - q, TopRight_Y + q);
		if (Aktualny == Cell::NIC)
		{
			KolkoCount = 0;
			Krzyzykcount = 0;
		}
		else if (Aktualny == Cell::KOLKO)
		{
			if (Poprzedni != Cell::KOLKO) KolkoCount = 1;
			else KolkoCount++;
			Poprzedni = Aktualny;
		}
		else if (Aktualny == Cell::KRZYZYK)
		{
			if (Poprzedni != Cell::KRZYZYK) Krzyzykcount = 1;
			else Krzyzykcount++;
			Poprzedni = Aktualny;
		}
		if (KolkoCount == WinCondition) return Cell::KOLKO;
		if (Krzyzykcount == WinCondition) return Cell::KRZYZYK;
	}
	return Cell::NIC;
}

int WinCheck::max(int TopLeft_X, int TopLeft_Y)
{
	return (TopLeft_X > TopLeft_Y ? TopLeft_X : TopLeft_Y);
}

WinCheck::WinCheck()
{

}

Cell WinCheck::checkWin(PlanszaData planszaData, int WinCondition)
{
	this->planszaData = planszaData;
	this->WinCondition = WinCondition;

	int Size = planszaData.getSize();
	for (int q = 0; q < Size; q++)
	{
		Cell result = checkRow(q);
		if (result != Cell::NIC) return result;
	}
	for (int q = 0; q < Size; q++)
	{
		Cell result = checkColumn(q);
		if (result != Cell::NIC) return result;
	}

	Cell result = checkDiag(0, 0);
	if (result != Cell::NIC) return result;
	for (int q = 0; q < Size - WinCondition; q++)
	{
		Cell result = checkDiag(q + 1, 0);
		if (result != Cell::NIC) return result;
		result = checkDiag(0, q + 1);
		if (result != Cell::NIC) return result;
	}

	result = checkADiag(Size - 1, 0);
	if (result != Cell::NIC) return result;
	for (int q = 0; q < Size - WinCondition; q++)
	{
		Cell result = checkADiag(Size - 2 - q, 0);
		if (result != Cell::NIC) return result;
		result = checkADiag(Size - 1, q + 1);
		if (result != Cell::NIC) return result;
	}

	return Cell::NIC;
}

bool WinCheck::isPlanszaFull(PlanszaData planszaData)
{
	this->planszaData = planszaData;
	for (int x = 0; x < planszaData.getSize(); x++)
	{
		for (int y = 0; y < planszaData.getSize(); y++)
		{
			if (planszaData.get(x, y) == Cell::NIC) return false;
		}
	}
	return true;
}
