//
// Created by cryptic on 20/10/23.
//

#include <iostream>
#include <sstream>
#include "Player.h"

Player::~Player() {

}

Player::Player():
    healthBar(sf::Vector2f(150.f, 10.f))
    {
    this->initPlayer();
//    this->initText();
}

void Player::initPlayer() {
    this->health = 100;
    this->score = 0;
    if(!this->playerTexture.loadFromFile("ship.png"))
    {
        std::cout << "could not open player texture";
    }

    this->playerTexture.setSmooth(true);

    this->body.setTexture(playerTexture);
    this->body.setScale(0.1f, 0.1f);

//    if(!this->healthTexture.loadFromFile("health.png"))
//    {
//        std::cout << "could not open health texture";
//    }
//    this->healthBar.setTexture(&healthTexture);
//    this->healthBar.setSize(sf::Vector2f(100.f, 100.f));
////    this->healthBar.setOrigin(this->healthBar.getSize().x / 0.5f, this->healthBar.getSize().y / 0.5f);
    this->healthBar.setPosition(620.f, 15.f);
    this->healthBar.setFillColor(sf::Color::Red);
    this->healthBar.setSize(sf::Vector2f(150.f * (this->health / 100.f), 10.f));

}

void Player::update() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        body.move(0.0f, -0.1f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        body.move(0.0f, 0.1f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        body.move(-0.1f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        body.move(0.1f, 0.f);
    }
    updateHealthBar();

}

void Player::draw(sf::RenderWindow *window) {
    window->draw(body);
    window->draw(healthBar);
}

//void Player::initText() {
//    if(!this->font.loadFromFile("hypersuper/HyperSuperRegular.ttf"))
//    {
//        std::cerr << "error opening font";
//    }
//    this->scoreText.setFont(font);
//
//    scoreText.setFillColor(sf::Color::White);
//
//
//}
//
//void Player::renderText(sf::RenderWindow *window) {
//    window->draw(this->scoreText);
//}

sf::Rect<float> Player::playerBound() {
    return this->body.getGlobalBounds();
}

void Player::updateHealthBar() {
    this->healthBar.setSize(sf::Vector2f(150.f * (this->health / 100.f), 10.f));
}

void Player::updateHealth(int health) {
    this->health += health;
}

int Player::getHealth() const {
    return this->health;
}


//void Player::updateText() {
//    std::stringstream ss;
//    ss << score;
//    std::string s;
//    ss >> s;
//
//    this->scoreText.setString("Score: "+ s);
//}
//
//void Player::updateScore() {
//
//}
