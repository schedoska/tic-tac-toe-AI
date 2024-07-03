#pragma once
#include <iostream>
#include "ListaLD.h"
#include "PlanszaData.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Plansza
{
	PlanszaData planszaData;
	int Size;
	unsigned int PlanszaRectSize;
	sf::Vector2u PlanszaRectPos;

	sf::Sprite znak;
	sf::Texture TexturaZnaku;
	float ZnakSeperation;

public:
	Plansza(unsigned int PlanszaRectSize, sf::Vector2u PlanszaRectPos);
	void crateEmptyPlansza(int Size);
	void render(sf::RenderTarget& okno);

	bool isCellEmpty(int x, int y);
	void placeCell(int x, int y, Cell cellType);

	PlanszaData getPlanszaData();
};

