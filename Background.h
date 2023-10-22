//
// Created by cryptic on 22/10/23.
//

#ifndef SPACE_SHOOTER_BACKGROUND_H
#define SPACE_SHOOTER_BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background {
public:
    Background();
    ~Background();

    void update();
    void draw(sf::RenderWindow* window);

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundImage;
    sf::Vector2f backgroundPosition1;
    sf::Vector2f  backgroundPosition2;

    void initBackground();

};


#endif //SPACE_SHOOTER_BACKGROUND_H
