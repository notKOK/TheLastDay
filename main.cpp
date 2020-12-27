#include <SFML/Graphics.hpp>
//#include <view.h>
#include "map.h"
#include "menu.h"
#include <iostream>

using namespace std;
using namespace sf;

class Player
{
	public:
		Player(string path, int x1, int y1, int x2, int y2, int positionX, int positionY, double scaleX, double scaleY)
		{
			this->image.loadFromFile(path);
			this->texture_.loadFromImage(this->image);
			this->sprite.setTexture(this->texture_);
			this->sprite.setTextureRect(IntRect(x1, y1, x2, y2));
			this->sprite.setPosition(positionX, positionY);
			this->sprite.setScale(
					scaleX / this->sprite.getLocalBounds().width,
					scaleY / this->sprite.getLocalBounds().height);
			x = positionX;
			y = positionY;
			map_x = positionX / 25;
			map_y = positionY / 25;
		}
		Image image;
		Texture texture_;
		Sprite sprite;
		float speed = 1;
		float x, y;
		float map_x, map_y;
};

class texture
{
	public:
		texture(string path, int x1, int y1, int x2, int y2, int positionX, int positionY, double scaleX, double scaleY)
		{
			this->image.loadFromFile(path);
			this->texture_.loadFromImage(this->image);
			this->sprite.setTexture(this->texture_);
			this->sprite.setTextureRect(IntRect(x1, y1, x2, y2));
			this->sprite.setPosition(positionX, positionY);
			this->sprite.setScale(
					scaleX / this->sprite.getLocalBounds().width,
					scaleY / this->sprite.getLocalBounds().height);
		}
		Image image;
		Texture texture_;
		Sprite sprite;
};

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "The last day");
    menu(window);

    Image heroimage;
    heroimage.loadFromFile("S:/ClionProjects/kursuck/hero.png");
    Texture herotexture;
    herotexture.loadFromImage(heroimage);
    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(50,25);
    herosprite.setTextureRect(IntRect(0,192,96,96));
    Clock clock;
    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        std::cout<<time << std::endl;
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { herosprite.move(-0.1*time, 0); } //первая координата Х отрицательна =>идём влево
        if (Keyboard::isKeyPressed(Keyboard::Right)) { herosprite.move(0.1*time, 0); } //первая координата Х положительна =>идём вправо
        if (Keyboard::isKeyPressed(Keyboard::Up)) { herosprite.move(0, -0.1*time); } //вторая координата (У) отрицательна =>идём вверх (вспоминаем из предыдущих уроков почему именно вверх, а не вниз)
        if (Keyboard::isKeyPressed(Keyboard::Down)) { herosprite.move(0, 0.1*time); };
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            herosprite.setColor(Color::Red);
        }
        window.clear();
        window.draw(herosprite);
        window.display();
    }
    return 0;
/*	//sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    string path = "S:/ClionProjects/kursuck/";
	Player hero(path + "heroOrientations.png", 56, 4, 80, 86, 400, 400, 80, 80);
	texture grass(path + "grass.jpg", 0, 0, 1920, 1080, 0, 0, 1920, 1080);
	texture house(path + "oneHouse.png", 0, 0, 308, 372, -20, -15, 350, 350);

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

		{
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { hero.sprite.move(-hero.speed, 0); hero.sprite.setTextureRect(IntRect(8 + 156 * (int(time) % 2), 115, 44, 92)); hero.x -= hero.speed;}
		else if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) { hero.sprite.move(hero.speed, 0); hero.sprite.setTextureRect(IntRect(8 + 156 * (int(time) % 2), 223, 44, 92)); hero.x += hero.speed;}
		else if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) { hero.sprite.move(0, -hero.speed); hero.sprite.setTextureRect(IntRect(5 + 156 * (int(time) % 2), 331, 50, 92)); hero.y -= hero.speed;}
		else if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { hero.sprite.move(0, hero.speed); hero.sprite.setTextureRect(IntRect(5 + 156 * (int(time) % 2), 7, 50, 92)); hero.y += hero.speed;}
		else hero.sprite.setTextureRect(IntRect(80,4,56,86));
		}

		cout << hero.x << "                        " << hero.y << endl;

		window.clear(); // AND THISS
		window.draw(grass.sprite);
		window.draw(house.sprite); // AND THIS
		window.draw(hero.sprite); // AND THIS
		window.display(); // DONT TOUCH THIS
	}*/
	return 0;
}

