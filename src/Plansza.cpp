#include "Plansza.h"
#include <iostream>

Plansza::Plansza(unsigned int PlanszaRectSize, sf::Vector2u PlanszaRectPos)
{
	this->PlanszaRectPos = PlanszaRectPos;
	this->PlanszaRectSize = PlanszaRectSize;

	if (!TexturaZnaku.loadFromFile("resources/Znak.png"))
	{
		std::cout << "Bark folderu resources!\nUruchum aplikacje w miejscy zawierajacym folder resources\n";
	}
	TexturaZnaku.setSmooth(true);
	znak.setTexture(TexturaZnaku);
}

void Plansza::crateEmptyPlansza(int Size)
{
	this->Size = Size;
	planszaData.create(Size);
	ZnakSeperation = (float)PlanszaRectSize / (float)Size;
	float scale = (float)ZnakSeperation / (float)TexturaZnaku.getSize().y;
	znak.setScale(scale, scale);
}

void Plansza::render(sf::RenderTarget& okno)
{
	int ZnakSize = TexturaZnaku.getSize().x / 3;

	for (int x = 0; x < Size; x++)
	{
		for (int y = 0; y < Size; y++)
		{
			znak.setPosition(PlanszaRectPos.x + x * ZnakSeperation, PlanszaRectPos.y + y * ZnakSeperation);
			if (planszaData.get(x, y) == Cell::NIC)
				znak.setTextureRect(sf::IntRect(2 * ZnakSize, 0, ZnakSize, ZnakSize));
			else if(planszaData.get(x, y) == Cell::KOLKO)
				znak.setTextureRect(sf::IntRect(ZnakSize, 0, ZnakSize, ZnakSize));
			else
				znak.setTextureRect(sf::IntRect(0, 0, ZnakSize, ZnakSize));
			okno.draw(znak);
		}
	}
}

bool Plansza::isCellEmpty(int x, int y)
{
	if (x >= Size || x < 0 || y >= Size || y < 0) return false;
	if (planszaData.get(x, y) == Cell::NIC) return true;
	else return false;
}

void Plansza::placeCell(int x, int y, Cell cellType)
{
	planszaData.place(x, y, cellType);
}

PlanszaData Plansza::getPlanszaData()
{
	return planszaData;
}
