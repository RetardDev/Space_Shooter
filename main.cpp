#include <iostream>
#include <SFML/Graphics.hpp>
#include "Obstacles.h"
#include "GameOverScreen.h"

enum class GameState{
    Main,
    Playing,
    GameOver
};


int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "first gui");
    sf::Event ev;

    GameState gameState  = GameState::Playing;

    Score score;
    Player player;
    Obstacles rock(score, player);
    GameOverScreen gameOverScreen(&window);


    while(window.isOpen())
    {
        while(window.pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();

        if(gameState == GameState::Playing) {

            rock.update();
            rock.draw(&window);
            player.draw(&window);
            player.update();

        if(player.getHealth() <= 0){ gameState = GameState::GameOver;}

        }
        else if(gameState == GameState::GameOver)
        {
            gameOverScreen.draw();
            gameOverScreen.update(&ev);
        }
        window.display();
    }

    return 0;
}
