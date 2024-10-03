#include "menu.h"

Menuu::Menuu(float width, float height) {
	if (!font.loadFromFile("AlexandriaFLF-Bold.ttf")) {
	}
	
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Yellow);
	mainMenu[0].setOutlineColor(sf::Color::Black);
	mainMenu[0].setOutlineThickness(1.0f);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(40, 100);
	
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setOutlineColor(sf::Color::Black);
	mainMenu[1].setOutlineThickness(1.0f);
	mainMenu[1].setString("Anggota");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(40,170);
	
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setOutlineColor(sf::Color::Black);
	mainMenu[2].setOutlineThickness(1.0f);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(40, 240);
	
	mainMenuSelected = 0;
}

Menuu::~Menuu() {
	
}

void Menuu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}

void Menuu::moveDown() {
	if (mainMenuSelected + 1 <= Max_main_menu) {
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected++;
		if (mainMenuSelected == 3)	{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
	}
}

void Menuu::moveUp() {
	if (mainMenuSelected - 1 >= -1) {
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected--;
		if (mainMenuSelected == -1) {
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Yellow);
		
	}
}

