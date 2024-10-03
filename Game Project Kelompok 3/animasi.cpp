#include "animasi.h" // ambil code dari animasi.h

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) { // memuat texture dan imagecount
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f; 
	currentImage.x = 0;
	
	//menampilkan pecahan dari tiap gambar
	uvRect.width = texture->getSize().x / float(imageCount.x);  
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation() {
	 
}

void Animation::Update(int row, float deltaTime, bool faceRight) { // fungsi update animasi
	currentImage.y = row;
	totalTime += deltaTime;  //time
	
	if (totalTime >= switchTime) {  
		totalTime -= switchTime;
		currentImage.x++; //waktu terus ditambah
		
		if (currentImage.x >= imageCount.x) { 
			currentImage.x = 0;
		}
	}
	
	uvRect.top =currentImage.y * uvRect.height;
	
	if (faceRight){ 
		uvRect.left =currentImage.x * uvRect.width; //pergantian setiap gambar/texture 
		uvRect.width = abs(uvRect.width);
	}	
	else {
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	
}

