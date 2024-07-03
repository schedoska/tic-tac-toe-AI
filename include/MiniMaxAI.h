#pragma once
#include <iostream>
#include "PlanszaData.h"
#include "WinCheck.h"

struct Ruch
{
	int x;
	int y;
	Ruch(int x = 1, int y = 1);
};

class MiniMaxAI
{
	int winAmount;
	int maxDepth = 7;
	int planszaSize;
	PlanszaData plansza;

	Cell znak_cpu;
	Cell znak_oponent;

	WinCheck winCheck;
	int FindMax(int depth, int beta, int alfa);
	int FindMin(int depth, int beta, int alfa);
	Cell findOponentZnak(Cell client_znak);

	int Wezlychecked = 0;

public:
	Ruch znajdzNajlepszyRuch(PlanszaData planszaData, Cell znak, int winAmount);
};

