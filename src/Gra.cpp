#include "Gra.h"
#include "MouseDriver.h"
#include "WinCheck.h"
#include <random>

void Gra::gameUpdate()
{
	if (kolejnosc == Kolejnosc::GRACZ_1)
	{
		gracz1->inputUpdate(sf::Mouse::getPosition(okno));
		sf::Vector2i chosenCell = gracz1->readChosenCell();
		if (plansza->isCellEmpty(chosenCell.x, chosenCell.y))
		{
			plansza->placeCell(chosenCell.x, chosenCell.y, gracz1_znak);
			kolejnosc = Kolejnosc::KOMPUTER;
			end_t = std::chrono::steady_clock::now();
			gamegui->SetCzas(std::chrono::duration <double, std::milli>(end_t - start_t).count(), Kolejnosc::GRACZ_1);
			start_t = std::chrono::steady_clock::now();
			checkEndGame();
		}
	}
	else
	{
		Ruch ruch = komputer_alt->znajdzNajlepszyRuch(plansza->getPlanszaData(), komputer_znak, gameSettings.IloscDoWygranej);
		plansza->placeCell(ruch.x, ruch.y, komputer_znak);
		kolejnosc = Kolejnosc::GRACZ_1;
		end_t = std::chrono::steady_clock::now();
		gamegui->SetCzas(std::chrono::duration <double, std::milli>(end_t - start_t).count(), Kolejnosc::KOMPUTER);
		start_t = std::chrono::steady_clock::now();
		checkEndGame();
	}
}

void Gra::initNewGame()
{
	siatka->changeKratkiSet(gameSettings.PlanszaSize, gameSettings.PlanszaSize);
	plansza->crateEmptyPlansza(gameSettings.PlanszaSize);
	gracz1_znak = gameSettings.ZnakGracz1;
	komputer_znak = (gracz1_znak == Cell::KOLKO ? Cell::KRZYZYK : Cell::KOLKO);

	delete menu;
	menu = nullptr;
	currentState = State::GAME_STATE;
	start_t = std::chrono::steady_clock::now();
	gamegui->resetTime();
	kolejnosc = (rand() % 2 ? Kolejnosc::GRACZ_1 : Kolejnosc::KOMPUTER);
}

void Gra::checkEndGame()
{
	WinCheck wincheck;
	Cell m_winner = wincheck.checkWin(plansza->getPlanszaData(), gameSettings.IloscDoWygranej);
	if (m_winner != Cell::NIC || wincheck.isPlanszaFull(plansza->getPlanszaData()))
	{
		currentState = State::IDLE_STATE;
		if (m_winner == gracz1_znak) winner = Kolejnosc::GRACZ_1;
		else if (m_winner == komputer_znak) winner = Kolejnosc::KOMPUTER;
		else winner = Kolejnosc::NIKT;
		gamegui->AddWin(winner);
	}
}

Gra::Gra()
{
	okno.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Kolko i Krzyzyk", sf::Style::Titlebar | sf::Style::Close);
	okno.setFramerateLimit(20);
	menu = nullptr;
	winscreen = nullptr;

	siatka = new Grid(3, 3, sf::Vector2u(50, 50), sf::Vector2u(400, 400));
	plansza = new Plansza(400, sf::Vector2u(50, 50));
	gracz1 = new Player(siatka);
	komputer = new Player(siatka);
	komputer_alt = new MiniMaxAI();
	gamegui = new GameGUI(sf::Vector2i(480, 50));

	plansza->crateEmptyPlansza(3);
	kolejnosc = Kolejnosc::GRACZ_1;
	currentState = State::MENU_STATE;
	srand(time(NULL));
}

void Gra::start()
{
	while (okno.isOpen()) {
		while (okno.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				okno.close();
			}
		}
		okno.clear(sf::Color::White);
		MouseDriver::update();

		if (currentState == State::GAME_STATE)
		{
			siatka->update(sf::Mouse::getPosition(okno));
			gamegui->update(sf::Mouse::getPosition(okno));
			if (gamegui->isGameReset())
			{
				currentState = State::MENU_STATE;
			}
			gameUpdate();
		}

		siatka->render(okno);
		plansza->render(okno);
		gamegui->render(okno);
		
		if (currentState == State::MENU_STATE)
		{
			if(menu == nullptr) menu = new MenuGUI(&gameSettings);
			menu->update(sf::Mouse::getPosition(okno));
			menu->render(okno);
			if (menu->isReadyToSatart())
			{
				initNewGame();
			}
		}

		if (currentState == State::IDLE_STATE)
		{
			if (winscreen == nullptr) winscreen = new WinScreen(winner);
			winscreen->update(sf::Mouse::getPosition(okno));
			winscreen->render(okno);
			if (winscreen->isPlayAgain())
			{
				delete winscreen;
				winscreen = nullptr;
				currentState = State::MENU_STATE;
			}
		}

		okno.display();
	}
}
