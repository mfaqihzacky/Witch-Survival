#pragma once
#include <SFML/Graphics.hpp>

class Animation{
	//PUBLIC CLASS (DIGUNAKAN BESAMA)
	public:
		Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
		~Animation();
		
		void Update(int row, float deltaTime, bool faceRight);
		sf::IntRect uvRect;
		
	//PRIVATE CLASS (DIGUNAKAN INDIVIDU)	
	private:
		sf::Vector2u imageCount;
		sf::Vector2u currentImage;
		
		float totalTime;
		float switchTime;	
};
