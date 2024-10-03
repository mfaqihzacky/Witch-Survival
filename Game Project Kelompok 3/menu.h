#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#define Max_main_menu 3
class Menuu {
	//PUBLIC CLASS (DIGUNAKAN BESAMA)
	public:
		Menuu(float width, float height);
		void draw(sf::RenderWindow &window);
		void moveUp();
		void moveDown();
	
		int mainMenuPressed(){
			return mainMenuSelected;
		}
		~Menuu();
	
	//PRIVATE CLASS (DIGUNAKAN INDIVIDU)		
	private:
		int mainMenuSelected;
		sf::Font font;
		sf::Text mainMenu[Max_main_menu];
};

