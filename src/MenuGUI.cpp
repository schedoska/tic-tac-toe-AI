#include "MenuGUI.h"
#include <string>
#include <sstream>

void MenuGUI::renderZnakField(sf::RenderTarget& okno)
{
	int ZnakTile = znakTxt.getSize().y;

	okno.draw(*WyborZnakuGraczText);
	okno.draw(*WyborZnakuCpuText);

	WyborBackground.setPosition(ZnakFieldPos + sf::Vector2f(340,0));
	okno.draw(WyborBackground);

	znak.setPosition(ZnakFieldPos + sf::Vector2f(360, -3));
	if (gameSettings->ZnakGracz1 == Cell::KRZYZYK) znak.setTextureRect(sf::IntRect(0, 0, ZnakTile, ZnakTile));
	else znak.setTextureRect(sf::IntRect(ZnakTile, 0, ZnakTile, ZnakTile));
	okno.draw(znak);

	WyborBackground.setPosition(ZnakFieldPos + sf::Vector2f(340, 80));
	okno.draw(WyborBackground);

	znak.setPosition(ZnakFieldPos + sf::Vector2f(360, 78));
	if (gameSettings->ZnakGracz1 == Cell::KRZYZYK) znak.setTextureRect(sf::IntRect(ZnakTile, 0, ZnakTile, ZnakTile));
	else znak.setTextureRect(sf::IntRect(0, 0, ZnakTile, ZnakTile));
	okno.draw(znak);

	GraczButton->render(okno);
	CpuButton->render(okno);
}

void MenuGUI::init_RozmiarPlanszyField(sf::Vector2f FeildPos)
{
	int Backgrund_sep = 340;
	int Buttons_sep = 160;

	RozmiarPlanszyText = new sf::Text("Rozmiar planszy", Czcionka, 40);
	RozmiarPlanszyText->setPosition(FeildPos + sf::Vector2f(0, 10));
	RozmiarPlanszyText->setFillColor(FontColor);

	RozpmiarPlanszyValue = new sf::Text("3x3", Czcionka, 30);
	RozpmiarPlanszyValue->setPosition(FeildPos + sf::Vector2f(Backgrund_sep + 10, 15));
	RozpmiarPlanszyValue->setFillColor(FontColor);

	RozmiarPlanszyBackground.setOutlineColor(BackGroundColor);
	RozmiarPlanszyBackground.setOutlineThickness(3);
	RozmiarPlanszyBackground.setPosition(FeildPos.x + Backgrund_sep, FeildPos.y + 8);
	RozmiarPlanszyBackground.setSize(sf::Vector2f(110,60));
	RozmiarPlanszyBackground.setFillColor(sf::Color(100, 100, 100));

	RozmiarPlanszyButtons = new ArrowButtons(sf::Vector2i(FeildPos.x + Backgrund_sep + Buttons_sep, FeildPos.y + 15));
}

void MenuGUI::init_IloscDoWygranejField(sf::Vector2f FeildPos)
{
	int Backgrund_sep = 340;
	int Buttons_sep = 160;

	IloscWygranaText = new sf::Text("Ilosc do wygranej", Czcionka, 40);
	IloscWygranaText->setPosition(FeildPos + sf::Vector2f(0,10));
	IloscWygranaText->setFillColor(FontColor);

	IloscWygranaValue = new sf::Text("3", Czcionka, 30);
	IloscWygranaValue->setPosition(FeildPos + sf::Vector2f(Backgrund_sep + 10, 15));
	IloscWygranaValue->setFillColor(FontColor);

	IloscWygranaBackground.setOutlineColor(BackGroundColor);
	IloscWygranaBackground.setOutlineThickness(3);
	IloscWygranaBackground.setPosition(FeildPos.x + Backgrund_sep, FeildPos.y + 8);
	IloscWygranaBackground.setSize(sf::Vector2f(110, 60));
	IloscWygranaBackground.setFillColor(sf::Color(100, 100, 100));

	IloscWygranejButtons = new ArrowButtons(sf::Vector2i(FeildPos.x + Backgrund_sep + Buttons_sep, FeildPos.y + 15));
}

