#include "ArrowButtons.h"
#include "MouseDriver.h"

ArrowButtons::ArrowButtons(sf::Vector2i ButtonsPos = sf::Vector2i(0, 0))
{
	ButtonSeperation = 5;
	ArrowButtonTexture.loadFromFile("resources/ArrowTexture.png");
	TileSize = ArrowButtonTexture.getSize().x / 3;

	m_isRightPressed = false;
	m_isLeftPressed = false;
	RightLastState = false;
	LeftLastState = false;

	RightArrow.setTexture(ArrowButtonTexture);
	RightArrow.setTextureRect(sf::IntRect(0, 0, TileSize, TileSize));
	LeftArrow.setTexture(ArrowButtonTexture);
	LeftArrow.setTextureRect(sf::IntRect(0, TileSize, TileSize, TileSize));

	setPos(ButtonsPos);
}

void ArrowButtons::setPos(sf::Vector2i ButtonsPos)
{
	this->ButtonsPos = ButtonsPos;
	LeftArrow.setPosition(ButtonsPos.x, ButtonsPos.y);
	RightArrow.setPosition(ButtonsPos.x + TileSize + ButtonSeperation, ButtonsPos.y);
}

void ArrowButtons::render(sf::RenderTarget& okno)
{
	okno.draw(LeftArrow);
	okno.draw(RightArrow);
}

void ArrowButtons::update(sf::Vector2i MousePos)
{
	m_isRightPressed = false;
	m_isLeftPressed = false;

	if (RightArrow.getGlobalBounds().contains(MousePos.x, MousePos.y))
	{
		RightArrow.setTextureRect(sf::IntRect(TileSize, 0, TileSize, TileSize));
		if (MouseDriver::isMouseLeftClicked()) {
			RightArrow.setTextureRect(sf::IntRect(2 * TileSize, 0, TileSize, TileSize));
			m_isRightPressed = true;
		}
	}
	else
	{
		RightArrow.setTextureRect(sf::IntRect(0, 0, TileSize, TileSize));
	}

	if (LeftArrow.getGlobalBounds().contains(MousePos.x, MousePos.y))
	{
		LeftArrow.setTextureRect(sf::IntRect(TileSize, TileSize, TileSize, TileSize));
		if (MouseDriver::isMouseLeftClicked()) {
			LeftArrow.setTextureRect(sf::IntRect(2 * TileSize, TileSize, TileSize, TileSize));
			m_isLeftPressed = true;
		}
	}
	else
	{
		LeftArrow.setTextureRect(sf::IntRect(0, TileSize, TileSize, TileSize));
	}

	bool m_RightTemp = m_isRightPressed;
	bool m_LeftTemp = m_isLeftPressed;
	if (RightLastState && m_isRightPressed) m_isRightPressed = false;
	if (LeftLastState && m_isLeftPressed) m_isLeftPressed = false;
	RightLastState = m_RightTemp;
	LeftLastState = m_LeftTemp;
}

bool ArrowButtons::isRightPressed()
{
	return m_isRightPressed;
}

bool ArrowButtons::isLeftPressed()
{
	return m_isLeftPressed;
}

Button::Button(sf::Vector2i ButtonsPos)
{
	if(!ButtonTxt.loadFromFile("resources/ButtonTexture.png"))
	{
		std::cout << "\nBark folderu resources!\nUruchum aplikacje w miejscu zawierajacym folder resources\n\n";
	}
	TileSizeY = ButtonTxt.getSize().y;
	TileSizeX = ButtonTxt.getSize().x / 3;

	Button_sprite.setTexture(ButtonTxt);
	Button_sprite.setTextureRect(sf::IntRect(0, 0, TileSizeX, TileSizeY));

	setPos(ButtonsPos);
}

void Button::setPos(sf::Vector2i ButtonsPos)
{
	this->ButtonPos = ButtonsPos;
	Button_sprite.setPosition(ButtonPos.x, ButtonPos.y);
}

void Button::render(sf::RenderTarget& okno)
{
	okno.draw(Button_sprite);
}

void Button::update(sf::Vector2i mousePos)
{
	m_isPressed = false;
	if (Button_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
	{
		Button_sprite.setTextureRect(sf::IntRect(TileSizeX, 0, TileSizeX, TileSizeY));
		if (MouseDriver::isMouseLeftClicked())
		{
			Button_sprite.setTextureRect(sf::IntRect(TileSizeX * 2, 0, TileSizeX, TileSizeY));
			m_isPressed = true;
		}
	}
	else
	{
		Button_sprite.setTextureRect(sf::IntRect(0, 0, TileSizeX, TileSizeY));
	}

	bool temp_isPressed = m_isPressed;
	if (LastState && m_isPressed) m_isPressed = false;
	LastState = temp_isPressed;
}

void Button::setTexture(std::string fileName)
{
	sf::Texture txt;
	txt.loadFromFile(fileName);
	ButtonTxt = txt;
	TileSizeX = txt.getSize().x / 3;
	TileSizeY = txt.getSize().y;
	update(sf::Vector2i(-100, -100));
}

bool Button::isPressed()
{
	return m_isPressed;
}
