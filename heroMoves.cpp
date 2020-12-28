#include <SFML/Graphics.hpp>
#include "units.h"
#include "heroMoves.h"

using namespace sf;


void move(float time_, Player hero, String* TileMap) {
    int counterY = 0;
    int counterX = 0;
    if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) && ((char)TileMap[hero.map_y][hero.map_x - 1] != '0'))
    {
        hero.sprite.move(-hero.speed, 0);
        hero.sprite.setTextureRect(IntRect(8 + 156 * (int(time_) % 2), 115, 44, 92));
        hero.x -= hero.speed;
        counterX -= hero.speed;
        if(counterX == -20) { counterX = 0; --hero.map_x;}
    }
    else if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))) && ((char)TileMap[hero.map_y][hero.map_x + 1] != '0'))
    {
        hero.sprite.move(hero.speed, 0);
        hero.sprite.setTextureRect(IntRect(8 + 156 * (int(time_) % 2), 223, 44, 92));
        hero.x += hero.speed;
        counterX += hero.speed;
        if(counterX == 20){ counterX = 0; ++hero.map_x;}
    }
    else if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))) && ((char)TileMap[hero.map_y - 1][hero.map_x] != '0'))
    {
        hero.sprite.move(0, -hero.speed);
        hero.sprite.setTextureRect(IntRect(5 + 156 * (int(time_) % 2), 331, 50, 92));
        hero.y -= hero.speed;
        counterY -= hero.speed;
        if(counterY == -20){counterY = 0; --hero.map_y;}
    }
    else if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))) && ((char)TileMap[hero.map_y + 1][hero.map_x] != '0'))
    {
        hero.sprite.move(0, hero.speed);
        hero.sprite.setTextureRect(IntRect(5 + 156 * (int(time_) % 2), 7, 50, 92));
        hero.y += hero.speed;
        counterY += hero.speed;
        if(counterY == 20) { counterY = 0; ++hero.map_y;}
    }
}
