#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Gra.h"
#include "Plansza.h"

int main() {
	Gra gra;
	gra.start();

	/*sf::RenderWindow* okno = new sf::RenderWindow(sf::VideoMode(500, 500), "Kolko i Krzyzyk", sf::Style::Default);
	sf::Event *evento = new sf::Event;

	while (okno->isOpen()) {
		while (okno->pollEvent(*evento)) {
			if (evento->type == sf::Event::Closed) {
				okno->close();
			}
		}
		okno->clear(sf::Color::Red);
		okno->display();
	}*/
}