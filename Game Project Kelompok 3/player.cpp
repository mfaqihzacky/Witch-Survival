#include "player.h" // mengambil code dari player.h
#include <vector> // library c++ vector

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime) {
	this->speed = speed;
	row = 0;
	faceRight = true;
	this->HPMax = 10; // hp yang tertera pada player adalah 10
	this->HP = this->HPMax;
	
	body.setSize(sf::Vector2f(110.0f, 70.0f)); // set size player sebesar (110.0f, 70.0f)
    body.setPosition(300.0f, 255.5f); //set player posisi pada (300.0f, 255.5f) 
    body.setTexture(texture); // memuat texture player
}

Player::~Player() {
	
}

void Player::Update(float deltaTime){
	sf:: Vector2f movement (0.0f, 0.0f); // kecepatan pergerakan player adalah (0.0f, 0.0f)
	//this->UpdateBorder(deltaTime);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
		// saat user menekan tombol A pada keyboard sama dengan menekan tombol panah kiri pada keyboard
		movement.x -= speed * deltaTime;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
		// saat user menekan tombol D pada keyboard sama dengan menekan tombol panah kanan pada keyboard
		movement.x += speed * deltaTime;
	}
		
	//set body position left and right
	if (body.getPosition().x >= 690) //Left
		body.setPosition(690.f, 255.5f);
	if (body.getPosition().x <= -30) //Right
		body.setPosition(-30.f, 255.5f);
		
	playerCenter=sf::Vector2f(body.getPosition().x+80.f,body.getPosition().y+10.f);	
		
	if (movement.x == 0.0f) { // kecepatan serangan dari player
		row = 1;
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::X))){ //tombol X pada keyboard digunakan untuk menyerang
			row = 7;
		}
	}
	else {
		row = 0 ;
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::X))||(movement.x == 0.0f)) { //tombol X pada keyboard digunakan untuk menyerang
			row = 7;
		}
		if (movement.x>= 0.0f) faceRight = true; 
		else faceRight = false;
	}
	
	animation.Update(row, deltaTime, faceRight); //update animasi
	body.setTextureRect(animation.uvRect); //set texture gerakan player
	body.move(movement); 
}

void Player::Draw(sf::RenderWindow& Play) { //fungsi draw
	Play.draw(body);
}



