#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

//flappy bird!
class Player 
{
public:
    Player();
    void draw(sf::RenderWindow &window);
    void update();
    sf::Vector2f getPosition();
private:
    int jumpIndex; //modelling jump speed
    bool falling; //for determining rotation
    sf::Sprite sprite; //for drawing
    sf::Texture texture;
    sf::RectangleShape hitbox;
    sf::SoundBuffer jumpSoundBuffer;
    sf::Sound jumpSound;
};