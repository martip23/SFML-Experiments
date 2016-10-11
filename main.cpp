#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game v0.1");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered
        // since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseEntered)
                std::cout << "The mouse has entered the arena!" << std::endl;

            if (event.type == sf::Event::MouseLeft)
                std::cout << "The cowardly mouse has left!" << std:: endl;

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
                std::cout << "Window, ye will be missed" << std::endl;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout << "Mouse is being crushed!!" << std::endl;
            }
        }

        //Colors window the lovely color, black

        window.clear(sf::Color::Black);


        window.display();
    }
    return EXIT_SUCCESS;
}

