#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

//pipe
class Pipe 
{
public:
    Pipe(int offset);
    void draw(sf::RenderWindow &window);
    void update();
    sf::Vector2f getPositionBottom();
    sf::Vector2f getPositionTop();
private:
    sf::RectangleShape topPipe;
    sf::RectangleShape bottomPipe;
};