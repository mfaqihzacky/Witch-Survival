#include "enemy.h"
#include<cstdlib>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2u windowSize) :
	animation(texture, imageCount, switchTime) {
	srand(time(NULL));
	this->speed = speed;
	row = 0;
	this->HPMax = rand() % 3 + 1;
	this->HP = this->HPMax;
	
	this->enemy1.setSize(sf::Vector2f(110.0f, 70.0f));
    enemy1.setTexture(texture);
   
    this->enemy2.setSize(sf::Vector2f(110.0f, 70.0f));
    enemy2.setTexture(texture);
}

Enemy::~Enemy() {
	
}

void Enemy::SetPos(sf::Vector2f position){
	this->enemy1.setPosition(position.x, position.y);
	this->enemy2.setPosition(position.x, position.y);
}

void Enemy::Kiri(float wAwan){
	sf:: Vector2f movement_enemy (0.0f, 0.0f);
	faceRight = true;
	movement_enemy.x += speed * wAwan;
	animation.Update(row, wAwan, faceRight);
	enemy1.setTextureRect(animation.uvRect);
	enemy1.move(movement_enemy);
	
}

void Enemy::Kanan(float wAwan){
	sf:: Vector2f movement_enemy (0.0f, 0.0f);
	faceRight = false;
	movement_enemy.x -= speed * wAwan;
	animation.Update(row, wAwan, faceRight);
	enemy2.setTextureRect(animation.uvRect);
	enemy2.move(movement_enemy);
	
}

void Enemy::Draw(sf::RenderWindow& window) {
            window.draw(enemy1);
            window.draw(enemy2);
}
