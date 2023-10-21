//
// Created by cryptic on 21/10/23.
//

#include <iostream>
#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(sf::RenderWindow* window):
    restartButton(sf::Vector2f(100, 50))
{
    this->window = nullptr;
    this->window = window;
    initText();
    initButton();
}

GameOverScreen::~GameOverScreen() {

}

void GameOverScreen::initText() {
    if(!this->font.loadFromFile("hypersuper/HyperSuperRegular.ttf"))
    {
        std::cout << "could not open font";
    }

    message.setFont(font);
    message.setPosition((window->getSize().x * 0.5) - restartButton.getSize().x , (window->getSize().y * 0.5) - restartButton.getSize().y);
    message.setCharacterSize(30);
    message.setFillColor(sf::Color::Red);
    message.setString("Game Over");

    restartMessage.setFont(font);
    restartMessage.setPosition((window->getSize().x * 0.5) - restartButton.getSize().x , (window->getSize().y * 0.5) - restartButton.getSize().y + 100.f);
    restartMessage.setCharacterSize(30);
    restartMessage.setFillColor(sf::Color::Red);
    restartMessage.setString("Restart");

}

void GameOverScreen::draw() {
    this->window->draw(restartButton);
    this->window->draw(message);
    this->window->draw(restartMessage);

}

void GameOverScreen::update(sf::Event* ev) {
    updateMousePos();
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(this->restartButton.getGlobalBounds().contains(this->mousePosView))
        {

        }
    }


}

void GameOverScreen::initButton() {
    restartButton.setPosition((window->getSize().x * 0.5) - restartButton.getSize().x , (window->getSize().y * 0.5) - restartButton.getSize().y + 100.f);
    restartButton.setFillColor(sf::Color::Transparent);
    restartButton.setOutlineColor(sf::Color::Red);
    restartButton.setOutlineThickness(5.f);
}

void GameOverScreen::updateMousePos() {
    this->mousePosWindow = sf::Mouse::getPosition();
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}
