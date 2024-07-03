#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "ArrowButtons.h"
#include "SettingsDefinitions.h"

class WinScreen
{
	sf::RectangleShape BackgroudLine;
	sf::Color BackgroundColor;

	sf::Font Czcionka;
	sf::Text WinText;

	Button* JeszczeRazButton;

public:
	WinScreen(Kolejnosc winner);
	void render(sf::RenderTarget& okno);
	void update(sf::Vector2i mousePos);
	bool isPlayAgain();
};

