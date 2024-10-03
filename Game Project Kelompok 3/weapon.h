#pragma once
#include <SFML/Graphics.hpp>
#include "animasi.h"

class Weapon{
	public:
		Weapon(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
		
		void SetPos(sf::Vector2f);
		void Draw(sf::RenderWindow& window);
		void Kiri(float deltaTime);
		void Kanan(float deltaTime2);
    	sf::RectangleShape wpn1;
    	sf::RectangleShape wpn2;
		~Weapon();
		
	private :
		Animation animation;
		unsigned int row;
		float speed;
		int i;
		bool faceRight;
		
};
