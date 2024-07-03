#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>

class ArrowButtons
{
	sf::Texture ArrowButtonTexture;
	int TileSize;
	int ButtonSeperation;
	sf::Vector2i ButtonsPos;

	sf::Sprite RightArrow;
	sf::Sprite LeftArrow;

	bool RightLastState;
	bool LeftLastState;

	bool m_isRightPressed;
	bool m_isLeftPressed;

public:
	ArrowButtons(sf::Vector2i ButtonsPos);
	void setPos(sf::Vector2i ButtonsPos);
	void render(sf::RenderTarget& okno);
	void update(sf::Vector2i MousePos);

	bool isRightPressed();
	bool isLeftPressed();
};

class Button
{
	sf::Texture ButtonTxt;
	int TileSizeX;
	int TileSizeY;
	sf::Vector2i ButtonPos;

	bool LastState;
	bool m_isPressed;

	sf::Sprite Button_sprite;

public:
	Button(sf::Vector2i ButtonsPos);
	void setPos(sf::Vector2i ButtonsPos);
	void render(sf::RenderTarget& okno);
	void update(sf::Vector2i mousePos);
	void setTexture(std::string fileName);
	bool isPressed();
};

