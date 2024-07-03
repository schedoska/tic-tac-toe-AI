#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Grid.h"

class Player
{
	Grid *grid;
	bool isMyTurn;

	sf::Vector2i chosenCell;

public:
	Player(Grid *grid);
	void inputUpdate(sf::Vector2i mousePos);
	sf::Vector2i readChosenCell();
	void setIsMyTurn(bool isMyTurn);
};

