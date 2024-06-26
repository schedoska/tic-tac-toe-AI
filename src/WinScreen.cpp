#include "WinScreen.h"
#include "SettingsDefinitions.h"

WinScreen::WinScreen(Kolejnosc winner)
{
	int LinePos = 160;
	int LineThicness = 180;
	BackgroundColor = sf::Color(200, 200, 200, 220);

	Czcionka.loadFromFile("resources/calibril.ttf");
	WinText.setFont(Czcionka);
	
	if (winner == Kolejnosc::GRACZ_1) WinText.setString("Wygrana!");
	else if (winner == Kolejnosc::KOMPUTER) WinText.setString("Wygral Komputer!");
	else WinText.setString("Remis!");

	WinText.setFillColor(sf::Color::Black);
	WinText.setCharacterSize(75);

	BackgroudLine.setPosition(0, LinePos);
	BackgroudLine.setSize(sf::Vector2f(WINDOW_WIDTH, LineThicness));
	BackgroudLine.setFillColor(BackgroundColor);

	int Center_x = BackgroudLine.getLocalBounds().width / 2;
	int Center_y = BackgroudLine.getLocalBounds().height / 2;
	int Center_x_Text = WinText.getLocalBounds().width / 2;
	int Center_y_Text = WinText.getLocalBounds().height / 2;
	WinText.setPosition(Center_x - Center_x_Text, Center_y - Center_y_Text + BackgroudLine.getPosition().y - 20);

	JeszczeRazButton = new Button(sf::Vector2i(50, 475));
	JeszczeRazButton->setTexture("resources/JeszczeRazButton.png");
}

void WinScreen::render(sf::RenderTarget& okno)
{
	okno.draw(BackgroudLine);
	okno.draw(WinText);
	JeszczeRazButton->render(okno);
}

void WinScreen::update(sf::Vector2i mousePos)
{
	JeszczeRazButton->update(mousePos);
}

bool WinScreen::isPlayAgain()
{
	return JeszczeRazButton->isPressed();
}

