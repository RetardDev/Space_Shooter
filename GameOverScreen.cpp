//
// Created by cryptic on 21/10/23.
//

#include <iostream>
#include "GameOverScreen.h"


GameOverScreen::GameOverScreen(sf::RenderWindow* window, GameState &gameState, Player& player):
    restartButton(sf::Vector2f(120, 50))
{
    this->playerPtr = &player;
    gameStatePtr = &gameState;
    this->window = window;
    initText();
    initButton();
    this->clicked = false;
}

GameOverScreen::~GameOverScreen() {

}

void GameOverScreen::initText() {
    if(!this->font.loadFromFile("hypersuper/HyperSuperRegular.ttf"))
    {
        std::cout << "could not open font";
    }

    message.setFont(font);
    message.setPosition(window->getSize().x * 0.5 - restartButton.getSize().x , window->getSize().y * 0.5 - restartButton.getSize().y);
    message.setCharacterSize(30);
    message.setFillColor(sf::Color::Red);
    message.setString("Game Over");

    restartMessage.setFont(font);
    restartMessage.setPosition(window->getSize().x * 0.5 - restartButton.getSize().x , window->getSize().y * 0.5 - restartButton.getSize().y + 100.f);
    restartMessage.setCharacterSize(30);
    restartMessage.setFillColor(sf::Color::Red);
    restartMessage.setString("  Restart ");

}

void GameOverScreen::draw() {
    this->window->draw(restartButton);
    this->window->draw(message);
    this->window->draw(restartMessage);
}

bool GameOverScreen::update(sf::Event* ev){
    updateMousePos();
    if(!clicked) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << gameStatePtr << std::endl;
            if (this->restartButton.getGlobalBounds().contains(this->mousePosView)) {
                *this->gameStatePtr = GameState::Playing;
                this->playerPtr->resetStats();
                return true;
            }
        }
    }else{
        clicked = true;
    }

return false;
}

void GameOverScreen::initButton() {
    restartButton.setPosition((this->window->getSize().x * 0.5) - restartButton.getSize().x , (this->window->getSize().y * 0.5) - restartButton.getSize().y + 100.f);
    restartButton.setFillColor(sf::Color::Transparent);
    restartButton.setOutlineColor(sf::Color::Red);
    restartButton.setOutlineThickness(5.f);
}

void GameOverScreen::updateMousePos() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}
