#pragma once					//DAPAT MENGURANGI WAKTU BUILD
#include <SFML/Graphics.hpp>	//INCLUDE SFML GRAPHICS
#include "animasi.h"			//AMBIL CODE DARI ANIMASI.H

//CLASS MAP IDENTIFIER
class Map{
	//PUBLIC CLASS (DIGUNAKAN BESAMA)
	public:
		Map(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
		~Map();
		void Kiri(float wAwan);					//FUNGSI AWAN 1
		void Kanan(float wAwan);				//FUNGSI AWAN 2
		void SetPos(sf::Vector2f);				//FUNGSI SETPOSISI
		void Update(float wAwan);				//FUNGSI UPDATE ANIMASI
		void Draw(sf::RenderWindow& window);	//FUNGSI DRAW
		sf::RectangleShape awan1;				//HITBOX
		sf::RectangleShape awan2;				//HITBOX
		
	//PRIVATE CLASS (DIGUNAKAN INDIVIDU)	
	private :
		//TIPE DATA
		Animation animation;
		unsigned int row;
		float speed;
		bool faceRight;
};
