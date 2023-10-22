#include <iostream>
#include <SFML/Graphics.hpp>
#include "Obstacles.h"
#include "GameOverScreen.h"
#include "GameState.h"
#include "Background.h"


int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "first gui");
    sf::Event ev;


    GameState gameState = GameState::Playing;
    std::cout << &gameState << std::endl;
    Background background;
    Score score;
    Player player(score);
    Obstacles rock(score, player);
    GameOverScreen gameOverScreen(&window, gameState, player);


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

            background.draw(&window);
            background.update();
            rock.update();
            rock.draw(&window);
            player.draw(&window);
            player.update();

        if(player.getHealth() <= 0){
            gameState = GameState::GameOver;}

        }
        else if(gameState == GameState::GameOver)
        {
            gameOverScreen.draw();
            if(gameOverScreen.update(&ev))
            {
//                player.updateHealth(100);

            }

        }
        window.display();
    }

    return 0;
}
