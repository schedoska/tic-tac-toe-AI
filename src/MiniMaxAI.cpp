#include "MiniMaxAI.h"
#include <vector>
#include <limits>

Ruch::Ruch(int x, int y)
{
	this->x = x;
	this->y = y;
}

int MiniMaxAI::FindMax(int depth, int beta, int alfa)
{
	Wezlychecked++;
	if (depth > maxDepth) return 0;

	Cell winner = winCheck.checkWin(plansza, winAmount);
	if (winner == znak_cpu) return 100 - depth;
	else if (winner == znak_oponent) return -100 + depth;
	else if (winCheck.isPlanszaFull(plansza)) return 0;

	int Najlepszy = std::numeric_limits<int>::min();

	for (int x = 0; x < planszaSize; x++)
	{
		for (int y = 0; y < planszaSize; y++)
		{
			if (plansza.get(x, y) != Cell::NIC) continue;
			plansza.place(x, y, znak_cpu);
			int Value = FindMin(depth + 1, beta, alfa);
			plansza.place(x, y, Cell::NIC);
			
			//Funkcja FindMax 
			if (Value > Najlepszy) Najlepszy = Value;
			//alfa beta ciecia
			if (Najlepszy >= beta) return Najlepszy;
			if (Najlepszy > alfa) alfa = Najlepszy;
		}
	}
	return Najlepszy;
}

int MiniMaxAI::FindMin(int depth, int beta, int alfa)
{
	Wezlychecked++;
	if (depth > maxDepth) return 0;

	Cell winner = winCheck.checkWin(plansza, winAmount);
	if (winner == znak_cpu) return 100 - depth;
	else if (winner == znak_oponent) return -100 + depth;
	else if (winCheck.isPlanszaFull(plansza)) return 0;

	int Najlepszy = std::numeric_limits<int>::max();

	for (int x = 0; x < planszaSize; x++)
	{
		for (int y = 0; y < planszaSize; y++)
		{
			if (plansza.get(x, y) != Cell::NIC) continue;
			plansza.place(x, y, znak_oponent);
			int Value = FindMax(depth + 1, beta, alfa);
			plansza.place(x, y, Cell::NIC);

			//Funkcja FindMin 
			if (Value < Najlepszy) Najlepszy = Value;
			//alfa beta ciecia
			if (Najlepszy <= alfa) return Najlepszy;
			if (Najlepszy < beta) beta = Najlepszy;
		}
	}
	return Najlepszy;
}

Cell MiniMaxAI::findOponentZnak(Cell client_znak)
{
	if (client_znak == Cell::KOLKO) return Cell::KRZYZYK;
	else return Cell::KOLKO;
}

Ruch MiniMaxAI::znajdzNajlepszyRuch(PlanszaData planszaData, Cell znak, int winAmount)
{
	Wezlychecked = 0;
	this->znak_cpu = znak;
	this->plansza = planszaData;
	this->winAmount = winAmount;
	planszaSize = plansza.getSize();
	znak_oponent = findOponentZnak(znak_cpu);

	int Najlepszy = std::numeric_limits<int>::min();
	Ruch NajlepszyRuch(0, 0);

	int alfa = std::numeric_limits<int>::min();
	int beta = std::numeric_limits<int>::max();

	for (int x = 0; x < planszaSize; x++)
	{
		for (int y = 0; y < planszaSize; y++)
		{
			if (plansza.get(x, y) != Cell::NIC) continue;
			plansza.place(x, y, znak_cpu);
			int Value = FindMin(0, beta, alfa);
			plansza.place(x, y, Cell::NIC);

			if (Value > Najlepszy)
			{
				Najlepszy = Value;
				NajlepszyRuch = Ruch(x, y);
			}

			if (Najlepszy >= beta) return NajlepszyRuch;
			if (Najlepszy > alfa) alfa = Najlepszy;
		}
	}
	std::cout << "Sprawdzone mozliwosci: " << Wezlychecked << "\n";
	std::cout << "Best value: " << Najlepszy << "\n\n";

	return NajlepszyRuch;
}