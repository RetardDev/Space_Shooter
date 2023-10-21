//
// Created by cryptic on 21/10/23.
//

#ifndef UNTITLED_GAMEOVERSCREEN_H
#define UNTITLED_GAMEOVERSCREEN_H
#include <SFML/Graphics.hpp>

class GameOverScreen {
public:
    GameOverScreen(sf::RenderWindow* window);
    ~GameOverScreen();


    void update(sf::Event* ev);
    void draw(sf::RenderWindow* window);

private:
    sf::Font font;
    sf::Text message;
    sf::RectangleShape restartButton;
    sf::Text restartMessage;

    void initButton(sf::RenderWindow* window);
    void initText(sf::RenderWindow* window);

};


#endif //UNTITLED_GAMEOVERSCREEN_H
