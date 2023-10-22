//
// Created by cryptic on 21/10/23.
//

#include <iostream>
#include <sstream>
#include "Score.h"

Score::Score() {
    this->score = 0;
    this->initText();
}

Score::~Score() {

}

void Score::updateScore(int points) {
    score += points;
}

int Score::getScore() const{
    return this->score;
}

void Score::initText() {
    if(!this->font.loadFromFile("hypersuper/HyperSuperRegular.ttf"))
    {
        std::cerr << "Error opening font";
    }
    this->scoreText.setFont(font);

    scoreText.setString("Score: 0" );
}

void Score::displayScore(sf::RenderWindow *window) {
    std::stringstream ss;
    ss << this->score;
    std::string s;
    ss >> s;
    this->scoreText.setString("Score: "+ s);

    window->draw(this->scoreText);
}

void Score::resetScore() {
    this->score = 0;
}

