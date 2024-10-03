//library SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//library C++
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <time.h>
#include "map.h"
#include "menu.h"
#include "enemy.h"
#include "patch.h"
#include "player.h"
#include "weapon.h"

// intruksi untuk compiler
using namespace sf;
using namespace std;

int rand(int, int);

int main() {
	time_t t;
	srand((unsigned)time(&t));

	sf::RenderWindow window(sf::VideoMode(768, 404), "Witch Survival"); // gambar 2D dengan ukuran 768x404 pixels dengan judul "Hero Survival"
	Menuu menu(768, 404); //tampilan menu 2D dengan ukuran 768x404
	window.setFramerateLimit(60); //batas framerate diatur sebesar 60fps

	//FONT
	// mengatur font dalam game dimana kami menggunakan 3 font yaitu AlexandriaFLF.ttf , AlexandriaFLF-Bold.ttf , dan Minecraft.ttf
	sf::Font font1;
	font1.loadFromFile("AlexandriaFLF.ttf");
	sf::Font font2;
	font2.loadFromFile("AlexandriaFLF-Bold.ttf");
	sf::Font font3;
	font3.loadFromFile("Minecraft.ttf");

	//MUSIC
	//mengatur music dalam game dimana kami menggunakan 3 music yaitu ingamemusic.ogg , menumusic.ogg , dan anggotamusic.ogg
	sf::Music music1;
	music1.openFromFile("ingamemusic.ogg");
	sf::Music music2;
	music2.openFromFile("menumusic.ogg");
	sf::Music music3;
	music3.openFromFile("anggotamusic.ogg");

	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape witchsurvival;
	witchsurvival.setSize(sf::Vector2f(500,500));
	witchsurvival.setPosition(235,-160);
	Texture witchsurvivalTexture;
	witchsurvivalTexture.loadFromFile("witchsurvival.png");
	witchsurvival.setTexture(&witchsurvivalTexture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape kelompok3;
	kelompok3.setSize(sf::Vector2f(300,300));
	kelompok3.setPosition(230,-105);
	Texture kelompok3Texture;
	kelompok3Texture.loadFromFile("kelompok3.png");
	kelompok3.setTexture(&kelompok3Texture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape anggota;
	anggota.setSize(sf::Vector2f(250,250));
	anggota.setPosition(-30,50);
	Texture anggotaTexture;
	anggotaTexture.loadFromFile("Syafiq.png");
	anggota.setTexture(&anggotaTexture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape namaanggota;
	namaanggota.setSize(sf::Vector2f(250,250));
	namaanggota.setPosition(-30,215);
	Texture namaanggotaTexture;
	namaanggotaTexture.loadFromFile("namasyafiq.png");
	namaanggota.setTexture(&namaanggotaTexture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape anggota1;
	anggota1.setSize(sf::Vector2f(250,250));
	anggota1.setPosition(160,50);
	Texture anggota1Texture;
	anggota1Texture.loadFromFile("Zacky.png");
	anggota1.setTexture(&anggota1Texture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape namaanggota1;
	namaanggota1.setSize(sf::Vector2f(250,250));
	namaanggota1.setPosition(160,215);
	Texture namaanggota1Texture;
	namaanggota1Texture.loadFromFile("namazacky.png");
	namaanggota1.setTexture(&namaanggota1Texture);
	/////////////////////////GAMBAR///////////////////////////
	sf::RectangleShape anggota2;
	anggota2.setSize(sf::Vector2f(250,250));
	anggota2.setPosition(350,50);
	Texture anggota2Texture;
	anggota2Texture.loadFromFile("Abdan.png");
	anggota2.setTexture(&anggota2Texture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape namaanggota2;
	namaanggota2.setSize(sf::Vector2f(250,250));
	namaanggota2.setPosition(350,215);
	Texture namaanggota2Texture;
	namaanggota2Texture.loadFromFile("namaabdan.png");
	namaanggota2.setTexture(&namaanggota2Texture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape anggota3;
	anggota3.setSize(sf::Vector2f(250,250));
	anggota3.setPosition(550,50);
	Texture anggota3Texture;
	anggota3Texture.loadFromFile("Danish.png");
	anggota3.setTexture(&anggota3Texture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape namaanggota3;
	namaanggota3.setSize(sf::Vector2f(250,250));
	namaanggota3.setPosition(550,215);
	Texture namaanggota3Texture;
	namaanggota3Texture.loadFromFile("namadanish.png");
	namaanggota3.setTexture(&namaanggota3Texture);
	/////////////////////////GAMBAR////////////////////////////
	sf::RectangleShape bilekamat;
	bilekamat.setSize(sf::Vector2f(770, 404));
	bilekamat.setPosition(0, 0);
	sf::Texture bilekamatTexture;
	bilekamatTexture.loadFromFile("backgroundmenu.png");
	bilekamat.setTexture(&bilekamatTexture);
	/////////////////////////GAMBAR////////////////////////////
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("az1.png");
	sf::Sprite background(backgroundTexture);
	/////////////////////////GAMBAR////////////////////////////
	sf::Texture playerTexture;
	playerTexture.loadFromFile("siuuu.png");
	/////////////////////////GAMBAR////////////////////////////
	sf::Texture map1Texture;
	map1Texture.loadFromFile("awan1.png");
	sf::Texture map2Texture;
	map2Texture.loadFromFile("awan2.png");
	/////////////////////////GAMBAR////////////////////////////
	sf::Texture enemy1Texture;
	enemy1Texture.loadFromFile("rillenemy.png");
	sf::Texture enemy2Texture;
	enemy2Texture.loadFromFile("pengjahit2.png");
	sf::Texture weaponTexture;
	weaponTexture.loadFromFile("apiungu.png");

	//VECTOR	
	std::vector<Weapon> weapon_kanan;
	std::vector<Weapon> weapon_kiri;
	std::vector<Enemy> enemies_kiri;
	std::vector<Enemy> enemies_kanan;
	std::vector<Map> awan1;
	std::vector<Map> awan2;

	//ANIMASI
	Map map1(&map1Texture, sf::Vector2u(3, 1), 40.4f, 45.0f);
	Map map2(&map2Texture, sf::Vector2u(3, 1), 40.4f, 35.0f);
	Weapon wpn1(&weaponTexture, sf::Vector2u(1, 1), 40.4f, 100.0f);
	Weapon wpn2(&weaponTexture, sf::Vector2u(1, 1), 40.4f, 100.0f);
	Enemy enemy1(&enemy1Texture, sf::Vector2u(6, 8), 0.3f, 40.0f, window.getSize());
	Enemy enemy2(&enemy2Texture, sf::Vector2u(6, 8), 0.3f, 40.0f, window.getSize());
	Player plyr(&playerTexture, sf::Vector2u(6, 8), 0.4f, 100.0f);

	//SCORE TEXT
	sf::Text scoreText; //mengatur style SCORE TEXT
	scoreText.setFont(font2); //teks score text menggunakan font2 yaitu AlexandriaFLF-Bold.ttf
	scoreText.setCharacterSize(20); // ukuran dari score text sebesar 20
	scoreText.setFillColor(sf::Color::White); // dengan warna putih
	scoreText.setPosition(15.f, 90.f); // score text terletak pada posisi (110.f, 10.f)

	//GAME OVER TEXT
	sf::Text gameOverText;//mengatur style GAME OVER TEXT
	gameOverText.setFont(font3);// teks game over menggunakan font2 yaitu minecraft.ttf
	gameOverText.setCharacterSize(70);// ukuran dari teks GAME OVER sebesar 70
	gameOverText.setFillColor(sf::Color::White); // dengan warna putih
	gameOverText.setOutlineColor(sf::Color::White);// dan outline berwarna putih
	gameOverText.setOutlineThickness(0.5f);
	gameOverText.setPosition(170.f, 245);// score text terletak pada posisi (110.f, 10.f)
	gameOverText.setString("GAME OVER!");//mengatur style GAME OVER

	//HP PLAYER TEXT
	sf::Text hpText; //mengatur style HP PLAYER
	hpText.setFont(font2);//teks HP PLAYER menggunakan font2 yaitu AlexandriaFLF-Bold.ttf
	hpText.setCharacterSize(14); // ukuran dari HP PLAYER sebesar 14
	hpText.setFillColor(sf::Color::White); // teks berwarna putih
	
	//HP ENEMY TEXT
	sf::Text eHpText;//mengatur style HP ENEMY
	eHpText.setFont(font2);//teks HP ENEMY menggunakan font2 yaitu AlexandriaFLF-Bold.ttf
	eHpText.setCharacterSize(14);// ukuran dari HP ENEMY sebesar 14
	eHpText.setFillColor(sf::Color::White);// teks berwarna putih

	//CLOCK
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock timeCountClock;

	//TIPE DATA FLOAT
	float wAan = 0.0f;
	float t1awan, t2awan;
	float spawnCD1, spawnCD2;
	float deltaTime = 0.0f, timeCount = 0.0f, deltaTime2 = 0.0f;

	//TIPE DATA INT
	// line 210-215 digunakan untuk inisialisasi awan
	int xawan;
	int score = 0;
	int shootTimer1 = 20, shootTimer2 = 20;
	int enemySpawnTimer = 0, enemySpawnTimer2 = 0;
	int awanc1 = 100, kanan = 0, kiri = 0, awanc2 = 100;
	int zombieCount1 = 100, zIndex = 0, kIndex = 0, zombieCount2 = 100;

	music2.play();	//MUSIC
	music2.setLoop(true);//music looping

	//OPEN
	while (window.isOpen()) {	//posisi awal user saat membuka game
		
		deltaTime = clock.restart().asSeconds();
		deltaTime2 = clock2.restart().asSeconds();
		timeCount = timeCountClock.getElapsedTime().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) { // menghasilkan periwisata valid
			if (event.type == sf::Event::Closed) window.close();//dipicu saat user ingin menutup window
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					menu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					menu.moveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return) {

					RenderWindow Play(sf::VideoMode(768, 404), "Witch Survival");
					RenderWindow OPTIONS(sf::VideoMode(768, 404), "Kelompok 3");

					int x = menu.mainMenuPressed();
					if (x == 0) {
						music1.play();
						music1.setLoop(true);
						while (Play.isOpen()) {
							music2.stop();
							
							deltaTime = clock.restart().asSeconds();
							deltaTime2 = clock2.restart().asSeconds();
							timeCount = timeCountClock.getElapsedTime().asSeconds();
							
							Event aevent;
							while (Play.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									music1.stop();
									Play.close();
									music2.play();
									music1.setLoop(true);
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										music1.stop();
										Play.close();
										music2.play();
										music1.setLoop(true);
									}
								}
							}
							OPTIONS.close();
							
							//HP PLAYER > 0 
							if (plyr.HP > 0) {
								plyr.Update(deltaTime);
								hpText.setPosition(plyr.body.getPosition().x+35, plyr.body.getPosition().y-7 - hpText.getGlobalBounds().height);
								hpText.setString(patch::to_string(plyr.HP) + "/" + patch::to_string(plyr.HPMax));
													
								if (shootTimer2 < 1000) shootTimer2++;
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && shootTimer2 >= 1000) {
									wpn1.SetPos(plyr.playerCenter);
									weapon_kanan.push_back(wpn1);
									shootTimer2 = 0;
								}

								spawnCD1 -= deltaTime;
								spawnCD2 -= deltaTime;
								t1awan -= deltaTime;
								t2awan -= deltaTime;

								if (t1awan <= 0 && kanan <= awanc1) {
									xawan = rand(-40, 60);
									awan1.push_back(map1);
									awan1[kanan].SetPos(sf::Vector2f(800.0f, xawan));
									kanan++;
									t1awan = rand(10, 1);
								}

								if (t2awan <= 0 && kiri <= awanc2) {
									xawan = rand(-40, 70);
									awan2.push_back(map2);
									awan2[kiri].SetPos(sf::Vector2f(800.0f, xawan));
									kiri++;
									t2awan = rand(10, 2);
								}

								for (int i = 0; i < weapon_kanan.size(); i++) {
									if (weapon_kanan[i].wpn2.getPosition().x <= 0) weapon_kanan.erase(weapon_kanan.begin() + i);

									for (size_t k = 0; k < enemies_kanan.size(); k++) {
										if (weapon_kanan[i].wpn2.getGlobalBounds().intersects(enemies_kanan[k].enemy2.getGlobalBounds())) {
											if (enemies_kanan[k].HP <= 1) {
												score += enemies_kanan[k].HPMax;
												enemies_kanan.erase(enemies_kanan.begin() + k);
												enemies_kanan.push_back(enemy2);
												enemies_kanan[k].SetPos(sf::Vector2f(790.f, 255.5f));
												kIndex=0,spawnCD2=0;
											}
											else
												enemies_kanan[k].HP--; //ENEMY TAKE DAMAGE
												weapon_kanan.erase(weapon_kanan.begin() + i);
											break;
										}
									}
								}
								
								for (int i = 0; i < weapon_kiri.size(); i++) {
									if (weapon_kiri[i].wpn1.getPosition().x <= 0) weapon_kiri.erase(weapon_kiri.begin() + i);
									for (size_t j = 0; j < enemies_kiri.size(); j++) {
										if (weapon_kiri[i].wpn1.getGlobalBounds().intersects(enemies_kiri[j].enemy1.getGlobalBounds())) {
											if (enemies_kiri[j].HP <= 1) {
												score += enemies_kiri[j].HPMax;
												enemies_kiri.erase(enemies_kanan.begin() + j);
												enemies_kiri.push_back(enemy1);
												enemies_kiri[j].SetPos(sf::Vector2f(-160.f, 260.0f));
												zIndex=0,spawnCD1=0;
											}
											else
												enemies_kiri[j].HP--; //ENEMY TAKE DAMAGE
												weapon_kiri.erase(weapon_kiri.begin() + i);
											break;
										}
									}		
								}
							
								if (spawnCD2 <= 0 && kIndex <= zombieCount2) {
									enemies_kanan.push_back(enemy2);
									enemies_kanan[kIndex].SetPos(sf::Vector2f(790.f, 255.5f));
									kIndex++;
									zombieCount2 = 0;
									spawnCD2 = rand(14,2);
								}
	
								for (int i = 0; i < enemies_kanan.size(); i++) {

									if (enemies_kanan[i].enemy2.getPosition().x <= 0 - enemies_kanan[i].enemy2.getGlobalBounds().width) {
										enemies_kanan.erase(enemies_kanan.begin() + i);
										break;
									}

									if (enemies_kanan[i].enemy2.getGlobalBounds().intersects(plyr.body.getGlobalBounds())) {
										enemies_kanan.erase(enemies_kanan.begin() + i);
										kIndex=0,spawnCD2=0;
										plyr.HP--; // PLAYER TAKE DAMAGE
										break;
									}
								}
								
								if (spawnCD1 <= 0 && zIndex <= zombieCount1) {
									enemies_kiri.push_back(enemy1);
									enemies_kiri[zIndex].SetPos(sf::Vector2f(-160.f, 260.0f));
									zIndex++;
									spawnCD1 = rand(12, 2);
								}
								
								//////////TERDAPAT KELEMAHAN KODE DI SINI, ENEMY COLLISIONNYA TIDAK BERFUNGSI
								/*for (int i = 0; i < enemies_kiri.size(); i++) {

									if (enemies_kiri[i].enemy1.getPosition().x <= 400 - enemies_kiri[i].enemy1.getGlobalBounds().width) {
										enemies_kiri.erase(enemies_kiri.begin() + i);
									break;
									}

									if (enemies_kanan[i].enemy1.getGlobalBounds().intersects(plyr.body.getGlobalBounds())) {
										enemies_kiri.erase(enemies_kiri.begin() + i);
										zIndex=0,spawnCD1=0;
										plyr.HP--; // PLAYER TAKE DAMAGE
									break;
									}
								}*/

								//MULAI ANIMASI
								for (int i = 0; i < enemies_kanan.size(); i++) enemies_kanan[i].Kanan(deltaTime);
								for (int i = 0; i < enemies_kiri.size(); i++) enemies_kiri[i].Kiri(deltaTime);
								for (int i = 0; i < weapon_kanan.size(); i++) weapon_kanan[i].Kanan(deltaTime2);
								for (int i = 0; i < weapon_kiri.size(); i++) weapon_kiri[i].Kiri(deltaTime);
								for (int i = 1; i < awan1.size(); i++) awan1[i].Kanan(deltaTime);
								for (int i = 0; i < awan2.size(); i++) awan2[i].Kanan(deltaTime);
							}

							enemy1.Kiri(deltaTime);
							enemy2.Kanan(deltaTime2);
							map1.Kanan(deltaTime);
							map2.Kiri(deltaTime);
							wpn1.Kiri(deltaTime);
							wpn2.Kanan(deltaTime);

							scoreText.setString("Score: " + patch::to_string(score));

							Play.clear();

							Play.draw(background);
							plyr.Draw(Play);
							for (int i = 0; i < enemies_kiri.size(); i++) {
								eHpText.setString(patch::to_string(enemies_kanan[i].HP) + "/" + patch::to_string(enemies_kiri[i].HPMax));
								eHpText.setPosition(enemies_kiri[i].enemy1.getPosition().x+45, enemies_kiri[i].enemy1.getPosition().y-7 - eHpText.getGlobalBounds().height);
								Play.draw(eHpText);
								enemies_kiri[i].Draw(Play);
							}
							for (int i = 0; i < enemies_kanan.size(); i++) {
								eHpText.setString(patch::to_string(enemies_kanan[i].HP) + "/" + patch::to_string(enemies_kanan[i].HPMax));
								eHpText.setPosition(enemies_kanan[i].enemy2.getPosition().x+45, enemies_kanan[i].enemy2.getPosition().y-4 - eHpText.getGlobalBounds().height);
								Play.draw(eHpText);
								enemies_kanan[i].Draw(Play);
							}
							for (int i = 0; i < awan1.size(); i++) awan1[i].Draw(Play);
							for (int i = 0; i < awan2.size(); i++) awan2[i].Draw(Play);
							for (int i = 1; i < weapon_kanan.size(); i++) weapon_kanan[i].Draw(Play);
							for (int i = 1; i < weapon_kiri.size(); i++) weapon_kiri[i].Draw(Play);

							Play.draw(scoreText);
							Play.draw(hpText);

							if (plyr.HP <= 0) {
								Play.draw(gameOverText);
							}
							Play.display();
						}
					}
					if (x == 1) {
						music3.play();
						while (OPTIONS.isOpen()) {
							music2.stop();
							Event aevent;
							while (OPTIONS.pollEvent(aevent)) {
								if (aevent.type == Event::Closed) {
									music3.stop();
									OPTIONS.close();
									music2.play();
									music2.setLoop(true);
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										music3.stop();
										OPTIONS.close();
										music2.play();
										music2.setLoop(true);
									}
								}
							}
							Play.close();
							OPTIONS.clear();
							OPTIONS.draw(kelompok3);
							OPTIONS.draw(anggota);
							OPTIONS.draw(namaanggota);
							OPTIONS.draw(anggota1);
							OPTIONS.draw(namaanggota1);
							OPTIONS.draw(anggota2);
							OPTIONS.draw(namaanggota2);
							OPTIONS.draw(anggota3);
							OPTIONS.draw(namaanggota3);
							OPTIONS.display();
						}
					}
					if (x == 2)	window.close();
				}
			}
		}
		window.clear();
		window.draw(bilekamat);
		window.draw(witchsurvival);
		menu.draw(window);
		window.display();
	}
	return 0;
}

int rand(int x, int y) {
	return x + (rand() % y);
}
