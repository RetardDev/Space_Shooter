//
// Created by cryptic on 20/10/23.
//

#ifndef UNTITLED_OBSTACLES_H
#define UNTITLED_OBSTACLES_H
#include <SFML/Graphics.hpp>
#include "Score.h"
#include "Player.h"


class Obstacles {
public:
    Obstacles(Score& score, Player& player);
    ~Obstacles();

    void update();
    void draw(sf::RenderWindow *window);


private:
    sf::RectangleShape rock;
    std::vector<sf::RectangleShape> rocks;
    sf::IntRect uvRect;
    sf::Texture texture;

    Score& score;
    Player& player;

    float rockTimer;
    float rockTimerMax;

    void initRocks();
    void spawnRocks();
    bool collisionDetection(std::vector<sf::RectangleShape> rocks);
};


#endif //UNTITLED_OBSTACLES_H
