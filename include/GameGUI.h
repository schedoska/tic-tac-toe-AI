#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "SettingsDefinitions.h"
#include "ArrowButtons.h"

class GameGUI
{
	sf::Font Czcionka;

	//Statystyki zwyciestw
	int GraczWins = 0;
	int Remisy = 0;
	int CpuWins = 0;
	sf::Texture statystykaTableTxt;
	sf::Sprite statystykaTabale;
	sf::Text GraczStatText, RemisStatText, CpuStatText;
	void UpdateStatsValues();

	//Statystyki Czasu
	float czasGracz = -1;
	float czasCpu = -1;
	sf::Texture czasTableTxt;
	sf::Sprite czasTable;
	sf::Text GraczCzasText, CpuCzasText;
	void UpdateCzasVaules();

	//Przyciski pomocnicze
	Button* GameResetButton;
	Button* StatystykiResetButton;

public:
	GameGUI(sf::Vector2i pos);
	void render(sf::RenderTarget& okno);
	void update(sf::Vector2i mousePos);

	void AddWin(Kolejnosc winner);
	void SetCzas(float time, Kolejnosc who);
	void resetTime();

	bool isGameReset();
};

