//
// Created by cryptic on 20/10/23.
//

#include <iostream>
#include "Obstacles.h"

Obstacles::Obstacles(Score& score, Player& player):
    score(score), player(player)
{
    this->rockTimer = 0.0f;
    this->rockTimerMax = 10000.0f;
    initRocks();
}

Obstacles::~Obstacles() {

}

void Obstacles::update() {
    bool touched = false;

    if(rockTimer >= rockTimerMax)
    {
        this->spawnRocks();
        rockTimer = 0.f;
    }else{
        rockTimer += 1.f;
    }

    for(int i = 0; i < this->rocks.size(); i++)
    {
        this->rocks[i].move(0.0f, 0.05f);
        if(rocks[i].getGlobalBounds().intersects(player.playerBound()) && !touched)
        {
            touched = true;
            this->rocks.erase(this->rocks.begin() + i);
            score.updateScore(-10);
            player.updateHealth(-10);
        }

        if(this->rocks[i].getPosition().y > 600 && rockTimerMax > 200.f)
        {
            this->rocks.erase(this->rocks.begin() + i);
            score.updateScore(1);
            this->rockTimerMax -= 500.f;
        }else{
            rockTimerMax = 2000.f;
        }
    }
}

void Obstacles::draw(sf::RenderWindow *window) {
    window->draw(rock);
    for(auto& r : this->rocks)
    {
        window->draw(r);
    }
    score.displayScore(window);
}

void Obstacles::initRocks() {
    if(!this->texture.loadFromFile("rock.png"))
    {
        std::cerr << "error";
    }

    this->rock.setPosition(0, -100.f);
    this->rock.setTexture(&texture);

    this->uvRect.width = this->texture.getSize().x / 2;
    this->uvRect.height = this->texture.getSize().y / 2;

    this->rock.setTextureRect(this->uvRect);
    this->rock.setSize(sf::Vector2f(50.f, 50.f));


}

void Obstacles::spawnRocks() {
    this->rock.setPosition(static_cast<float>(rand() % static_cast<int>(800 - rock.getSize().x)), -100.f);

    this->rock.setTexture(&texture);

    this->rocks.push_back(this->rock);

}

bool Obstacles::collisionDetection(std::vector<sf::RectangleShape> rocks) {



    return false;
}
