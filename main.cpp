#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //Initialize variables
    int windowXSize     = 800;
    int windowYSize     = 600;
    float characterPosX    = 395;
    float characterPosY    = 295;
    float charScaleFactorX  = 5.0;
    float charScaleFactorY  = 5.0;
    int charSizeX           = 10;
    int charSizeY           = 13;
    int movementSpeed   = 1;
    
    //Create window
    sf::RenderWindow window(sf::VideoMode(windowXSize, windowYSize), "Game v0.3");
    sf::Clock clock; //Start clock for frame limiter

    //Load textures
    sf::Texture texture;
    if (!texture.loadFromFile("./Sprites/Sprites.png")){
        std::cout << "Could not load file" << std::endl;
    }

    sf::Texture bgTexture;
    if (!bgTexture.loadFromFile("./Textures/Overworld.png", sf::IntRect(0,100,50,50))){
        std::cout << "Could not load background texture" << std::endl;
    }

    //Set background using texture
    bgTexture.setRepeated(true);  //Set texture to repeat on background box
    sf::Sprite background;
    background.setTexture(bgTexture);
    background.setTextureRect(sf::IntRect(0,0,windowXSize,windowYSize));

    //Create character with texture
    sf::Sprite character;

    character.setTexture(texture);
    character.setTextureRect(sf::IntRect(19,19,charSizeX,charSizeY));
    character.setScale(sf::Vector2f(charScaleFactorX, charScaleFactorY));
                
    // run the program as long as the window is open
    while (window.isOpen())
    {
        //Draw character at certain position
        character.setPosition(sf::Vector2f(characterPosX, characterPosY));

        // check all the window's events that were triggered
        // since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
           /* if (event.type == sf::Event::MouseEntered)
                std::cout << "The mouse has entered the arena!" << std::endl;

            if (event.type == sf::Event::MouseLeft)
                std::cout << "The cowardly mouse has left!" << std:: endl;
            */
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
                std::cout << "Window, ye will be missed" << std::endl;
            }/*
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout << "Mouse is being crushed!!" << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }*/
        }

        // Use keyboard class for *smooth* keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if (characterPosX <= 0) {}

            else {characterPosX -= movementSpeed;}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if (characterPosX >= windowXSize - (charScaleFactorX * charSizeX)) {}
            else { characterPosX += movementSpeed; }
        }       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if (characterPosY >= windowYSize - (charScaleFactorY * charSizeY)){}
            else { characterPosY += movementSpeed; }
        }       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if (characterPosY <= 0) {}
            else {characterPosY -= movementSpeed;}
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            movementSpeed = 3;
        }
        else {movementSpeed = 1;}
        while (clock.getElapsedTime().asMilliseconds() < 10);

        clock.restart();

        //Colors window the lovely color, black
        window.draw(background);
        window.draw(character);

        window.display();
    }
    return EXIT_SUCCESS;
}

