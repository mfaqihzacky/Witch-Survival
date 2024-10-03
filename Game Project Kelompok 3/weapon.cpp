#include "weapon.h"
#include "player.h"

Weapon::Weapon(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime) {
	this->speed = speed;
	row = 0;
	
	this->wpn1.setSize(sf::Vector2f(43.0f, 43.0f));
    wpn1.setTexture(texture);
    
    this->wpn2.setSize(sf::Vector2f(43.0f, 43.0f));
    wpn2.setTexture(texture);
}

Weapon::~Weapon() {
	
}

void Weapon::SetPos(sf::Vector2f position){
	this->wpn1.setPosition(position.x, position.y);
	this->wpn2.setPosition(position.x, position.y);
}

void Weapon::Kiri(float deltaTime){
	faceRight=false;
	sf:: Vector2f movement_cloud (0.0f, 0.0f);
	movement_cloud.x -= speed * deltaTime;
	animation.Update(row, deltaTime, faceRight);
	wpn1.setTextureRect(animation.uvRect);
	wpn1.move(movement_cloud);	
}

void Weapon::Kanan(float deltaTime2){
	faceRight=true;
	sf:: Vector2f movement_cloud (0.0f, 0.0f);
	movement_cloud.x += speed * deltaTime2;
	animation.Update(row, deltaTime2, faceRight);
	wpn2.setTextureRect(animation.uvRect);
	wpn2.move(movement_cloud);	
}

void Weapon::Draw(sf::RenderWindow& window) {
	window.draw(wpn1);
	window.draw(wpn2);
}
