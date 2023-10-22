//
// Created by cryptic on 22/10/23.
//

#include <iostream>
#include "Background.h"

Background::Background():
    backgroundPosition1(0, 0), backgroundPosition2(backgroundTexture.getSize().x, 0)
{
    initBackground();
}

Background::~Background() {

}

void Background::initBackground() {
    if(!backgroundTexture.loadFromFile("background.jpg"))
    {
        std::cerr << "could not open background image";
    }
    backgroundImage.setPosition(0,0);
    backgroundImage.setTexture(backgroundTexture);


}

void Background::update() {
    backgroundPosition1.y -= 1.0f * 0.016f;
    backgroundPosition2.y -= 1.0f * 0.016f;
    std::cout << "y:" << backgroundPosition1.y << std::endl;
    std::cout << backgroundTexture.getSize().y << std::endl;
    if(backgroundPosition1.y <= -400)
    {
        backgroundPosition1.y = 400;
    }

    if(backgroundPosition2.y <= -100 )
    {
        backgroundPosition2.y = 600;
    }

}

void Background::draw(sf::RenderWindow *window) {
    window->draw(backgroundImage);

}
