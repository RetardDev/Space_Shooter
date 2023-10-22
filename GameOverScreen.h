//
// Created by cryptic on 21/10/23.
//

#ifndef UNTITLED_GAMEOVERSCREEN_H
#define UNTITLED_GAMEOVERSCREEN_H
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Player.h"

class GameOverScreen {
public:
    GameOverScreen(sf::RenderWindow* window, GameState &gameState, Player& player);
    ~GameOverScreen();


    bool update(sf::Event* ev);
    void draw();

private:
    sf::Font font;
    sf::Text message;
    sf::RectangleShape restartButton;
    sf::Text restartMessage;

    sf::RenderWindow* window;

    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    GameState* gameStatePtr;

    Player* playerPtr;

    bool clicked;
    void updateMousePos();
    void initButton();
    void initText();

};


#endif //UNTITLED_GAMEOVERSCREEN_H
