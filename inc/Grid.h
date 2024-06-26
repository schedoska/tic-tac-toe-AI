#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Grid
{
	int X_kratki, Y_kratki;
	sf::Vector2u GridPos, GridSize;

	std::vector<sf::RectangleShape*> PionoweLinie;
	std::vector<sf::RectangleShape*> PoziomeLinie;

	int LineThicness;
	sf::Color LineColor;
	sf::Color KursorColor;

	sf::RectangleShape GridKursor;
	bool isKursorVisible;

	void RemoveAllLines();

public:
	Grid(int X_kratki, int Y_kratki, sf::Vector2u GridPos, sf::Vector2u GridSize);
	~Grid();
	void render(sf::RenderTarget& okno);
	void changeKratkiSet(int X_kratki, int Y_kratki);
	void update(sf::Vector2i MousePos);

	bool isInRect(sf::Vector2i MousePos);
	sf::Vector2i CellPos(sf::Vector2i MousePos);
};

