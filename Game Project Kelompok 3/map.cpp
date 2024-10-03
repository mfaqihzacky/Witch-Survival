#include "map.h" //ambil code dari map.h

Map::Map(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime) {
	this->speed = speed; 
	faceRight = true;

    this->awan1.setSize(sf::Vector2f(220.0f, 120.0f)); //set ukuran texture awan 1 sebesar (220.0f, 120.0f)
    awan1.setTexture(texture); //memuat texture awan 1
    this->awan2.setSize(sf::Vector2f(220.0f, 120.0f));//set ukuran texture awan 2 sebesar (220.0f, 120.0f)
    awan2.setTexture(texture); //memuat texture awan 2
}

Map::~Map() {
	
}

void Map::SetPos(sf::Vector2f position){ //fungsi set posisi
	this->awan1.setPosition(position.x, position.y); // set posisi awan1
	this->awan2.setPosition(position.x, position.y); //set posisi awan2
}

void Map::Kanan(float wAwan){ //fungsi awan yang spawn dari kanan map
	sf:: Vector2f movement_cloud (0.0f, 0.0f);//kecepatan gerakan awan1
	row = 0;
	faceRight = true;
	movement_cloud.x -= speed * wAwan;	
	animation.Update(row, wAwan, faceRight);
	awan1.setTextureRect(animation.uvRect); //memuat texture animasi awan1
	awan1.move(movement_cloud);
	
}
void Map::Kiri(float wAwan){ //fungsi awan yang spawn dari kiri map
	sf:: Vector2f movement_cloud (0.0f, 0.0f); //kecepatan gerakan awan2
	row = 2;
	faceRight = false;
	movement_cloud.x += speed * wAwan;	
	animation.Update(row, wAwan, faceRight);
	awan2.setTextureRect(animation.uvRect);//memuat texture animasi awan2
	awan2.move(movement_cloud);
	
}

void Map::Draw(sf::RenderWindow& window) { //fungsi draw
	window.draw(awan1);
	window.draw(awan2);
}



