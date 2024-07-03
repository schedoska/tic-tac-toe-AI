#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "ArrowButtons.h"
#include "PlanszaData.h"

struct GameSettings
{
	int PlanszaSize = 3;
	int IloscDoWygranej = 3;
	Cell ZnakGracz1 = Cell::KRZYZYK;
};

class MenuGUI
{
	bool m_Rozpocznij;
	GameSettings *gameSettings;

	sf::Color FontColor;
	sf::Color BackGroundColor;

	//Rozmiar Planszy
	sf::Text* RozmiarPlanszyText;
	sf::Text* RozpmiarPlanszyValue;
	sf::RectangleShape RozmiarPlanszyBackground;
	ArrowButtons* RozmiarPlanszyButtons;

	//ilosc do wygranej
	sf::Text* IloscWygranaText;
	sf::Text* IloscWygranaValue;
	sf::RectangleShape IloscWygranaBackground;
	ArrowButtons* IloscWygranejButtons;

	//Wybor znaku gracza
	sf::Texture znakTxt;
	sf::Text* WyborZnakuGraczText;
	sf::Text* WyborZnakuCpuText;
	sf::RectangleShape WyborBackground;
	sf::Sprite znak;
	sf::Vector2f ZnakFieldPos;
	Button* GraczButton;
	Button* CpuButton;
	void renderZnakField(sf::RenderTarget& okno);

	//Rozpocznij przycisk
	Button* RozpocznijButton;

	//TloMenu
	sf::RectangleShape Tlo;

	sf::Font Czcionka;
	void init_RozmiarPlanszyField(sf::Vector2f FeildPos);
	void init_IloscDoWygranejField(sf::Vector2f FeildPos);
	void init_WyborZnakuField(sf::Vector2f FeildPos);

	void updateValueTexts();

public:
	MenuGUI(GameSettings *gameSettings = nullptr);
	void render(sf::RenderTarget& okno);
	void update(sf::Vector2i MousePos);
	bool isReadyToSatart();
};


