#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "include/pipe.hpp"

//render pipe with a given offset
Pipe::Pipe(int offset) 
{
    int topPosition = 80 + offset;
    int bottomPosition = topPosition + 140;

    bottomPipe.setSize(sf::Vector2f(50, 300));
    bottomPipe.setFillColor(sf::Color::Green);
    bottomPipe.setPosition(sf::Vector2f(900, bottomPosition));

    topPipe.setSize(sf::Vector2f(50, topPosition));
    topPipe.setFillColor(sf::Color::Green);
    topPipe.setPosition(sf::Vector2f(900, 0));
}

//draw pipe to window
void Pipe::draw(sf::RenderWindow &window)
{
    window.draw(topPipe);
    window.draw(bottomPipe);
}

//move pipe along, reset if reaches the end
void Pipe::update() 
{
    topPipe.move(-2, 0);
    bottomPipe.move(-2, 0);
    if(topPipe.getPosition().x < -50)
    {
        topPipe.setPosition(sf::Vector2f(900, 0));
        bottomPipe.setPosition(sf::Vector2f(900, bottomPipe.getPosition().y));
    }
}

//returns the position of the top left corner of the bottom pipe
sf::Vector2f Pipe::getPositionBottom()
{
    return bottomPipe.getPosition();
}

//returns the position of the bottom left corner of the top pipe
sf::Vector2f Pipe::getPositionTop()
{
    return sf::Vector2f(topPipe.getPosition().x, topPipe.getPosition().y + topPipe.getSize().y);
}