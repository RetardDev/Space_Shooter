//
// Created by cryptic on 20/10/23.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    ~Player();

//    void renderText(sf::RenderWindow *window);
    void update();
    void draw(sf::RenderWindow *window);
    sf::Rect<float> playerBound();
    void updateHealth(int health);
    int getHealth() const;



private:
    sf::Sprite body;
    sf::Texture playerTexture;
//    sf::Font font;
//    sf::Text scoreText;
    sf::RectangleShape healthBar;
    sf::Texture healthTexture;

    sf::Vector2f healthOffset;
    int score;
    unsigned int health;

    void initPlayer();
    void updateHealthBar();

//    void initText();
//    void updateText();
//    void updateScore();

};


#endif //UNTITLED_PLAYER_H
