#pragma once
#include <SFML/Graphics.hpp> //INCLUDE SFML GRAPHICS
#include "animasi.h"  //ambil code dari animasi.h

class Enemy{
	//PUBLIC CLASS (DIGUNAKAN BESAMA)
	public:
		Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2u windowSize);
		~Enemy();
		
		void Kiri(float wAwan);
		void Kanan(float wAwan);
		void SetPos(sf::Vector2f);
		void Draw(sf::RenderWindow& window);
	
		int HP;
    	int HPMax;
    	sf::RectangleShape enemy1;
		sf::RectangleShape enemy2;
		unsigned int row;
		
	//PRIVATE CLASS (DIGUNAKAN INDIVIDU)	
	private :	
		Animation animation;
		float speed;
		int i;
		bool faceRight;
};
