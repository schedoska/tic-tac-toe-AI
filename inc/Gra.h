#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <chrono>
#include "SettingsDefinitions.h"
#include "Grid.h"
#include "Plansza.h"
#include "Player.h"
#include "MenuGUI.h"
#include "WinScreen.h"
#include "GameGUI.h"
#include "MiniMaxAI.h"

class Gra
{
	sf::RenderWindow okno;
	sf::Event evento;

	GameGUI* gamegui;
	MenuGUI *menu;
	WinScreen* winscreen;

	Grid* siatka;
	Plansza* plansza;

	Player* gracz1;
	Cell gracz1_znak;
	Player* komputer;
	MiniMaxAI* komputer_alt;
	Cell komputer_znak;

	Kolejnosc kolejnosc;
	GameSettings gameSettings;
	State currentState;

	Kolejnosc winner;

	void gameUpdate();
	void initNewGame();
	void checkEndGame();

	std::chrono::steady_clock::time_point start_t, end_t;

public:
	Gra();
	void start();
};

