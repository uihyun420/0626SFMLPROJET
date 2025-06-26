#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputMgr.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        InputMgr::Clear();


        sf::Event event; 
        while (window.pollEvent(event))
        {
            

            if (event.type == sf::Event::Closed)
                window.close();


            InputMgr::UpdateEvent(event);
        }


        // update 구간

        InputMgr::Update(0.f); // 벡터 구현 전 0.f 





        if (InputMgr::GetKeyDown(sf::Keyboard::A))
        {
            std::cout << "Key Down: A" << std::endl;
        }
        if (InputMgr::GetKeyUp(sf::Keyboard::A))
        {
            std::cout << "Key Up: A" << std::endl;
        }
        if (InputMgr::GetKey(sf::Keyboard::A))
        {
            std::cout << "Key Held: A" << std::endl;
        }



        // Draw 구간
        window.clear();
        window.draw(shape);
        window.display();



    }

    return 0;
}