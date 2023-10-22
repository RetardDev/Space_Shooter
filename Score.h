//
// Created by cryptic on 21/10/23.
//

#ifndef UNTITLED_SCORE_H
#define UNTITLED_SCORE_H


#include <SFML/Graphics.hpp>

class Score {
public:
    Score();
    ~Score();

    void resetScore();
    void updateScore(int points);
    int getScore() const;
    void displayScore(sf::RenderWindow *window);

private:
    sf::Font font;
    sf::Text scoreText;

    int score;
    void initText();





};


#endif //UNTITLED_SCORE_H