void MenuGUI::init_WyborZnakuField(sf::Vector2f FeildPos)
{
	ZnakFieldPos = FeildPos;
	znakTxt.loadFromFile("resources/Znak.png");
	znakTxt.setSmooth(true);
	znak.setTexture(znakTxt);
	znak.setTextureRect(sf::IntRect(160, 0, 160, 160));
	znak.setScale(0.4, 0.4);

	WyborBackground.setSize(sf::Vector2f(110, 60));
	WyborBackground.setOutlineColor(BackGroundColor);
	WyborBackground.setOutlineThickness(3);
	WyborBackground.setFillColor(sf::Color(100, 100, 100));

	WyborZnakuGraczText = new sf::Text("Gracz", Czcionka, 40);
	WyborZnakuGraczText->setPosition(FeildPos + sf::Vector2f(0, 5));
	WyborZnakuGraczText->setFillColor(FontColor);

	WyborZnakuCpuText = new sf::Text("Komputer", Czcionka, 40);
	WyborZnakuCpuText->setPosition(FeildPos + sf::Vector2f(0, 80));
	WyborZnakuCpuText->setFillColor(FontColor);

	GraczButton = new Button(sf::Vector2i(FeildPos.x + 500, FeildPos.y + 8));
	CpuButton = new Button(sf::Vector2i(FeildPos.x + 500, FeildPos.y + 8 + 80));
}

void MenuGUI::updateValueTexts()
{
	std::stringstream PlanszaSize_txt;
	PlanszaSize_txt << gameSettings->PlanszaSize << 'x' << gameSettings->PlanszaSize;
	RozpmiarPlanszyValue->setString(PlanszaSize_txt.str());

	std::stringstream IloscDoWygranej_txt;
	IloscDoWygranej_txt << gameSettings->IloscDoWygranej;
	IloscWygranaValue->setString(IloscDoWygranej_txt.str());
}

MenuGUI::MenuGUI(GameSettings* gameSettings)
	:gameSettings(gameSettings)
{
	m_Rozpocznij = false;

	Czcionka.loadFromFile("resources/calibril.ttf");
	FontColor = sf::Color::White;
	BackGroundColor = sf::Color(100, 95, 244);

	Tlo.setSize(sf::Vector2f(1000, 1000));
	Tlo.setFillColor(sf::Color(110, 110, 110,230));
	init_RozmiarPlanszyField(sf::Vector2f(110, 90));
	init_IloscDoWygranejField(sf::Vector2f(110, 170));
	init_WyborZnakuField(sf::Vector2f(110, 260));
	updateValueTexts();

	RozpocznijButton = new Button(sf::Vector2i(50, 430));
	RozpocznijButton->setTexture("resources/RozpocznijButton.png");
}

void MenuGUI::render(sf::RenderTarget& okno)
{
	okno.draw(Tlo);

	okno.draw(*RozmiarPlanszyText);
	RozmiarPlanszyButtons->render(okno);
	okno.draw(RozmiarPlanszyBackground);
	okno.draw(*RozpmiarPlanszyValue);

	okno.draw(*IloscWygranaText);
	IloscWygranejButtons->render(okno);
	okno.draw(IloscWygranaBackground);
	okno.draw(*IloscWygranaValue);

	renderZnakField(okno);
	RozpocznijButton->render(okno);
}

void MenuGUI::update(sf::Vector2i MousePos)
{
	RozpocznijButton->update(MousePos);
	GraczButton->update(MousePos);
	CpuButton->update(MousePos);
	RozmiarPlanszyButtons->update(MousePos);
	IloscWygranejButtons->update(MousePos);

	if (RozmiarPlanszyButtons->isLeftPressed())
	{
		if (gameSettings->PlanszaSize < 4) return;
		gameSettings->PlanszaSize--;
		if (gameSettings->IloscDoWygranej > gameSettings->PlanszaSize) gameSettings->IloscDoWygranej = gameSettings->PlanszaSize;
		updateValueTexts();
	}
	else if (RozmiarPlanszyButtons->isRightPressed())
	{
		if (gameSettings->PlanszaSize > 19) return;
		gameSettings->PlanszaSize++;
		updateValueTexts();
	}
	if (IloscWygranejButtons->isLeftPressed())
	{
		if (gameSettings->IloscDoWygranej < 4) return;
		gameSettings->IloscDoWygranej--;
		updateValueTexts();
	}
	else if (IloscWygranejButtons->isRightPressed())
	{
		if (gameSettings->IloscDoWygranej >= gameSettings->PlanszaSize) return;
		gameSettings->IloscDoWygranej++;
		updateValueTexts();
	}

	if (GraczButton->isPressed() || CpuButton->isPressed())
	{
		if (gameSettings->ZnakGracz1 == Cell::KRZYZYK) gameSettings->ZnakGracz1 = Cell::KOLKO;
		else gameSettings->ZnakGracz1 = Cell::KRZYZYK;
	}
	
	if (RozpocznijButton->isPressed())
	{
		m_Rozpocznij = true;
	}
}

bool MenuGUI::isReadyToSatart()
{
	return m_Rozpocznij;
}


