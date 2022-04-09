#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "include/player.hpp"

//render a new player
Player::Player()
{
    jumpIndex = 0;
    texture.loadFromFile("./src/assets/bird.png");
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(350, 250));
    hitbox.setSize(sf::Vector2f(40, 40));
    hitbox.setPosition(sf::Vector2f(350, 250));
    hitbox.setFillColor(sf::Color::Transparent);

    jumpSoundBuffer.loadFromFile("./src/assets/jump.wav");
    jumpSound.setBuffer(jumpSoundBuffer);
}

//draw player to window
void Player::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(hitbox);
}

//player controller
void Player::update()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        jumpSound.play();
        jumpIndex = 10;
    }
    if(hitbox.getPosition().y <= 0 || hitbox.getPosition().y >= 454) //prevent player from going offscreen
    {
        sprite.setRotation(0);
        if(hitbox.getPosition().y <= 0)
        {
            hitbox.setPosition(sf::Vector2f(hitbox.getPosition().x, 0));
        }
        else
        {
            hitbox.setPosition(sf::Vector2f(hitbox.getPosition().x, 454));
        }
    }
    if(jumpIndex > 0)
    {
        falling = false;
        if(!falling) //rotate up when jumping
        {
            sprite.setRotation(-20);
        }
        jumpIndex -= 1;
        hitbox.move(0, -jumpIndex);
    }
    else
    {
        if(!falling) //rotate back when falling
        {
            sprite.setRotation(20);
            falling = true;
        }
        hitbox.move(0, 4);
    }
    sprite.setPosition(hitbox.getPosition());
}

//returns the position of the top left corner of the hitbox
sf::Vector2f Player::getPosition()
{
    return hitbox.getPosition();
}