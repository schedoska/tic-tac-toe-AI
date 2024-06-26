#include "GameGUI.h"
#include <sstream>
#include <string>

void GameGUI::UpdateStatsValues()
{
	std::stringstream GraczWinsStream;
	GraczWinsStream << GraczWins;
	GraczStatText.setString(GraczWinsStream.str());

	std::stringstream RemisyStream;
	RemisyStream << Remisy;
	RemisStatText.setString(RemisyStream.str());

	std::stringstream CpuWinsStream;
	CpuWinsStream << CpuWins;
	CpuStatText.setString(CpuWinsStream.str());
}

void GameGUI::UpdateCzasVaules()
{
	std::stringstream GraczCzasStream;
	if (czasGracz == -1) GraczCzasStream << "-";
	else
	{
		if (czasGracz > 1000)
		{
			GraczCzasStream.precision(3);
			GraczCzasStream <<  czasGracz / 1000.f << "s";
		}
		else
		{
			GraczCzasStream << (int)czasGracz << "ms";
		}
	}
	GraczCzasText.setString(GraczCzasStream.str());

	std::stringstream CpuCzasStream;
	if (czasCpu == -1) CpuCzasStream << "-";
	else
	{
		if (czasCpu > 1000)
		{
			CpuCzasStream.precision(3);
			CpuCzasStream << czasCpu / 1000.f << "s";
		}
		else
		{
			CpuCzasStream << (int)czasCpu << "ms";
		}
	}
	CpuCzasText.setString(CpuCzasStream.str());
}

GameGUI::GameGUI(sf::Vector2i pos)
{
	//Statystyki zwyciestw
	int StatTextsHeight = 80;

	statystykaTableTxt.loadFromFile("resources/StatystykaTable.png");
	statystykaTabale.setTexture(statystykaTableTxt);
	statystykaTabale.setPosition(pos.x, pos.y);

	Czcionka.loadFromFile("resources/calibril.ttf");
	GraczStatText.setFont(Czcionka);
	GraczStatText.setCharacterSize(30);
	GraczStatText.setFillColor(sf::Color::Black);
	GraczStatText.setPosition(pos.x + 35, pos.y + StatTextsHeight);

	RemisStatText.setFont(Czcionka);
	RemisStatText.setCharacterSize(30);
	RemisStatText.setFillColor(sf::Color::Black);
	RemisStatText.setPosition(pos.x + 135, pos.y + StatTextsHeight);

	CpuStatText.setFont(Czcionka);
	CpuStatText.setCharacterSize(30);
	CpuStatText.setFillColor(sf::Color::Black);
	CpuStatText.setPosition(pos.x + 235, pos.y + StatTextsHeight);

	UpdateStatsValues();

	//Statystyki czasu
	int CzasTextsHeight = 80;
	pos = sf::Vector2i(pos.x, pos.y + 140);

	czasTableTxt.loadFromFile("resources/CzasTable.png");
	czasTable.setTexture(czasTableTxt);
	czasTable.setPosition(pos.x, pos.y);

	GraczCzasText.setFont(Czcionka);
	GraczCzasText.setCharacterSize(30);
	GraczCzasText.setFillColor(sf::Color::Black);
	GraczCzasText.setPosition(pos.x + 45, pos.y + CzasTextsHeight);

	CpuCzasText.setFont(Czcionka);
	CpuCzasText.setCharacterSize(30);
	CpuCzasText.setFillColor(sf::Color::Black);
	CpuCzasText.setPosition(pos.x + 195, pos.y + CzasTextsHeight);

	UpdateCzasVaules();

	GameResetButton = new Button(sf::Vector2i(pos.x, 330));
	GameResetButton->setTexture("resources/RestartGryButton.png");

	StatystykiResetButton = new Button(sf::Vector2i(pos.x, 395));
	StatystykiResetButton->setTexture("resources/StatystykaResetButton.png");
}

void GameGUI::render(sf::RenderTarget& okno)
{
	okno.draw(statystykaTabale);
	okno.draw(GraczStatText);
	okno.draw(RemisStatText);
	okno.draw(CpuStatText);

	okno.draw(czasTable);
	okno.draw(GraczCzasText);
	okno.draw(CpuCzasText);

	GameResetButton->render(okno);
	StatystykiResetButton->render(okno);
}

void GameGUI::update(sf::Vector2i mousePos)
{
	GameResetButton->update(mousePos);
	StatystykiResetButton->update(mousePos);

	if (StatystykiResetButton->isPressed())
	{
		GraczWins = 0;
		Remisy = 0;
		CpuWins = 0;
		UpdateStatsValues();
	}
}

void GameGUI::AddWin(Kolejnosc winner)
{
	if (winner == Kolejnosc::GRACZ_1) GraczWins++;
	else if (winner == Kolejnosc::KOMPUTER) CpuWins++;
	else Remisy++;
	UpdateStatsValues();
}

void GameGUI::SetCzas(float time, Kolejnosc who)
{
	if (who == Kolejnosc::GRACZ_1)
		czasGracz = time;
	else if (who == Kolejnosc::KOMPUTER)
		czasCpu = time;
	UpdateCzasVaules();
}

void GameGUI::resetTime()
{
	czasCpu = -1;
	czasGracz = -1;
	UpdateCzasVaules();
}

bool GameGUI::isGameReset()
{
	return GameResetButton->isPressed();
}

