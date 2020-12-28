#include <SFML/Graphics.hpp>
#include "units.h"


using namespace sf;


Player::Player(string path, int x1, int y1, int x2, int y2, int positionX, int positionY, double scaleX, double scaleY)
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
    map_x = positionX / 20;
    map_y = positionY / 20;
		}


texture::texture(string path, int x1, int y1, int x2, int y2, int positionX, int positionY, double scaleX,
                 double scaleY) {
    this->image.loadFromFile(path);
    this->texture_.loadFromImage(this->image);
    this->sprite.setTexture(this->texture_);
    this->sprite.setTextureRect(IntRect(x1, y1, x2, y2));
    this->sprite.setPosition(positionX, positionY);
    this->sprite.setScale(
            scaleX/this->sprite.getLocalBounds().width,
            scaleY/this->sprite.getLocalBounds().height);
}