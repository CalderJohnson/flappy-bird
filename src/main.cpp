#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <random>
#include "include/player.hpp"
#include "include/pipe.hpp"

//detect a collision between a player and a pipe
bool detectCollision(Player &player, Pipe &pipe)
{
    if(player.getPosition().x + 40 >= pipe.getPositionBottom().x && player.getPosition().x <= pipe.getPositionBottom().x + 50)
    {
        if(player.getPosition().y + 40 >= pipe.getPositionBottom().y)
        {
            return true;
        }
    }
    if(player.getPosition().x + 40 >= pipe.getPositionTop().x && player.getPosition().x <= pipe.getPositionTop().x + 50)
    {
        if(player.getPosition().y + 40 <= pipe.getPositionTop().y)
        {
            return true;
        }
    }
    return false;
}

int main() 
{
    //initialize trackers and seed random number generator
    srand(time(NULL));
	sf::Clock clock;

    //initialize window and background
    sf::RenderWindow window(sf::VideoMode(900, 504), "Flappy Bird!", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("./src/assets/background.png");
    sf::Sprite background(backgroundTexture);

    //initialize audio
    sf::Music music;
    music.openFromFile("./src/assets/music.wav");
    music.setLoop(true);
    music.play();

    sf::Sound deathSound;
    sf::SoundBuffer deathSoundBuffer;
    deathSoundBuffer.loadFromFile("./src/assets/death.wav");
    deathSound.setBuffer(deathSoundBuffer);

    //initialize player
    Player player;

    //initialize pipes
    Pipe pipes[4] = { Pipe(rand()%300), Pipe(rand()%300), Pipe(rand()%300), Pipe(rand()%300)};
    int pipeCount = 0;

    //main game loop
    while(window.isOpen()) 
    {
        //handle events and draw bg
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }
        window.draw(background);

        //update score
        if (clock.getElapsedTime().asSeconds() > 2)
		{
            if(pipeCount < 4)
            {
                pipeCount++;
            }
			clock.restart();
		}

        //update player
        player.draw(window);
        player.update();

        //update pipes
        for(int i = 0; i < pipeCount; ++i)
        {
            pipes[i].draw(window);
            pipes[i].update();
            if(detectCollision(player, pipes[i]))
            {
                deathSound.play();
                window.close();
            }
        }

        //update window
        window.display();
        window.clear();
    }
}