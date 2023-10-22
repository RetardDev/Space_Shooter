//
// Created by cryptic on 20/10/23.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <SFML/Graphics.hpp>
#include "Score.h"

class Player {
public:
    Player(Score& score);
    ~Player();

//    void renderText(sf::RenderWindow *window);
    void update();
    void draw(sf::RenderWindow *window);
    sf::Rect<float> playerBound();
    void updateHealth(int health);
    int getHealth() const;
    void resetStats();



private:
    sf::Sprite body;
    sf::Texture playerTexture;
//    sf::Font font;
//    sf::Text scoreText;
    sf::RectangleShape healthBar;
    //add outline here
    sf::Texture healthTexture;

    sf::Vector2f healthOffset;
    unsigned int health;

    Score& score;

    void initPlayer();
    void updateHealthBar();

//    void initText();
//    void updateText();
//    void updateScore();

};


#endif //UNTITLED_PLAYER_H
