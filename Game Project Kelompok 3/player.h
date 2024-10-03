#pragma once
#include <SFML/Graphics.hpp>
#include "animasi.h"
#include "weapon.h"

class Player{
	//PUBLIC CLASS (DIGUNAKAN BESAMA)
	public:
		Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
		~Player();
		
		void Update(float deltaTime);
		void Draw(sf::RenderWindow& Play);
		sf::Vector2f playerCenter;
		sf::RectangleShape body;
		int HP;
		int HPMax;
		bool faceRight;
		unsigned int row;
		
	//PRIVATE CLASS (DIGUNAKAN INDIVIDU)
	private :
		
		Animation animation;	
		float speed;	
};
