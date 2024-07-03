#include "Grid.h"
#include <iostream>

Grid::Grid(int X_kratki, int Y_kratki, sf::Vector2u GridPos, sf::Vector2u GridSize)
	:X_kratki(X_kratki), Y_kratki(Y_kratki), GridPos(GridPos), GridSize(GridSize)
{
	LineThicness = 2;
	LineColor = sf::Color(150,150,150);
	KursorColor = sf::Color(0, 0, 0, 20);

	GridKursor.setFillColor(KursorColor);
	GridKursor.setPosition(100, 100);
	changeKratkiSet(X_kratki, Y_kratki);
}

Grid::~Grid()
{
	RemoveAllLines();
}

void Grid::render(sf::RenderTarget& okno)
{
	if(isKursorVisible)
	okno.draw(GridKursor);

	for (size_t q = 0; q < PionoweLinie.size(); q++)
	{
		okno.draw(*PionoweLinie[q]);
	}
	for (size_t q = 0; q < PoziomeLinie.size(); q++)
	{
		okno.draw(*PoziomeLinie[q]);
	}
}

void Grid::changeKratkiSet(int X_kratki, int Y_kratki)
{
	RemoveAllLines();

	this->X_kratki = X_kratki;
	this->Y_kratki = Y_kratki;

	float Pionowe_LineSeperation = (float)GridSize.x / (float)X_kratki;
	float Poziome_LineSeperation = (float)GridSize.y / (float)Y_kratki;

	for (int q = 0; q < X_kratki + 1; q++)
	{
		sf::RectangleShape* Linia = new sf::RectangleShape(sf::Vector2f(LineThicness, GridSize.y + LineThicness));
		Linia->setPosition(GridPos.x + q * Pionowe_LineSeperation, GridPos.y);
		Linia->setFillColor(LineColor);
		PionoweLinie.push_back(Linia);
	}
	for (int q = 0; q < Y_kratki + 1; q++)
	{
		sf::RectangleShape* Linia = new sf::RectangleShape(sf::Vector2f(GridSize.x + LineThicness, LineThicness));
		Linia->setPosition(GridPos.x, GridPos.y + q * Poziome_LineSeperation);
		Linia->setFillColor(LineColor);
		PoziomeLinie.push_back(Linia);
	}
	GridKursor.setSize(sf::Vector2f(Poziome_LineSeperation, Pionowe_LineSeperation));
}

void Grid::update(sf::Vector2i MousePos)
{
	if (isInRect(MousePos))
	{
		isKursorVisible = true;
	}
	else isKursorVisible = false;
	
	float Pionowe_LineSeperation = (float)GridSize.x / (float)X_kratki;
	float Poziome_LineSeperation = (float)GridSize.y / (float)Y_kratki;
	sf::Vector2i Cell_Pos = CellPos(MousePos);
	GridKursor.setPosition(Cell_Pos.x * Pionowe_LineSeperation + GridPos.x, 
							Cell_Pos.y * Poziome_LineSeperation + GridPos.y);
}

void Grid::RemoveAllLines()
{
	for (size_t q = 0; q < PionoweLinie.size(); q++)
	{
		delete PionoweLinie[q];
	}
	for (size_t q = 0; q < PoziomeLinie.size(); q++)
	{
		delete PoziomeLinie[q];
	}
	PionoweLinie.clear();
	PoziomeLinie.clear();
}

sf::Vector2i Grid::CellPos(sf::Vector2i MousePos)
{
	int X_relativePos = MousePos.x - GridPos.x;
	int Y_relativePos = MousePos.y - GridPos.y;

	int X_gridPos = X_relativePos / GridKursor.getSize().x;
	int Y_gridPos = Y_relativePos / GridKursor.getSize().y;

	if (X_gridPos > X_kratki - 1) X_gridPos = X_kratki - 1;
	if (Y_gridPos > Y_kratki - 1) Y_gridPos = Y_kratki - 1;
	if (X_gridPos < 0) X_gridPos = 0;
	if (Y_gridPos < 0) Y_gridPos = 0;

	return sf::Vector2i(X_gridPos, Y_gridPos);
}

bool Grid::isInRect(sf::Vector2i MousePos)
{
	sf::IntRect Gridrect(GridPos.x, GridPos.y, GridSize.x, GridSize.y);
	return Gridrect.contains(MousePos);
}
