#include "Player.h"
#include "MouseDriver.h"

Player::Player(Grid *grid)
	:grid(grid)
{
	isMyTurn = false;
}

void Player::inputUpdate(sf::Vector2i mousePos)
{
	if (MouseDriver::isMouseLeftClicked())
	{
		if (!grid->isInRect(mousePos))
		{
			chosenCell = sf::Vector2i(-1, -1);
		}
		else
		{
			chosenCell = grid->CellPos(mousePos);
		}
	}
	else
	{
		chosenCell = sf::Vector2i(-1, -1);
	}
}

sf::Vector2i Player::readChosenCell()
{
	return chosenCell;
}

void Player::setIsMyTurn(bool isMyTurn)
{
	this->isMyTurn = isMyTurn;
}

