#include <SFML/Graphics.hpp>
#include "units.h"
#include "heroMoves.h"
#include <fstream>
#include <vector>
#include <iostream>


using namespace std;
using namespace sf;



int main()
{
	RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", Style::Fullscreen);
	int counter1 = 0, counter2 = 0, counter3 = 0;
    string path = "S:/ClionProjects/kursuck/";
	Font font;
	font.loadFromFile(path + "19925.ttf");
	Text text1("", font, 20);
	text1.setString("Bring me he knifes:");
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text1.setPosition(100, 570);
	Text text2("", font, 20);
	text2.setString("Feed the horses:");
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(480, 570);
	Text text3("", font, 20);
	text3.setString("Deliver the documents:");
	text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text3.setPosition(850, 570);

	Player hero(path +"heroOrientations.png", 56, 4, 80, 86, 400, 400, 80, 80);
	texture grass(path + "grass.jpg", 0, 0, 1920, 1080, 0, 0, 1920, 1080);
	texture house1(path + "oneHouse.png", 0, 0, 308, 378, -8, 2, 360, 400);
	texture blacksmith(path +"hous1.png", 0, 0, 262, 317, 40, 30, 306, 370);
	texture fence(path + "fence.png", 0, 0, 144, 96, 144, 986, 144, 96);
	texture horseshouse(path + "horseshouse.png", 0, 0, 274, 364, 1600, 0, 320, 425);
	texture bighouse(path + "bighouse.png", 0, 0, 342, 274, 1100, 10, 399, 320);
	texture smoke(path +"smoke.png", 0, 0, 80, 104, 169, 40, 50, 84);

    const int WIDTH_MAP = 54;
    const int HEIGHT_MAP = 96;
    String TileMap[HEIGHT_MAP];
    char mar;
	ifstream file("map.txt");
	for(size_t i = 0; i < 54; ++i){
	    for(size_t j = 0; j < 96; ++j){
	        file >> mar;
	        TileMap[i][j] = mar;
	    }
	}

	int counterX = 0;
	int counterY = 0;
		bool a1 = 0;
		bool a2 = 0;
		bool a3 = 0;

	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds(); //дать прошедшее время в микросекундах
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) && ((char)TileMap[hero.map_y][hero.map_x - 1] != '0')) 
		{ 
			hero.sprite.move(-hero.speed, 0); 
			hero.sprite.setTextureRect(IntRect(8 + 156 * (int(time) % 2), 115, 44, 92)); 
			hero.x -= hero.speed; 
			counterX -= hero.speed;
			if(counterX == -20) { counterX = 0; --hero.map_x;}
		} 
		else if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) && ((char)TileMap[hero.map_y][hero.map_x + 1] != '0')) 
		{ 
			hero.sprite.move(hero.speed, 0); 
			hero.sprite.setTextureRect(IntRect(8 + 156 * (int(time) % 2), 223, 44, 92)); 
			hero.x += hero.speed; 
			counterX += hero.speed;
			if(counterX == 20){ counterX = 0; ++hero.map_x;}
		} 
		else if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))) && ((char)TileMap[hero.map_y - 1][hero.map_x] != '0')) 
		{ 
			hero.sprite.move(0, -hero.speed); 
			hero.sprite.setTextureRect(IntRect(5 + 156 * (int(time) % 2), 331, 50, 92)); 
			hero.y -= hero.speed; 
			counterY -= hero.speed;
			if(counterY == -20){counterY = 0; --hero.map_y;}
		} 
		else if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))) && ((char)TileMap[hero.map_y + 1][hero.map_x] != '0')) 
		{ 
			hero.sprite.move(0, hero.speed); 
			hero.sprite.setTextureRect(IntRect(5 + 156 * (int(time) % 2), 7, 50, 92)); 
			hero.y += hero.speed; 
			counterY += hero.speed;
			if(counterY == 20) { counterY = 0; ++hero.map_y;}
		}  
		if(hero.x < 320 && hero.x > 20 && hero.y == 360)
		{
		cout << "fkajfouahjofa" << endl;
			a1 = true;
		}
		bool h1 =(a1 && (hero.x > 68 && hero.x < 340) && hero.y == 620);
		if(h1)
		{
			++counter1;
			text1.setString("Bring me he knifes:" + to_string(counter1));
			a1 = 0;
		}
		if(hero.x < 1880 && hero.x > 1600 && hero.y > 240 && hero.y < 380)
		{
			a2 = true;
		}
		bool h2 =(a2 && (hero.x > 444 && hero.x < 712) && hero.y == 620);
		if(h2)
		{
			++counter2;
			text2.setString("Feed the hourses:" + to_string(counter2));
			a2 = 0;
		}
		if(hero.x < 1440 && hero.x > 1140 && hero.y == 260)
		{
			a3 = true;
		}
		bool h3 =(a3 && (hero.x > 820 && hero.x < 1090) && hero.y == 620);
		if(h3)
		{
			++counter3;
			text3.setString("Deliver the documents:" + to_string(counter3));
			a3 = 0;
		}
		window.clear();
		window.draw(grass.sprite);
		for(size_t i = 0; i < 17; ++i)
		{
			fence.sprite.setPosition(116 * i, 0);
			window.draw(fence.sprite); 
		}
		if(time > 1 && time < 2)
		{
			smoke.sprite.setTextureRect(IntRect(80, 0, 120, 104));
		}
		if(time > 2 && time < 3)
		{
			smoke.sprite.setTextureRect(IntRect(200, 0, 100, 104));
		}
		if(time > 3 && time < 4)
		{
			smoke.sprite.setTextureRect(IntRect(300, 0, 122, 104));
		}
		if(time > 4)
		{
			smoke.sprite.setTextureRect(IntRect(422, 0, 110, 104));
			clock.restart();
		}
		window.draw(horseshouse.sprite); 
		window.draw(blacksmith.sprite); 
		window.draw(smoke.sprite);
		window.draw(bighouse.sprite);
		window.draw(hero.sprite);

		for(size_t i = 0; i < 3; ++i)
		{
			house1.sprite.setPosition(50 + 370 * i, 600);
			window.draw(house1.sprite);
		}
		for(size_t i = 0; i < 17; ++i)
		{
			fence.sprite.setPosition(116 * i, 986);
			window.draw(fence.sprite); 
		}
		cout << hero.x << ' ' << hero.y << endl;
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.display(); 
	}
	return 0;
}