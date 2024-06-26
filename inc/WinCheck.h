#pragma once
#include "PlanszaData.h"

class WinCheck
{
	PlanszaData planszaData;
	int WinCondition;

	Cell checkRow(int Row);
	Cell checkColumn(int Column);
	Cell checkDiag(int TopLeft_X, int TopLeft_Y);
	Cell checkADiag(int TopRight_X, int TopRight_Y);

	int max(int TopLeft_X, int TopLeft_Y);

public:
	WinCheck();
	Cell checkWin(PlanszaData planszaData, int WinCondition);
	bool isPlanszaFull(PlanszaData planszaData);
};

