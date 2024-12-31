#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    std::cout << "Hello world!!" << std::endl;
    sf::Texture texture("C:\\Users\\Haison\\game\\hello-world\\src\\textures\\Monkey D Luffy.png", false, sf::IntRect({0, 0}, {35, 50}));
    Character character(texture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                // left key is pressed: move our character
                character.move(-1.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
            {
                // right key is pressed: move our character
                character.move(1.f); 
            }
        }

        window.clear();
        window.draw(character);
        window.display();
    }
}
 